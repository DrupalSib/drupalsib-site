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
  $menu_list = drupalsib_site_footer_small_menu_menus();
  
  $main_menu_tree = menu_tree_page_data($conf['selected_menu']);
  $footer_menu = array();
  foreach ($main_menu_tree as $id => $result) {
    if (!$result['link']['hidden']) {
      $footer_menu[$id]['title'] = $result['link']['link_title'];
      $footer_menu[$id]['url'] = $result['link']['link_path'];
      $footer_menu[$id]['active'] = $result['link']['in_active_trail'];
    }
  }
  $footer_menu_html = array();
  if (!empty($footer_menu)) {
    foreach ($footer_menu as $key){
        $footer_menu_html[] = l($key['title'], $key['url']);
    }
  }
  $output = theme('drupalsib_site_footer_small_menu', array('footer_menu' => $footer_menu_html));
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

function drupalsib_site_footer_small_menu_content_type_edit_form(&$form, &$form_state) {
$conf = $form_state['conf'];

$form['selected_menu'] = array(
'#type' => 'select',
'#title' => t('Select menu'),
'#options' => drupalsib_site_footer_small_menu_menus(),
'#description' => t('Chose the menu from the list'),
'#default_value' => $conf['selected_menu'],

);

return $form;
}

function drupalsib_site_footer_small_menu_content_type_edit_form_submit($form, &$form_state) {
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