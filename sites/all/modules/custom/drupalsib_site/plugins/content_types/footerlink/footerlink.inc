<?php

$plugin = array(
  'title' => t('Footer menu'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('footer_menu'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_footerlink_content_type_theme',
  'defaults' => array(
      'menu_main' => 'main-menu',
  ),
);

function drupalsib_site_footerlink_content_type_render($subtype, $conf, $panel_args) {
  global $base_url;
  
  $menu_list = menu_get_menus();
  
  $main_menu_tree = menu_tree($conf['menu_main']);
  
  $footer_menu_title = $menu_list[$conf['menu_main']];
  
  $footer_menu_content = '';
  
  foreach ($main_menu_tree as $mid => $key){    
    if (isset($key['#title'])){
      $footer_menu_content .= '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  
  $output = theme('drupalsib_site_footerlink', array('footer_menu_title' => $footer_menu_title, 'footer_menu_content' => $footer_menu_content));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function drupalsib_site_footerlink_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_footerlink'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_footerlink'
  );
}

function drupalsib_site_footerlink_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['menu_left'] = array(
    '#type' => 'select',
    '#title' => t('Select menu'),
    '#options' => menu_get_menus(),
    '#description' => t('Chose the menu from the list'),
    '#default_value' => $conf['menu_main'],
  );

  return $form;
}

function drupalsib_site_footerlink_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}