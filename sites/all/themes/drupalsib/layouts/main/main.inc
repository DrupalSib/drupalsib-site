<?php

// Plugin definition
$plugin = array(
  'title' => t('Main'),
  'category' => t('Drupalsib'),
  'icon' => 'main.png',
  'theme' => 'drupalsib_main',
  'css' => 'main.css',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer')
  ),
);
