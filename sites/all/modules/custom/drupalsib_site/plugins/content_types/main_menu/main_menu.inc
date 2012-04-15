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
  $links = '';
  foreach (menu_tree('main-menu') as $key => $info) {
    if (!is_numeric($key)) {
      continue;
    }
    $item_link = NULL;
    if (!$info['original_link']['hidden']) {
      $class = NULL;
      if ($info['#href'] == '<front>') {
        $class = 'homepage';
        $image = '<img src="/' . DRUPALSIB_SITE_THEME_PATH . '/images/pic-menu-hp.png" alt="homepage"/>';
        $item_link = l($image, $info['#href'], array('html' => TRUE));
      }
      else {
        if (($node = menu_get_object('node', 1, $info['#href']))
            && (!empty($node->field_section_highlight['und'][0]['value']))) {
          $class = 'orange';
        }
        $item_link = l($info['#title'], $info['#href']);
      }
      $links .= '<li ' . ($class ? "class=\"$class\"" : '') . '>' . $item_link . '</li>';
    }
  }
  
  if ($links) {
    $links = '<ul class="menu">' . $links . '</ul>';
  } 
 
  $block = new stdClass();  
  $block->content = theme('drupalsib_site_main_menu', array('links' => $links));
  return $block;
}

function drupalsib_site_main_menu_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_main_menu'] = array(
    'path' => $plugin['path'],
    'template' => 'drupalsib_site_main_menu',
  );
}
