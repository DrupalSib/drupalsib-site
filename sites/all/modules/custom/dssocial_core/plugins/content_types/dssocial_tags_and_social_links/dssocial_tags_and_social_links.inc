<?php
/**
 * @file
 * Theme functions for like button.
 */

$plugin = array(
  'title' => t('Social links and tags'),
  'description' => t('Social links and tags'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_tags_and_social_links_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_tags_and_social_links_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $context = dssocial_core_get_context_by_type($context, 'node');
//  rate_node_view($context->data, 'full');
  $output = '';
  if (!empty($context->data)) {
    $services = array();
    $node = $context->data;
    $style = variable_get('service_links_block_style', SERVICE_LINKS_STYLE_IMAGE_AND_TEXT);
//    $services = service_links_render($node, FALSE, $style);

    if (!empty($context->data->content['rate_like'])) {
      $services[] = drupal_render($context->data->content['rate_like']);
    }

//    $services[] = dssocial_core_get_vk_like();
//    $services[] = dssocial_core_get_fb_like();
    $conf['right'] = theme('dssocial_social_links', array('buttons' => $services));

    if ($conf['selected_tag_or_info'] == DSSSOCIAL_TAGS_AND_SOCIAL_LINKS_TAGS) {
      if (!empty($node->field_tags)) {
        $vars['tags'] = implode(',', dssocial_core_field_get_term($node->field_tags));
        $conf['left'] = theme('dssocial_tags', array('tags' => $vars['tags']));
      }
    }

    if (isset ($conf['author_information']) && ($conf['selected_tag_or_info'] == DSSSOCIAL_TAGS_AND_SOCIAL_LINKS_AUTHOR_INFORMACHION) && ($node->type != 'poll')) {
      $user_author = user_load($node->field_author[LANGUAGE_NONE][0]['target_id']);

      if ($user_author->uid == $user->uid) {
        $user_path = 'user/' . $user_author->uid . '/profile_edit';
      }
      else {
        $user_path = 'user/' . $user_author->uid;
      }

      if (!empty($user_author->name)) {
        $author_information['author_name'] = l($user_author->name, $user_path);
      }

      $profile = profile2_load_by_user($user_author);

      if (!empty($profile['main_profile']->field_logo)) {
        $author_information['author_image'] = l(theme(
        'image_style',
          array(
            'path' => $profile['main_profile']->field_logo[LANGUAGE_NONE][0]['uri'],
            'style_name' => 'author_avatar',
            'attributes' => array(
              'class' => 'ds_author_img'),
          )
        ), $user_path, array('html' => TRUE));
      }

      if (!empty($context->data->field_date[LANGUAGE_NONE])) {
        $author_information['author_date_publication'] = t('@date', array(
          '@date' => format_date($context->data->field_date[LANGUAGE_NONE][0]['value'], 'custom', 'd/m/Y'),
        ));
      }
      else {
        $author_information['author_date_publication'] = t('@date', array(
          '@date' => format_date($context->data->created, 'custom', 'd/m/Y'),
        ));
      }

      $conf['left'] = theme('author', array('author_information' => $author_information));
    }
    $output = theme('dssocial_tags_and_social_links', array('conf' => $conf));
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions for tags and social button this theme.
 */
function dssocial_core_dssocial_tags_and_social_links_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_tags_and_social_links'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-tags-and-social-links',
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_tags_and_social_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['selected_tag_or_info'] = array(
    '#type' => 'select',
    '#title' => t('Selected tags or author information'),
    '#options' => array(t('tag'), t('author_information'), t('none')),
    '#default_value' => $conf['selected'],
    '#description' => t('Selected tags or author information'),
  );
  $form['selected_type'] = array(
    '#type' => 'select',
    '#title' => t('Selected type for block'),
    '#options' => array(t('small'), t('big')),
    '#default_value' => $conf['selected'],
    '#description' => t('Selected type for block'),
  );
  return $form;
}

/**
 * Implements hook_content_type_edit_form_submit().
 */
function dssocial_core_dssocial_tags_and_social_links_content_type_edit_form_submit(&$form, &$form_state) {
  foreach ($form_state['values'] as $key => $value) {
    $form_state['conf'][$key] = $value;
  }
}
