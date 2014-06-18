<?php
/**
 * @file
 * Views module integration.
 */

/**
 * Implements hook_views_plugins().
 */
function asset_widget_views_plugins() {
  $plugins = array(
    'exposed_form' => array(
      'exposed_form_asset_widget' => array(
        'title' => t('Asset widget exposed form'),
        'help' => t('Specific exposed form for asset widget.'),
        'handler' => 'views_plugin_exposed_form_asset_widget',
        'uses options' => TRUE,
        'help topic' => 'exposed-form-basic',
        'path' => ASSET_WIDGET_MODULE_PATH . '/views/plugins',
      ),
    ),
  );

  return $plugins;
}
