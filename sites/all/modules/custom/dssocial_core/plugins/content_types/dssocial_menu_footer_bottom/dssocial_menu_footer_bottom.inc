<?php
/**
 * @file
 * Theme functions menu footer bottom.
 */

$plugin = array(
  'title' => t('Menu footer bottom'),
  'single' => TRUE,
  'icon' => 'dssocial_menu_footer_bottom.png',
  'description' => t('Menu footer bottom'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_menu_footer_bottom_content_type_theme',
  'defaults' => array(
    'menus_list' => array(),
  ),
);

/**
 * Implements hook_content_type_render().
 */
function dssocial_core_dssocial_menu_footer_bottom_content_type_render($subtype, $conf, $panel_args) {
  if (empty($conf['menus_list'])) {
    return;
  }

  $menus = menu_tree_all_data($conf['menus_list']);
  if (empty($menus)) {
    return;
  }

  $count = 1;
  $links = '';
  foreach ($menus as $menu) {
    if ($menu['link']['link_path'] != '<front>') {
      if ($count == count($menus)) {
        $class = "last";
      }
      $menu = l($menu['link']['link_title'], $menu['link']['link_path']);
      if (!empty($class)) {
        $links .= '<li class=' . $class . '>' . $menu . '</li>';
      }
      else {
        $links .= '<li>' . $menu . '</li>';
      }
      $count++;
    }
  }

  if ($links) {
    $links = '<div><ul>' . $links . '</ul></div>';
  }

  $block = new stdClass();
  $block->content = theme('dssocial_menu_footer_bottom', array('links' => $links));
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function dssocial_core_dssocial_menu_footer_bottom_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_menu_footer_bottom'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-menu-footer-bottom',
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_menu_footer_bottom_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $menus = db_select('menu_custom', 'mc')
    ->fields('mc', array('title', 'menu_name'))
    ->orderBy('mc.title')
    ->execute()
    ->fetchAllKeyed();

  if ($menus) {
    $form['menus_list'] = array(
      '#type'    => 'select',
      '#options' => array_flip($menus),
      '#default_value' => (isset($conf['menus_list'])) ? $conf['menus_list'] : '',
      '#title'   => t('Select menu to render'),
    );
  }

  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function dssocial_core_dssocial_menu_footer_bottom_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
