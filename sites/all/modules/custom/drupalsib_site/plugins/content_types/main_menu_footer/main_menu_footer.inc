<?php

$plugin = array(
  'title' => t('Main_menu_footer'),
  'single' => TRUE,
  'icon' => 'icon_main_menu_footer.png',
  'description' => t('Add a main menu footer from your site as content.'),
  'category' => t('Drupalsib'),
  'hook theme' => 'drupalsib_site_main_menu_footer_content_type_theme',
);

function drupalsib_site_main_menu_footer_content_type_render($subtype, $conf, $panel_args) {
  $links = '';
  
  $menu = array ();
  
  foreach (menu_tree('main-menu') as $key => $info) {
    if (!is_numeric($key)) {
      continue;
    }
    if ($info['#href'] != '<front>') {
      $menu[] = array('title' => $info['#title'], 
          'href' => $info['#href']);
    }
  }
  
  for ($i=0; $i<count($menu); $i++) {
    $class = NULL;
    if ($i==count($menu)-1) {
      $class = "last";
    }
    $item_link = l($menu[$i]['title'], $menu[$i]['href']);
    $links .= '<li ' . ($class ? "class=\"$class\"" : '') . '>' . $item_link . '</li>';
  }
  
  if ($links) {
    $links = '<div><ul>' . $links . '</ul></div>';
  }
 
  $block = new stdClass();  
  $block->content = theme('drupalsib_site_main_menu_footer', array('links' => $links));
  return $block;
}

function drupalsib_site_main_menu_footer_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_main_menu_footer'] = array(
    'path' => $plugin['path'],
    'template' => 'drupalsib_site_main_menu_footer',
  );
}
