<?php
/**
 * @file
 * Theme functions for poll this theme.
 */

$plugin = array(
  'title' => t('Poll see also'),
  'description' => t('Poll see also'),
  'category' => t('Dssocial core'),
  'hook theme' => 'dssocial_core_dssocial_poll_see_also_content_type_theme',
  'all contexts' => TRUE,
);

/**
 * Returns content node.
 */
function dssocial_core_dssocial_poll_see_also_content_type_render($subtype, $conf, $panel_args, $context) {
  $conf['title'] = !empty($conf['override_title_text']) ? $conf['override_title_text'] : t('on the same theme');
  $context = dssocial_core_get_context_by_type($context, 'node');
  $node = $context->data;
  $output = '';
  if (!empty($node)) {
    $section = '';
    if (!empty($node->field_section)) {
      $section = $node->field_section[LANGUAGE_NONE][0]['target_id'];
    }
    $results = views_get_view_result('poll_list', 'poll_theme', $section, $node->nid);
    if (!empty($results)) {
      foreach ($results as $key => $result) {
        // Link.
        $poll_also[$key]['link'] = url('node/' . $result->nid);
        // Title.
        if (!empty($result->_field_data['nid']['entity']->field_poll_title)) {
          $poll_title = $result->_field_data['nid']['entity']->field_poll_title[LANGUAGE_NONE][0]['value'];
          $poll_also[$key]['title'] = dssocial_core_trim_title($poll_title, 45);
        }
        else {
          $poll_also[$key]['title'] = dssocial_core_trim_title($result->node_title, 30);
        }
        // Image.
        if (!empty($result->field_field_image)) {
          $poll_also[$key]['image'] = theme('image_style', array(
            'path' => $result->field_field_image[0]['raw']['uri'],
            'style_name' => 'poll_image',
          ));
        }
      }
      if (!empty($poll_also)) {
        $output = theme('dssocial_poll_see_also', array('poll_also' => $poll_also, 'conf' => $conf));
      }
    }
  }

  $block = new stdClass();
  $block->content = $output;
  return $block;
};

/**
 * Theme functions for poll this theme.
 */
function dssocial_core_dssocial_poll_see_also_content_type_theme(&$theme, $plugin) {
  $theme['dssocial_poll_see_also'] = array(
    'path' => $plugin['path'],
    'template' => 'dssocial-poll-see-also',
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function dssocial_core_dssocial_poll_see_also_content_type_edit_form($form, &$form_state) {
  return $form;
}
