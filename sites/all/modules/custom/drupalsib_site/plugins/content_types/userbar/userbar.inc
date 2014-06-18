<?php
/**
 * @file
 * Theme functions for drupalsib_site_userbar.
 */

$plugin = array(
  'title' => t('Userbar'),
  'single' => TRUE,
  'icon' => 'icon_userbar.png',
  'description' => t('Add a userbar from your site as content.'),
  'category' => t('Drupalsib'),
  'hook theme' => 'drupalsib_site_userbar_content_type_theme',
);

/**
 * Userbar.
 *
 */
function drupalsib_site_userbar_content_type_render($subtype, $conf, $panel_args) {
  global $user;
  $block = new stdClass();

  $links = '';

  $img_link = '';

  if (user_is_anonymous()) {
    $space = '&nbsp';
    $login_link = l($space . t('Вход'), 'user/login', array('html' => TRUE));
    $login_link .= l($space . t(' Регистрация'), 'user/register', array('html' => TRUE));
    $links .= '<img src="/' . DRUPALSIB_SITE_THEME_PATH . '/images/icon_login.png" ' . 'class="icon_login" alt="' . t('login') . '" title="' . t('login') . '"/>';
    $links .= '<span>' . $login_link . '</span>';
  }
  else {
    if (!empty($user->uid)) {
      $user = user_load($user->uid);
    }
    if (!empty($user->picture->uri)) {
      $avatar = theme('image_style', array(
          'path' => $user->picture->uri,
          'style_name' => array('login_img'),
          ));
      $img_link = l($avatar, "user/$user->uid/profile_edit", array('html' => TRUE));
    }

    $nick_link = l($user->name, "user/$user->uid/profile_edit", array('html' => TRUE));
    $out_link = l(t('Выйти'), 'user/logout', array('html' => TRUE));
    $links .= '<ul><li class="first">' . $img_link . '</li>' . '<li>' . $nick_link . '</li>' . '<li class="last">' . $out_link . '</li></ul>';
  }

  $block->content = theme('drupalsib_site_userbar', array('links' => $links));

  return $block;
}

/**
 * Userbar theme.
 */
function drupalsib_site_userbar_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_userbar'] = array(
    'path' => $plugin['path'],
    'template' => 'drupalsib_site_userbar',
  );
}
