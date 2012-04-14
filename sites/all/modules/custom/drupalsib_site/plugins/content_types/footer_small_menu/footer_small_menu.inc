<?php

$plugin = array(
  'title' => t('footer_small_menu'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('footer_small_menu'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_footer_small_menu_content_type_theme',
  'defaults' => array(
      'selected_menu' => 'main-menu',
  ),
);

function drupalsib_site_footer_small_menu_content_type_render($subtype, $conf, $panel_args) {
  global $base_url;
//$search =  drupal_get_form('search_block_form');  
  $menu_list = drupalsib_site_footer_small_menu_menus();
  
  $main_menu_tree = menu_tree($conf['selected_menu']);//menu_tree_page_data('main-menu'); 
  foreach ($main_menu_tree as $mid => $key){
    if (isset($key['#title'])){
      $footer_menu[] = '<li>' . l($key['#title'], $key['#href']) . '</li>';
    }
  }
  
  $output = theme('drupalsib_site_footer_small_menu', array('footer_menu' => $footer_menu));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function drupalsib_site_footer_small_menu_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_footer_small_menu'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_footer_small_menu'
  );
}

/**
* Returns an edit form for the custom type.
*/
// The function name is MODULE_NAME_CT_NAME_content_type_edit_form
function drupalsib_site_footer_small_menu_content_type_edit_form(&$form, &$form_state) {
// The current configuration
$conf = $form_state['conf'];

// This and the next one are normal FAPI form making.
$form['selected_menu'] = array(
'#type' => 'select',
'#title' => t('Select menu'),
'#options' => drupalsib_site_footer_small_menu_menus(),//array(
    //0 => t('No'),
    //1 => t('Yes'),
//),/
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['selected_menu'],

);

return $form;
}

function drupalsib_site_footer_small_menu_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function drupalsib_site_footer_small_menu_menus() {
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

  return $menu_names;
}