<?php

function drupalsib_preprocess_node(&$vars, $hook) {
$view_mode = $vars['view_mode'];
$node = $vars['node'];

$preprocess = 'bl_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
if (function_exists($preprocess)) {
$preprocess($vars, $hook);
}

$vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);

 
}