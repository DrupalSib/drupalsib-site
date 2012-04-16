<?php

$plugin = array(
  'title' => t('Logobar'),
  'single' => TRUE,
  'icon' => 'icon_logobar.png',
  'description' => t('Drupalsib content types logobar'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_logobar_content_type_theme'
);

function drupalsib_site_logobar_content_type_render($subtype, $conf, $panel_args) {

  $site_logo = l('<img src="/' . DRUPALSIB_SITE_THEME_PATH . '/images/logo.png" alt="homepage"/>', "/", array('html' => TRUE));
  $site_slogan = '<span>' . variable_get('site_slogan', '') . '</span>';  
  $output = theme('drupalsib_site_logobar', array('site_logo' => $site_logo, 'site_slogan' => $site_slogan));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function drupalsib_site_logobar_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_logobar'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_logobar'
  );
}