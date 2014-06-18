<?php
/**
 * @file
 * Theme functions for dssocial_core module.
 */

/**
 * Theme content category name function.
 *
 * @param type $vars
 *   Type $vars.
 *
 * @return type
 *   Type.
 */
function theme_dssocial_core_content_category_name($vars) {
  $output = '';
  $term_tid = NULL;
  $node = $vars['node'];
  if (!empty($node->field_content_category[LANGUAGE_NONE][0]['target_id'])) {
    $term = taxonomy_term_load($node->field_content_category[LANGUAGE_NONE][0]['target_id']);
    $term_tid = $term->tid;
    $output = $term->name . ' / ';
  }

  if ($term_tid) {
    $output = l(
      $output,
      "taxonomy/term/$term_tid/popularity",
      array(
        'attributes' => array(
          'title' => $term->name,
        ),
      )
    );
  }

  return $output;
}

/**
 * Theme content tags function.
 *
 * @param array $vars
 *   Array $vars.
 *
 * @return string
 *   String.
 */
function theme_dssocial_core_content_tags($vars) {
  $output = '';
  $node = $vars['node'];

  if (!empty($node->field_tags[LANGUAGE_NONE])) {
    foreach ($node->field_tags[LANGUAGE_NONE] as $value) {
      $tag = taxonomy_term_load($value['target_id']);
      if (!empty($tag)) {
        $output[] = l(
          $tag->name,
          "taxonomy/term/{$tag->tid}/tag/popularity",
          array(
            'attributes' => array(
              'title' => $tag->name,
            ),
          )
        );
      }
    }

    $output = implode(', ', $output);
  }

  return $output;
}
