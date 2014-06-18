<?php
/**
 * @file
 * Theme functions for authora this article.
 */

$plugin = array(
  'title' => t('About the author'),
  'description' => t('About the author'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_about_author_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns content node.
 */
function dssocial_core_dssocial_about_author_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $context = dssocial_core_get_context_by_type($context, 'node');
  $node = $context->data;
  $output = '';
  $user_autors = $node->field_author[LANGUAGE_NONE][0]['target_id'];
  $user_autor = user_load($user_autors);

  if ($user_autor->uid == $user->uid) {
    $user_path = 'user/' . $user_autor->uid . '/profile_edit';
  }
  else {
    $user_path = 'user/' . $user_autor->uid;
  }
    // Name.
  $vars['name'] = l($user_autor->name, $user_path);
  $profil = profile2_load_by_user($user_autor);
    // Image.
  if (!empty($profil['main_profile']->field_logo)) {
    $vars['user_logo'] = l(theme(
      'image_style',
      array(
        'path' => $profil['main_profile']->field_logo[LANGUAGE_NONE][0]['uri'],
        'style_name' => 'author_image',
        'attributes' => array(
          'class' => 'ds_author_img'),
      )
    ), $user_path, array('html' => TRUE));
  }
    // Information.
  if (!empty($profil['main_profile']->field_information)) {
      $vars['user_information'] = t(dssocial_core_trim_title($profil['main_profile']->field_information[LANGUAGE_NONE][0]['value'], 155));
  }
    // About user articles.
  $vars['about_user_articles'] = l(t("+ view all articles"), 'user/' . $user_autor->uid);
  if (!empty($vars)) {
    $output = theme('dssocial_about_author', array('vars' => $vars));
  }
  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions for articles this theme.
 */
function dssocial_core_dssocial_about_author_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_about_author'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-about-author',
  );
}
