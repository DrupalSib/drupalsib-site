<?php

$plugin = array(
  'title' => t('Social vkontakte'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('Block social vkontakte'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_social_vkontakte_content_type_theme'
);

function drupalsib_site_social_vkontakte_content_type_render($subtype, $conf, $panel_args) {
  $output = theme('drupalsib_site_social_vkontakte');
  $block = new stdClass();
  $block->content = $output;
  return $block;
};

function drupalsib_site_social_vkontakte_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_social_vkontakte'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_social_vkontakte'
  );
}
