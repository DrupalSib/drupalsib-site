<?php
/**
 * @file
 * dssocial_core_feature_views_headline_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dssocial_core_feature_views_headline_list_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dssocial_core_feature_views_headline_list_views_api() {
  return array("version" => "3.0");
}
