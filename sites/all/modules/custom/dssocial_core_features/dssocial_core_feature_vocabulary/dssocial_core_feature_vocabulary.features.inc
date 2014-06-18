<?php
/**
 * @file
 * dssocial_core_feature_vocabulary.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dssocial_core_feature_vocabulary_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
