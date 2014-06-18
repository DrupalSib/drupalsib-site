<?php
/**
 * @file
 * Assets widget administration pages logic.
 */

/**
 * Menu callback to get tab content by ID, or all enabled tabs if ID omitted.
 */
function asset_widget_get_tab_by_id($target_tab_id = FALSE) {
  $tabs_content = array();
  $response = array('#type' => 'ajax');

  // Render specified tab.
  if ($target_tab_id) {
    $info = asset_widget_get_tabs_info($target_tab_id);
    if ($info) {
      $output = asset_widget_get_rendered_tab_content($info, $_POST);
      if ($output) {
        $tabs_content['tabsContent'][$target_tab_id] = $output;
      }
    }
  }
  // Render all tabs content.
  else {
    $use_cookie_fallback = variable_get('asset_widget_save_last_search', FALSE);
    foreach (asset_widget_get_tabs_info() as $tab_id => $info) {
      $output = asset_widget_get_rendered_tab_content($info, $_POST, $use_cookie_fallback);
      if ($output) {
        $tabs_content['tabsContent'][$tab_id] = $output;
      }
    }
  }

  // We let our content callback add own specific commands.
  $response['#commands'] = asset_widget_get_current_commands();

  if (!empty($tabs_content['tabsContent'])) {

    $response['#commands'][] = array(
      'command' => 'assetWidgetInsertTabContent',
      'data' => $tabs_content['tabsContent'],
    );
  }

  // Set first tab as active on first load, or search results in case of cookie-stored search.
  if (!$target_tab_id && variable_get('asset_widget_save_last_search', FALSE) && !empty($_COOKIE['Drupal_asset_widget_filter_params'])) {
    $target_tab = 'results';
  }
  else {
    $target_tab = !$target_tab_id ? key($tabs_content['tabsContent']) : $target_tab_id;
  }

  $response['#commands'][] = array(
    'command' => 'assetWidgetGotoTab',
    'data' => $target_tab,
  );

  return $response;
}

/**
 * Menu callback to build label for dropped asset.
 */
function asset_widget_drop_get_label() {
  $response = array('#type' => 'ajax');

  $output = '';
  if (isset($_POST['aid']) && ($aid = $_POST['aid']) && ($asset = asset_load($aid))) {
    $label = entity_label('node', $asset);
    $output = "$label ($aid)";
  }

  $response['#commands'][] = array(
    'command' => 'assetWidgetDropToField',
    'data' => array(
      'label' => $output,
      'selector' => $_POST['selector_id'] ? $_POST['selector_id'] : '',
    ),
  );

  return $response;
}

/**
 * Render markup for widget tab.
 */
function asset_widget_get_rendered_tab_content($tab_info, $args, $use_cookie_fallback = FALSE) {
  $render_results = array();
  if (function_exists($tab_info['content_callback'])) {
    if (!empty($tab_info['arguments'])) {
      $actual_args = array();
      foreach ($tab_info['arguments'] as $arg) {
        if (isset($args[$arg])) {
          $actual_args[] = $args[$arg];
        }
        // If possible use COOKIE fallback i.e. for saved search.
        elseif ($use_cookie_fallback && !empty($_COOKIE['Drupal_asset_widget_' . $arg])) {
          $actual_args[] = $_COOKIE['Drupal_asset_widget_' . $arg];
        }
        elseif (isset($tab_info['defaults'])) {
          $actual_args[] = $tab_info['defaults'][$arg];
        }
      }
      $render_results = call_user_func_array($tab_info['content_callback'], $actual_args);
    }
    else {
      $render_results = call_user_func($tab_info['content_callback']);
    }
  }

  return render($render_results);
}
