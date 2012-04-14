<?php

/**
 * @file
 * Plugin to handle the 'node' content type which allows individual nodes
 * to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
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
 * Output function for the 'node' content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function drupalsib_site_userbar_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  
  $links = '';

  if (user_is_anonymous()) {
      $login_link = l('&nbsp' . t('Вход'), 'user/login', array('html' => TRUE));
      $links .= '<img src="/' . DRUPALSIB_SITE_THEME_PATH .
              '/images/icon_login.png" ' . 
              'class="icon_login" alt="' . t('login') . '"/>';
      $links .= '<span>' . $login_link . '</span>';
  }
  else {
      $links = '<ul>
        <li class="first"><a href="#"><img src="/<?php print DRUPALSIB_SITE_THEME_PATH; ?>/images/avatar.jpeg" class="icon_login" alt="login"/></a></li>
        <li><a href="#">nick-name</a></li>
        <li><a href="#">cообщения</a></li>
        <li><a href="#">выйти</a></li>
    </ul>';
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
