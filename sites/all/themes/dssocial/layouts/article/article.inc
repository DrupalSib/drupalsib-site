<?php
/**
 * @file
 * Layout for article node
 */

// Plugin definition.
$plugin = array(
  'title' => t('Article'),
  'category' => t('Dssocial'),
  'icon' => 'article.png',
  'theme' => 'dssocial_article',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left'),
    'right' => t('Right'),
    'comment_form' => t('Comment form'),
    'posted_comments' => t('Posted comments'),
  ),
);
