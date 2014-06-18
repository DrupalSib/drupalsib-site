<?php
/**
 * @file
 * dssocial_core_feature_strongarm_variable.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dssocial_core_feature_strongarm_variable_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dssocial_core_fb_api_id';
  $strongarm->value = 'dssite.dev';
  $export['dssocial_core_fb_api_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dssocial_core_vk_api_id';
  $strongarm->value = '2979870';
  $export['dssocial_core_vk_api_id'] = $strongarm;

  return $export;
}
