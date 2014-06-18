<?php
/**
 * @file
 * Module related preprocesses and theme overrides.
 */

/**
 * Preprocess variables for asset_wrapper.tpl.php.
 * @see asset_wrapper.tpl.php
 */
function template_preprocess_asset_wrapper(&$vars) {
  $element = $vars['element'];
  $asset = $element['#entity'];
  $view_mode = $element['#view_mode'];
  $base = 'asset_wrapper';

  $classes_array = $vars['classes_array'];
  $classes_array[] = drupal_html_class('asset');
  $classes_array[] = drupal_html_class("aid-$asset->aid");
  $classes_array[] = drupal_html_class('asset-' . $element['#bundle']);

  if (isset($asset->in_editor) && $asset->in_editor) {
    $classes_array[] = drupal_html_class('editor');
    $base = 'asset_editor_wrapper';
    $vars['attributes_array']['contenteditable'] = 'false';
    $vars['attributes_array']['data-cke-editable'] = 'false';
  }

  $bundle = strtr($element['#bundle'], '-', '_');
  $vars['theme_hook_suggestions'][] = $base . '__' . $bundle;
  $vars['theme_hook_suggestions'][] = $base . '__' . $bundle . '__' . $view_mode;

  if ($view_mode !== ASSET_DEFAULT_MODE) {
    $options = !empty($asset->asset_options) && is_array($asset->asset_options) ? $asset->asset_options : array();
    if (!empty($options['align']) && in_array($options['align'], array('', 'left', 'right'), TRUE)) {
      $classes_array[] = drupal_html_class('asset-align-' . $options['align']);
    }
  }

  $vars['classes_array'] = $classes_array;
  $vars['attributes_array']['class'] = $classes_array;

  $vars['asset'] = $asset;
  $vars['content'] = $element['#children'];
  $vars['view_mode'] = $view_mode;
}
