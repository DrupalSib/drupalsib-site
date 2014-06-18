<?php
/**
 * @file
 * Theme functions User profile edit.
 */

$plugin = array(
  'title' => t('User profile edit'),
  'description' => t('User profile edit'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_user_profile_edit_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns edit.
 */
function dssocial_core_dssocial_user_profile_edit_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $user_edit_profile = user_load($panel_args[0]);

  if ($user->uid == $user_edit_profile->uid || $user->uid == 1) {
    module_load_include('inc', 'user', 'user.pages');
    $form = drupal_get_form('user_profile_form', $user_edit_profile, 'main_profile');
    $output = theme('dssocial_user_profile_edit', array('form' => $form));
  }
  else {
    $output = t('No access');
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions User profile edit.
 */
function dssocial_core_dssocial_user_profile_edit_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_user_profile_edit'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-user-profile-edit',
  );
}
