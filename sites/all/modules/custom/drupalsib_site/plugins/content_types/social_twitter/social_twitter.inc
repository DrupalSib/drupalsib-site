<?php

$plugin = array(
  'title' => t('Social twitter'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('Block social twitter'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_social_twitter_content_type_theme'
);

function drupalsib_site_social_twitter_content_type_render($subtype, $conf, $panel_args) {
  $output = theme('drupalsib_site_social_twitter');
  $block = new stdClass();
  $block->content = $output;
  return $block;
};

function drupalsib_site_social_twitter_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_social_twitter'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_social_twitter'
  );
}
