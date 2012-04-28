<?php
/**
 * @file
 * drupalsib_site_feature_dossier.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalsib_site_feature_dossier_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
