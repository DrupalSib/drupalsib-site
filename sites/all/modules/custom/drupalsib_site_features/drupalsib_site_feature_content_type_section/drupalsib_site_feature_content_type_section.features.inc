<?php
/**
 * @file
 * drupalsib_site_feature_content_type_section.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupalsib_site_feature_content_type_section_node_info() {
  $items = array(
    'section' => array(
      'name' => t('Section'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
