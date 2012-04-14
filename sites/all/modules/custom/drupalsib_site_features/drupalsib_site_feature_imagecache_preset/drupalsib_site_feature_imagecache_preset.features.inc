<?php
/**
 * @file
 * drupalsib_site_feature_imagecache_preset.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function drupalsib_site_feature_imagecache_preset_image_default_styles() {
  $styles = array();

  // Exported image style: login_img
  $styles['login_img'] = array(
    'name' => 'login_img',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => '24',
          'height' => '24',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
