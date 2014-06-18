<?php


/**
 * Implementation of hook_views_data()
 */
function views_fb_like_views_data() {
  $data = array();

  $data['views_fb_like']['table']['group'] = t('FB');

  $data['views_fb_like']['table']['join']['node'] = array(
    'field' => 'nid',
    'left_field' => 'nid',
  );

  $data['views_fb_like']['count'] = array(
    // For backwards compatibility with version 6.x-1.0.
    'real field' => 'like_count',
    'title' => t('Number of Likes'),
    'help' => t('The number of times Facebook users have "Liked" the page.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['views_fb_like']['share_count'] = array(
    'title' => t('Number of Shares'),
    'help' => t('The number of times users have shared the page on Facebook.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['views_fb_like']['comment_count'] = array(
    'title' => t('Number of Comments'),
    'help' => t('The number of comments users have made on the shared story.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['views_fb_like']['total_count'] = array(
    'title' => t('Total number'),
    'help' => t('The total number of times the URL has been shared, liked, or commented on.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['views_fb_like']['last_updated'] = array(
    'title' => t('Last updated'),
    'help' => t('The date the last time the FB like count was updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_plugins().
 */
function views_fb_like_views_plugins() {
  return array(
    'display' => array(
      'views_fb_like_execution' => array(
        'title' => t('FB Likes fetcher'),
        'help' => t("The view will be executed periodically."),
        'handler' => 'views_fb_like_plugin_display',
        'theme' => 'views_view',
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'use more' => FALSE,
        'accept attachments' => FALSE,
        'admin' => t('Periodic execution'),
        // Don't alow direct instances of this display:
        //'no ui' => FALSE,
        'parent' => 'views_periodic_execution',
        'use root account' => TRUE,
      ),
    ),
  );
}
