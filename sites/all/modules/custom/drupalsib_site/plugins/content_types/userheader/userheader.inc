<?php

$plugin = array(
  'title' => t('userheader'),
  'single' => TRUE,
  'title' => t('userheader'),
  'icon' => 'icon_node.png',
  'description' => t('Drupalsib content types header'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_userheader_content_type_theme'
);

function drupalsib_site_userheader_content_type_render($subtype, $conf, $panel_args) {
  $site_slogan = variable_get('site_slogan', '');
  $output = theme('drupalsib_site_userheader', array('site_slogan' => $site_slogan));
  $block = new stdClass();
  $block->content = $output;
  return $block;
}

function drupalsib_site_userheader_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_userheader'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_userheader'
  );
}