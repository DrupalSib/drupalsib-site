<?php
/**
 * @file
 * dssocial_core_feature_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function dssocial_core_feature_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => '0',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'assets_filter' => array(
        'weight' => '-47',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '-46',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '-42',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => '1',
    'status' => '1',
    'weight' => '10',
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '1',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
