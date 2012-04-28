<?php
/**
 * @file
 * drupalsib_site_feature_panels.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function drupalsib_site_feature_panels_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menu
  $menus['menu-menu'] = array(
    'menu_name' => 'menu-menu',
    'title' => 'Меню',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Меню');


  return $menus;
}
