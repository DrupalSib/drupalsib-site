<?php

$plugin = array(
  'title' => t('Footer menu'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('footer_menu'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_footerlink_content_type_theme',
  'defaults' => array(
      'menu_left' => 'main-menu',
      'menu_center_left' => 'main-menu',
      'menu_center_right' => 'main-menu',
      'menu_right' => 'main-menu',
  ),
);

function drupalsib_site_footerlink_content_type_render($subtype, $conf, $panel_args) {
  global $base_url;
  
  $menu_list = drupalsib_site_footerlink_menus();
  
  $main_menu_tree = menu_tree($conf['menu_left']);
  $footer_menu = '<div class="ds_footer_cells"><div id="ds_footer_title"><h3>';
  $footer_menu .= $menu_list[$conf['menu_left']];
  $footer_menu .= '</h3></div><ul id="block-one">';
  foreach ($main_menu_tree as $mid => $key){    
    if (isset($key['#title'])){
      $footer_menu .= '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  $footer_menu .= '</ul></div>';
  
  $main_menu_tree = menu_tree($conf['menu_center_left']);
  $footer_menu .= '<div class="ds_footer_cells"><div id="ds_footer_title"><h3>';
  $footer_menu .= $menu_list[$conf['menu_center_left']];
  $footer_menu .= '</h3></div><ul id="block-two">';
  foreach ($main_menu_tree as $mid => $key){    
    if (isset($key['#title'])){
      $footer_menu .= '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  $footer_menu .= '</ul></div>';
  
  $main_menu_tree = menu_tree($conf['menu_center_right']);
  $footer_menu .= '<div class="ds_footer_cells"><div id="ds_footer_title"><h3>';
  $footer_menu .= $menu_list[$conf['menu_center_right']];
  $footer_menu .= '</h3></div><ul id="block-three">';
  foreach ($main_menu_tree as $mid => $key){    
    if (isset($key['#title'])){
      $footer_menu .= '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  $footer_menu .= '</ul></div>';
  
  $main_menu_tree = menu_tree($conf['menu_right']);
  $footer_menu .= '<div class="ds_footer_cells"><div id="ds_footer_title"><h3>';
  $footer_menu .= $menu_list[$conf['menu_right']];
  $footer_menu .= '</h3></div><ul id="block-four">';
  foreach ($main_menu_tree as $mid => $key){    
    if (isset($key['#title'])){
      $footer_menu .= '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  $footer_menu .= '</ul></div>';  
  
  $output = theme('drupalsib_site_footerlink', array('footer_menu' => $footer_menu));
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

/**
* Returns an edit form for the custom type.
*/
// The function name is MODULE_NAME_CT_NAME_content_type_edit_form
function drupalsib_site_footerlink_content_type_edit_form(&$form, &$form_state) {
// The current configuration
$conf = $form_state['conf'];

// This and the next one are normal FAPI form making.
$form['menu_left'] = array(
'#type' => 'select',
'#title' => t('Select menu left'),
'#options' => drupalsib_site_footerlink_menus(),
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['menu_left'],
);

$form['menu_center_left'] = array(
'#type' => 'select',
'#title' => t('Select menu center left'),
'#options' => drupalsib_site_footerlink_menus(),
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['menu_center_left'],
);

$form['menu_center_right'] = array(
'#type' => 'select',
'#title' => t('Select menu center right'),
'#options' => drupalsib_site_footerlink_menus(),
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['menu_center_right'],
);

$form['menu_right'] = array(
'#type' => 'select',
'#title' => t('Select menu right'),
'#options' => drupalsib_site_footerlink_menus(),
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['menu_right'],
);

return $form;
}

function drupalsib_site_footerlink_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function drupalsib_site_footerlink_menus() {
  return menu_get_menus();/*
  if (function_exists('menu_get_menus')) {
    // If the menu module is enabled, list custom menus.
    $menus = menu_get_menus();
  }
  else {
    // Otherwise, list only system menus.
    $menus = menu_list_system_menus();
  }

  // If the book module is enabled, also include book menus.
  if (function_exists('book_get_books')) {
    foreach (book_get_books() as $bid => $link) {
      $menus["book-toc-$bid"] = t('Book: %title', array('%title' => $link['title']));
    }
  }

  // menu_get_names() filters out empty menus, and adds any menus not found using the above calls (edge case).
  foreach (menu_get_names() as $menu) {
    $menu_names[$menu] = isset($menus[$menu]) ? $menus[$menu] : 'Other menu: ' . $menu;
  }

  return $menu_names;*/
}