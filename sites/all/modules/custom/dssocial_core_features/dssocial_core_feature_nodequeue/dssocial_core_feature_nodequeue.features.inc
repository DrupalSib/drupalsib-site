<?php
/**
 * @file
 * dssocial_core_feature_nodequeue.features.inc
 */

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function dssocial_core_feature_nodequeue_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: headline_slider
  $nodequeues['headline_slider'] = array(
    'name' => 'headline_slider',
    'title' => 'Headline slider',
    'subqueue_title' => '',
    'size' => '5',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'types' => array(
      0 => 'headline',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: headline_tiles
  $nodequeues['headline_tiles'] = array(
    'name' => 'headline_tiles',
    'title' => 'Headline tiles',
    'subqueue_title' => '',
    'size' => '9',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'types' => array(
      0 => 'headline',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
