<?php
/**
 * @file
 * Theme functions menu top.
 */

$plugin = array(
  'title' => t('Menu top'),
  'single' => TRUE,
  'icon' => 'dssocial_menu_top.png',
  'description' => t('Main menu'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_menu_top_content_type_theme',
);

/**
 * Implements hook_content_type_render().
 */
function dssocial_core_dssocial_menu_top_content_type_render($subtype, $conf, $panel_args) {
  $links = '';
  $menu = array();
  foreach (menu_tree_all_data('main-menu') as $info) {
    $menu[] = array('title' => $info['link']['title'], 'href' => $info['link']['href']);
  }
  
  for ($i = 0; $i < count($menu); $i++) {
     $classes = array();
    
     if ($menu[$i]['href'] == $_GET['q'] || ($menu[$i]['href'] == '<front>' && drupal_is_front_page())) {
       $classes[]='active_trail';  
     }
    if ($menu[$i]['href'] == '<front>') {
      $classes[] = 'homepage';
      $image = '<img src="/' . DRUPALSIB_SITE_THEME_PATH . '/images/pic-menu-hp.png" alt="homepage"/>';
      $item_link = l($image, $menu[$i]['href'], array('html' => TRUE));
    }
    else {
      if ($i == count($menu) - 1) {
        $classes[] = "last";
      }
      if (($node = menu_get_object('node', 1, $menu[$i]['href']))
          && (!empty($node->field_section_highlight['und'][0]['value']))) {
        $classes[] = 'orange';
      }
      $item_link = l($menu[$i]['title'], $menu[$i]['href']);
    }
    
     if (!empty($classes))  
         $links .= '<li class="' . implode(" ",$classes) . '">' . $item_link . '</li>';
     
     else  
         $links .= '<li>' . $item_link . '</li>';
     }
     

  if (!empty($links)) {
    $links = '<ul class="menu">' . $links . '</ul>';
     
  }
  else {
    $links = '';
  }

  // TODO.
  // Refactor.
  $links .= '<ul class="right-block"><li><a href="/rss"><img src="/' . DSSOCIAL_CORE_IMAGE_PATH . '/spacer.gif" class="rss" alt="RSS"></a></li></ul>';

  $block = new stdClass();
  $block->content = theme('dssocial_menu_top', array('links' => $links));
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function dssocial_core_dssocial_menu_top_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_menu_top'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-menu-top',
  );
}
