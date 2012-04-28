<?php
/**
 * @file
 * drupalsib_site_feature_content_type_dossier.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupalsib_site_feature_content_type_dossier_node_info() {
  $items = array(
    'dossier' => array(
      'name' => t('Dossier'),
      'base' => 'node_content',
      'description' => t('The dossiers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
