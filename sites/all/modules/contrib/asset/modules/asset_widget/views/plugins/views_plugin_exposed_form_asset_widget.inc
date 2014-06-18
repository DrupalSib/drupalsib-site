<?php
/**
 * @file
 * Definition of views_plugin_exposed_form_asset_widget.
 */

/**
 * Exposed form plugin that provides an specific exposed form for asset widget.
 *
 * @ingroup views_exposed_form_plugins
 */
class views_plugin_exposed_form_asset_widget extends views_plugin_exposed_form {
  function render_exposed_form($block = FALSE) {
    // Deal with any exposed filters we may have, before building.
    $form_state = array(
      'view' => &$this->view,
      'display' => &$this->display,
      'method' => 'get',
      'rerender' => TRUE,
      'no_redirect' => TRUE,
      'always_process' => TRUE,
    );

    // Some types of displays (eg. attachments) may wish to use the exposed
    // filters of their parent displays instead of showing an additional
    // exposed filter form for the attachment as well as that for the parent.
    if (!$this->view->display_handler->displays_exposed() || (!$block && $this->view->display_handler->get_option('exposed_block'))) {
      unset($form_state['rerender']);
    }

    if (!empty($this->ajax)) {
      $form_state['ajax'] = TRUE;
    }

    $form_state['exposed_form_plugin'] = $this;
    $form = drupal_build_form('views_exposed_form', $form_state);

    // Show exposed form only on live preview, or in when flag manually setted.
    if (!empty($this->view->render_exposed_form) || !empty($this->view->live_preview)) {
      // We add special class to get our form in JS.
      $form['#attributes']['class'][] = 'asset-widget-search-exposed-form';

      // Move all field descriptions to tooltips.
      foreach (element_children($form) as $child_key) {
        if (isset($form[$child_key]['#name']) && isset($form['#info']['filter-' . $form[$child_key]['#name']])) {
          if (!empty($form[$child_key]['#description'])) {
            $widget = &$form['#info']['filter-' . $form[$child_key]['#name']];
            if (empty($widget['description'])) {
              $widget['description'] = $form[$child_key]['#description'];
            }
            unset($form[$child_key]['#description']);
          }
        }
      }

      $output = drupal_render($form);

      if (!$this->view->display_handler->displays_exposed()
        || (!$block && $this->view->display_handler->get_option('exposed_block'))) {
        return "";
      }
      else {
        return $output;
      }
    }
    return "";
  }
}
