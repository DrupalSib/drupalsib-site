<?php
/**
 * @file
 * Theme functions User profile links.
 */

$plugin = array(
  'title' => t('User profile links'),
  'description' => t('User profile links'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_user_profile_links_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns links.
 */
function dssocial_core_dssocial_user_profile_links_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $output = '';

  if ($user->uid == $panel_args[0] || $user->uid == 1) {
    $vars['link'] = l(
      t('Edit my profile'),
      "user/{$user->uid}/profile_edit"
    );
    $output = theme('dssocial_user_profile_links', $vars);
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions User profile links.
 */
function dssocial_core_dssocial_user_profile_links_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_user_profile_links'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-user-profile-links',
  );
}
