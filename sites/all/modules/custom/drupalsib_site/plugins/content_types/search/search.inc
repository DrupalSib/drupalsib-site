<?php

$plugin = array(
  'title' => t('Search'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('Search block'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_search_content_type_theme'
);

function drupalsib_site_search_content_type_render($subtype, $conf, $panel_args) {
  $search =  drupal_get_form('search_block_form');
  $output = theme('drupalsib_site_search', array('search' => $search));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function drupalsib_site_search_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_search'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_search'
  );
}

function drupalsib_site_search_menus() {
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
    $menu_names[$menu] = isset($menus[$menu]) ? $menus[$menu] : t('Other menu: %menu', array('%menu' => $menu));
  }

  return $menu_names;
}