<?php
/**
 * @file
 * dssocial_core_feature_content_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dssocial_core_feature_content_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: create article content.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'editor',
      1 => 'moderator',
      2 => 'writer',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any article content.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'editor',
      1 => 'moderator',
      2 => 'writer',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any article content.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own article content.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'editor',
      1 => 'moderator',
      2 => 'writer',
    ),
    'module' => 'node',
  );

  return $permissions;
}
