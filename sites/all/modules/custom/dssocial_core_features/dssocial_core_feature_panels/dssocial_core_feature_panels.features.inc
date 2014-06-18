<?php
/**
 * @file
 * dssocial_core_feature_panels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dssocial_core_feature_panels_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
