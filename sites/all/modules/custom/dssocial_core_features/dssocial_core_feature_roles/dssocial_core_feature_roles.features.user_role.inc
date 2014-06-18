<?php
/**
 * @file
 * dssocial_core_feature_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dssocial_core_feature_roles_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '3',
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => '2',
  );

  // Exported role: writer.
  $roles['writer'] = array(
    'name' => 'writer',
    'weight' => '4',
  );

  return $roles;
}
