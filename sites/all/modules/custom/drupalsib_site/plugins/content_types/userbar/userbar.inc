<?php

$plugin = array(
  'title' => t('Userbar'),
  'single' => TRUE,
  'icon' => 'icon_userbar.png',
  'description' => t('Add a userbar from your site as content.'),
  'category' => t('Drupalsib'),
  'hook theme' => 'drupalsib_site_userbar_content_type_theme',
);

function drupalsib_site_userbar_content_type_render($subtype, $conf, $panel_args) {
  global $user;
  $block = new stdClass();

  $links = '';

  if (user_is_anonymous()) {
    $login_link = l('&nbsp' . t('Вход'), 'user/login', array('html' => TRUE));
    $links .= '<img src="/' . DRUPALSIB_SITE_THEME_PATH .
        '/images/icon_login.png" ' .
        'class="icon_login" alt="' . t('login') . '" title="' . t('login') . '"/>';
    $links .= '<span>' . $login_link . '</span>';
  } else {
    if (!empty($user->uid)) {
      $user = user_load($user->uid);
    }
    if (!empty($user->picture->uri)) {
      $avatar = theme('image_style', array(
          'path' => $user->picture->uri,
          'style_name' => 'login_img'
          ));
    }
    $img_link = l($avatar, "user/$user->uid", array('html' => TRUE));
    $nick_link = l($user->name, "user/$user->uid", array('html' => TRUE));
    $mes_link = l(t('Сообщения'), '#', array('html' => TRUE));
    $out_link = l(t('Выйти'), '', array('html' => TRUE));

    $links .= '<ul><li class="first">' . $img_link . '</li>' .
        '<li>' . $nick_link . '</li>' .
        '<li>' . $mes_link . '</li>' .
        '<li>' . $out_link . '</li></ul>';
  }

  $block->content = theme('drupalsib_site_userbar', array('links' => $links));

  return $block;
}

function drupalsib_site_userbar_content_type_theme(&$theme, $plugin) {
  $theme['drupalsib_site_userbar'] = array(
    'path' => $plugin['path'],
    'template' => 'drupalsib_site_userbar',
  );
}