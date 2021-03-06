<?php
/**
 * @file
 * dssocial_core_feature_content_headline.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dssocial_core_feature_content_headline_user_default_permissions() {
  $permissions = array();

  // Exported permission: create headline content.
  $permissions['create headline content'] = array(
    'name' => 'create headline content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any headline content.
  $permissions['delete any headline content'] = array(
    'name' => 'delete any headline content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own headline content.
  $permissions['delete own headline content'] = array(
    'name' => 'delete own headline content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any headline content.
  $permissions['edit any headline content'] = array(
    'name' => 'edit any headline content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own headline content.
  $permissions['edit own headline content'] = array(
    'name' => 'edit own headline content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
