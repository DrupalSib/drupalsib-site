<?php
/**
 * @file
 * dssocial_core_feature_asset_types.features.inc
 */

/**
 * Implements hook_default_asset_type().
 */
function dssocial_core_feature_asset_types_default_asset_type() {
  $items = array();
  $items['image'] = entity_import('asset_type', '{
    "type" : "image",
    "name" : "Image",
    "icon" : "AddImage.png",
    "description" : "",
    "help" : "",
    "weight" : "0",
    "locked" : "0",
    "uuid" : "",
    "rdf_mapping" : []
  }');
  return $items;
}
