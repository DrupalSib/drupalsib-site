<?php
/**
 * @file
 * Theme functions info user.
 */

$plugin = array(
  'title' => t('Info user'),
  'description' => t('Info user'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_user_info_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns content node.
 */
function dssocial_core_dssocial_user_info_content_type_render($subtype, $conf, $panel_args, $context) {
  $user = user_load($panel_args[0]);

  if (!empty($user)) {
    $profile = profile2_load_by_user($user);
    $vars['name'] = $user->name;
    $vars['user_member_for'] = format_interval(REQUEST_TIME - $user->created);

    if (!empty($profile['main_profile']->field_logo)) {
      $vars['user_logo'] = l(theme(
        'image_style',
        array(
          'path' => $profile['main_profile']->field_logo[LANGUAGE_NONE][0]['uri'],
          'style_name' => 'author_info',
        )
      ), 'user/' . $user->uid, array('html' => TRUE));
    }
  }
  if (!empty($vars)) {
    $output = theme('dssocial_user_info', $vars);
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions info user.
 */
function dssocial_core_dssocial_user_info_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_user_info'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-user-info',
  );
}
