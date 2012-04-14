<?php

/**
 * @file
 * Plugin to handle the 'node' content type which allows individual nodes
 * to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Main_menu'),
  'single' => TRUE,
  'icon' => 'icon_main_menu.png',
  'description' => t('Add a main menu from your site as content.'),
  'category' => t('Drupalsib'),
  'hook theme' => 'drupalsib_site_main_menu_content_type_theme',
);

/**
 * Output function for the 'node' content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function drupalsib_site_main_menu_content_type_render($subtype, $conf, $panel_args) {
  $main_menu_tree = menu_tree_page_data('main-menu');

  $main_menu = array();
  
  $links = '<ul class="menu">';
  
  foreach ($main_menu_tree as $id => $result) {
    if (!$result['link']['hidden']) {
      $main_menu[$id]['title'] = $result['link']['link_title'];
      $main_menu[$id]['url'] = $result['link']['link_path'];
      $main_menu[$id]['active'] = $result['link']['in_active_trail'];
    }
  }
  $main_menu = array_values($main_menu);
  foreach ($main_menu as $key => $result) {
    if ($key == 0) {
      $home_link = l('<img src=/"' . DRUPALSIB_SITE_THEME_PATH . '/images/pic-menu-hp.png" alt="homepage"/>', $main_menu[$key]['url'], array('html' => TRUE));
      $links .= '<li class="homepage">' . $home_link . '</li>';
    } 
    else {
      $item_link = l(t($main_menu[$key]['title']), $main_menu[$key]['url'], array('html' => TRUE));
      $links .= '<li>' . $item_link . '</li>';
    }
  }
  
  $links .= '</ul>';

  $block->content = theme('drupalsib_site_main_menu', array('links' => $links));

  return $block;
}

function drupalsib_site_main_menu_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_main_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'drupalsib_site_main_menu',
  );
}
