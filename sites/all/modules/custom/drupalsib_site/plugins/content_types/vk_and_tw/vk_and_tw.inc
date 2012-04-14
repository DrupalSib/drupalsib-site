<?php

$plugin = array(
  'title' => t('vk and tw'),
  'single' => TRUE,
  'icon' => 'icon_node.png',
  'description' => t('Block vk and tw group'),
  'category' => t('DrupalSib'),
  'hook theme' => 'drupalsib_site_vk_and_tw_content_type_theme'
);

function drupalsib_site_vk_and_tw_content_type_render($subtype, $conf, $panel_args) {
  $output = theme('drupalsib_site_vk_and_tw');
  $block = new stdClass();
  $block->content = $output;
  return $block;
};

function drupalsib_site_vk_and_tw_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_vk_and_tw'] = array(
      'path' => $plugin['path'],
      'template' => 'drupalsib_site_vk_and_tw'
  );
}
