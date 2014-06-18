<?php
/**
 * @file
 * Theme functions User profile tabs.
 */

$plugin = array(
  'title' => t('User profile tabs'),
  'description' => t('User profile tabs'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_user_profile_tabs_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns tabs.
 */
function dssocial_core_dssocial_user_profile_tabs_content_type_render($subtype, $conf, $panel_args, $context) {
  $user = user_load($panel_args[0]);

  $vars['link_popularity'] = l(
    t('popularity'), "user/$user->uid/popularity", array(
      'attributes' => array(
        'id' => 'first_tab',
      ),
    )
  );

  $vars['link_comment'] = l(
    t('comment on articles'), "user/$user->uid/comment", array(
      'attributes' => array(
        'id' => 'click-comments',
      ),
    )
  );

  $vars['link_content'] = l(
    t('content'), "user/$user->uid", array(
      'attributes' => array(
        'id' => 'click-content',
      ),
    )
  );

  if (!empty($vars)) {
    $output = theme('dssocial_user_profile_tabs', $vars);
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions User profile tabs.
 */
function dssocial_core_dssocial_user_profile_tabs_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_user_profile_tabs'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-user-profile-tabs',
  );
}
