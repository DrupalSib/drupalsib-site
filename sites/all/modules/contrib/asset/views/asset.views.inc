<?php
/**
 * @file
 * Views module integration.
 */

/**
 * Implements hook_views_handlers().
 */
function asset_views_handlers() {
  return array(
    'info' => array(
      'path' => ASSET_MODULE_PATH . '/views/handlers',
    ),
    'handlers' => array(
      'asset_views_handler_field_asset_link_edit' => array(
        'parent' => 'asset_views_handler_field_asset_link',
      ),
      'asset_views_handler_field_asset_link_delete' => array(
        'parent' => 'asset_views_handler_field_asset_link',
      ),
      'asset_views_handler_field_asset_link_insert' => array(
        'parent' => 'asset_views_handler_field_asset_link',
      ),
      'asset_views_handler_field_asset' => array(
        'parent' => 'views_handler_field',
      ),
      'asset_views_handler_argument_asset_aid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
    ),
  );
}

/**
 * Implements hook_views_plugins().
 */
function asset_views_plugins() {
  return array(
    'module' => 'asset',
    'row' => array(
      'asset' => array(
        'title' => t('Rendered asset'),
        'help' => t('Renders an asset in a specific view mode.'),
        'handler' => 'asset_views_plugin_row_asset_view',
        'uses fields' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
        'base' => array('asset'),
      ),
    ),
  );
}
