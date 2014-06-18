<?php
/**
 * @file
 * dssocial_core_feature_vocabulary.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dssocial_core_feature_vocabulary_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dssocial_core_comment_message';
  $strongarm->value = 'The number of characters in the text of comments exceeds the allowable limit of 1000 characters.';
  $export['dssocial_core_comment_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'dssocial_core_vk_api_id';
  $strongarm->value = '2979870';
  $export['dssocial_core_vk_api_id'] = $strongarm;

  return $export;
}
