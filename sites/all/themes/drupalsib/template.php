<?php

function drupalsib_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];
  $preprocess = 'drupalsib_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

  if (function_exists($preprocess)) {
    $preprocess($vars, $hook);
  }

  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
//  kpr($vars['theme_hook_suggestions']);
}

function drupalsib_preprocess_node__headline_teaser(&$vars) {
  $node = $vars['node'];
  $vars['description'] = $node->field_headline_description['und'][0]['value'];
  $vars['image'] = theme('image_style', array(
       'path' => $node->field_headline_image['und'][0]['uri'],
       'style_name' => 'headline_teaser'
      ));
//  kpr($vars['node']);
}