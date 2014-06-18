<?php
/**
 * @file
 * Theme functions menu footer top.
 */

$plugin = array(
  'title' => t('Menu footer top'),
  'single' => TRUE,
  'icon' => 'dssocial_menu_footer_top.png',
  'description' => t('Menu footer top'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_menu_footer_top_content_type_theme',
  'defaults' => array(
    'menu_main' => array(),
  ),
);

/**
 * Implements hook_content_type_render().
 */
function dssocial_core_dssocial_menu_footer_top_content_type_render($subtype, $conf, $panel_args) {
  if (empty($conf['menu_main'])) {
    return;
  }

  $footer_menu_title = $conf['override_title_text'];
  $menus = menu_tree_page_data($conf['menu_main']);
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
  if (empty($links)) {
    return;
  }
  $output = theme('dssocial_menu_footer_top', array('footer_menu_title' => $footer_menu_title, 'footer_menu_content' => $links));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function dssocial_core_dssocial_menu_footer_top_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_menu_footer_top'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-menu-footer-top',
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_menu_footer_top_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['menu_main'] = array(
    '#type' => 'select',
    '#title' => t('Select menu'),
    '#options' => menu_get_menus(),
    '#description' => t('Chose the menu from the list'),
    '#default_value' => !empty($conf['menu_main']) ? $conf['menu_main'] : '',
  );

  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function dssocial_core_dssocial_menu_footer_top_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
