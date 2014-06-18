<?php
/**
 * @file
 * Theme functions for dssocial theme.
 */

/**
 * Preprocess for a breadcrumb trail.
 *
 * @see theme_breadcrumb()
 */
function dssocial_preprocess_breadcrumb(&$vars) {
  global $user;

  $vars['output'] = '';
  $homepage_delimeter = ' : ';
  $section = NULL;
  $category = NULL;
  $account = NULL;
  $content = NULL;
  if (!drupal_is_front_page()) {
    if ($node = menu_get_object()) {
      if (!empty($node->field_section[LANGUAGE_NONE][0]['target_id'])) {
        $section = node_load($node->field_section[LANGUAGE_NONE][0]['target_id']);
        $content = $node;
      }
      elseif (!empty($node->field_content_category[LANGUAGE_NONE][0]['target_id'])) {
        // Load category;
        $query = db_select('node', 'n');
        $query->fields('n', array('nid'));
        $query->join('field_data_field_dossier_content', 'fdfdc', 'n.nid = fdfdc.entity_id');
        $query->condition('n.status', 1);
        $query->condition('fdfdc.entity_type', 'node');
        $query->condition('fdfdc.field_dossier_content_target_id', $node->nid);
        $results = $query->execute()->fetchCol();
        if (!empty($results)) {
          $section = node_load(array_shift($results));
        }
        $content = $node;
      }

      if ($node->type == 'page') {
        $vars['output'] .= dssocial_core_trim_title(check_plain($node->title), 50);
      }
      elseif (!$content) {
        $content = $node;
      }
    }
    elseif (arg(0) == 'user') {
      if (is_numeric(arg(1)) && $account = user_load(arg(1))) {
        $vars['output'] .= t('User : ') . check_plain($account->name);
      }
      elseif (arg(1) == 'register' && user_is_anonymous()) {
        $vars['output'] .= t('Register');
      }
      elseif (arg(1) == 'login' && user_is_anonymous()) {
        $vars['output'] .= t('Log in');
      }
      elseif (arg(1) == 'password' && user_is_anonymous()) {
        $vars['output'] .= t('Request new password');
      }
      else {
        if (user_is_logged_in()) {
          $vars['output'] .= t('User : ') . check_plain($user->name);
        }
        else {
          $vars['output'] .= t('Log in');
        }
      }
    }
    elseif (arg(0) == 'taxonomy' && $taxonomy = taxonomy_term_load(arg(2))) {
      $vars['output'] .= check_plain($taxonomy->name);
    }
    elseif (arg(0) == 'rss') {
      $vars['output'] .= t('RSS');
    }
    elseif (search_is_active()) {
      $vars['output'] .= t('Search results');
    }

    // Fill section.
    if ($section) {
      // Fill parent section if exist.
      if (!empty($section->field_section[LANGUAGE_NONE][0]['target_id'])) {
        $parent_section = node_load($section->field_section[LANGUAGE_NONE][0]['target_id']);
        if (!empty($parent_section)) {
          $homepage_delimeter = ' > ';
          $vars['output'] .= l($parent_section->title, "node/$parent_section->nid");
          $vars['output'] .= ' > ';
        }
      }

      if ($content) {
        $homepage_delimeter = ' > ';

        $vars['output'] .= l($section->title, 'node/' . $section->nid);
        $vars['output'] .= ' : ';
        $vars['output'] .= dssocial_core_fill_node_breadcrumb($content);
      }
      else {
        $vars['output'] .= dssocial_core_trim_title(check_plain($section->title), 50);
      }
    }
    elseif ($content) {
      $vars['output'] .= dssocial_core_fill_node_breadcrumb($content);
    }

    // Add homepage link.
    if ($vars['output']) {
      $vars['output'] = l(t('Home'), '<front>') . $homepage_delimeter . $vars['output'];
    }
    else {
      $vars['output'] = l(t('Home'), '<front>');
    }
  }
}

/**
 * Provide additional prepositions.
 */
function dssocial_preprocess_node(&$vars, $hook) {
  $node = $vars['node'];
  $view_mode = $vars['view_mode'];
  $preprocess = 'dssocial_preprocess_node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
  if (function_exists($preprocess)) {
    $preprocess($vars, $hook);
  }
  $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '_' . str_replace('-', '_', $view_mode);
}

/**
 * Process variables for views-view.tpl.php
 *
 * @see views-view.tpl.php
 */
function dssocial_preprocess_views_view(&$vars) {
  if (!empty($vars['theme_hook_suggestions']) && is_string($vars['theme_hook_suggestions'])) {
    $function = 'dssocial_preprocess_' . $vars['theme_hook_suggestions'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-fields.tpl.php
 *
 * @see views-view-fields.tpl.php
 */
function dssocial_preprocess_views_view_fields(&$vars) {
  if (isset($vars['theme_hook_suggestions'])) {
    $function = 'dssocial_preprocess_' . $vars['theme_hook_suggestions'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * Process variables for views-view-table.tpl.php
 *
 * @see views-view-table.tpl.php
 */
function dssocial_preprocess_views_view_table(&$vars) {
  if (isset($vars['theme_hook_suggestions'])) {
    $function = 'dssocial_preprocess_' . $vars['theme_hook_suggestions'];
    if (function_exists($function)) {
      $function($vars);
    }
  }
}
/**
 * Preprocess view mode teaser for headline.
 */
function dssocial_preprocess_node__headline_teaser(&$vars) {
  // Description.
  if (!empty($vars['elements']['field_description'])) {
    $vars['description'] = render($vars['elements']['field_description']);
  }
  // Image.
  $vars['image'] = theme('image_style', array(
      'path' => $vars['field_headline_image'][LANGUAGE_NONE][0]['uri'],
      'style_name' => 'headline_view_teaser',
      'alt' => !empty($vars['field_headline_image'][LANGUAGE_NONE][0]['alt']) ? $vars['field_headline_image'][LANGUAGE_NONE][0]['alt'] : $vars['title'],
  ));
  // Select gradient.
  if (!$vars['field_headline_gradient'][LANGUAGE_NONE][0]['value']) {
    $vars['class'] = 'ds_description_white';
  }
  else {
    $vars['class'] = 'ds_description';
  }
  // Link.
  $vars['link'] = '#';
  if (!empty($vars['field_headline_reference'])) {
    $vars['link'] = url('node/' . $vars['field_headline_reference'][LANGUAGE_NONE][0]['target_id']);
  }
}

/**
 * Preprocess view mode full for headline.
 */
function dssocial_preprocess_node__headline_full(&$vars) {
  $node = $vars['node'];
  static $number = 0;
  $vars['number'] = $number;
  $number++;
  // Image.
  $vars['image'] = theme('image_style', array(
      'path' => $node->field_headline_image[LANGUAGE_NONE][0]['uri'],
      'style_name' => 'slider_list_view',
      'alt' => !empty($node->field_headline_image[LANGUAGE_NONE][0]['alt']) ? $node->field_headline_image[LANGUAGE_NONE][0]['alt'] : $vars['title'],
      'attributes' => array('class' => array('cell-image')),
  ));
  // Title color.
  if (!empty($node->field_headline_title_color[LANGUAGE_NONE])) {
    $vars['title_color'] = t($node->field_headline_title_color[LANGUAGE_NONE][0]['value']);
  }
  // Link.
  $vars['link'] = '#';

  // Select gradient.
  if (empty($node->field_headline_gradient[LANGUAGE_NONE][0]['value'])) {
    $vars['class'] = 'ds-description-headline';
  }
  else {
    $vars['class'] = 'ds-description-headline-white';
  }

  if (!empty($node->field_headline_reference[LANGUAGE_NONE])) {
    $vars['link'] = l(
      t(''),
      'node/' . $node->field_headline_reference[LANGUAGE_NONE][0]['target_id'],
      array(
        'attributes' => array(
          'class' => array(
            'slide-link',
            'card-style-overlay',
          ),
        ),
      )
    );
  }
}

/**
 * Preprocess view node full for article.
 */
function dssocial_preprocess_node__article_full(&$vars) {
  $node = $vars['node'];
  // Title.
  $vars['title'] = dssocial_core_trim_title(($node->title), 250);
  // Description.
  if (!empty($node->field_article_description)) {
    $vars['description'] = check_markup($node->field_article_description[LANGUAGE_NONE][0]['value'], 'filtered_html');
  }
  // Tags.
  if (!empty($node->field_tags)) {
    $vars['tags'] = implode(',', dssocial_core_field_get_term($node->field_tags));
  }
  // Primary media.
  if (!empty($node->field_media_primary)) {
    switch ($node->field_media_primary[LANGUAGE_NONE][0]['value']) {
      case 'image':
        // Image.
        if (!empty($node->field_image[LANGUAGE_NONE])) {
          $vars['image'] = theme('image_style', array(
            'path' => $node->field_image[LANGUAGE_NONE][0]['uri'],
            'style_name' => 'article_image_full',
          ));
        }
        break;

      case 'video':
        // Video.
        $config = array(
          'clip' => array(
            'url' => file_create_url($node->field_video[LANGUAGE_NONE][0]['uri']),
            'autoPlay' => FALSE,
          ));
        $vars['video'] = theme('flowplayer', array(
          'config' => $config, 'attributes' => array(
            'style' => 'width:464px;height:288px;'),
            ));
        break;

      case 'slideshow':
        // Slideshow.
        if (!empty($node->field_slideshow[LANGUAGE_NONE])) {
          $slideshow = node_load($node->field_slideshow[LANGUAGE_NONE][0]['target_id']);
          if (!empty($slideshow->field_slideshow_image[LANGUAGE_NONE])) {
            foreach ($slideshow->field_slideshow_image[LANGUAGE_NONE] as $slide) {
              $vars['link'] = $slide['uri'];
              $vars['slides'][] = theme('image_style', array(
                'path' => $slide['uri'],
                'style_name' => 'article_image_full',
                'attributes' => array(
                  'class' => array('imagecache', 'imagecache-diaporama_large'),
                  'width' => 464,
                  'height' => 288,
                ),
              ));
            }
            $vars['link'] = file_create_url($slide['uri']);
            foreach ($slideshow->field_slideshow_image[LANGUAGE_NONE] as $diagramm) {
              $vars['diagramms'][] = theme('image_style', array(
                'path' => $diagramm['uri'],
                'style_name' => 'image_diagramma_small',
                'attributes' => array(
                  'class' => array('imagecache', 'imagecache-diaporama_small'),
                  'width' => 77,
                  'height' => 48,
                )));
            }

            $vars['previous'] = l(
              t(''),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'deck-prev-link',
                  'title' => t('Previous'),
                ),
              )
            );

            $vars['next'] = l(
              t(' '),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'deck-next-link',
                  'title' => t('Next'),
                  'style' => 'margin-right:8px',
                ),
              )
            );

            $vars['close_block'] = l(
              t(''),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'open-link',
                  'onclick' => "$('#deck-container').removeClass('hide-description'); $('.open-close-block .open-link').addClass('active');$('.open-close-block .close-link').removeClass('active');return false;",
                ),
              )
            );

            $vars['close_sep'] = l(
              t(''),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'close-link active',
                  'onclick' => "$('#deck-container').addClass('hide-description'); $('.open-close-block .close-link').addClass('active'); $('.open-close-block .open-link').removeClass('active'); return false;",
                ),
              )
            );

            $vars['top_next'] = l(
              t(''),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'deck-next-link',
                  'title' => t('Next'),
                  'id' => 'top-next',
                ),
              )
            );

            $vars['top_prev'] = l(
              t(''),
              $vars['link'], array(
                'attributes' => array(
                  'class' => 'deck-prev-link',
                  'title' => t('Previous'),
                  'id' => 'top-prev',
                ),
              )
            );
          }
        }
        break;
    }
  }
}

/**
 * Process variables for node--dossier-full.tpl.php
 *
 * @see node--dossier-full.tpl.php
 */
function dssocial_preprocess_node__dossier_full(&$vars) {
  $node = $vars['node'];
  // Tags.
  if (!empty($node->field_tags)) {
    $vars['tags'] = implode(',', dssocial_core_field_get_term($node->field_tags));
  }
  if (!empty($node->field_dossier_description[LANGUAGE_NONE][0]['value'])) {
    $vars['description'] = $node->field_dossier_description[LANGUAGE_NONE][0]['value'];
  }

}

/**
 * Process variables for node--dossier-teaser.tpl.php
 *
 * @see node--dossier-teaser.tpl.php
 */
function dssocial_preprocess_node__dossier_teaser(&$vars) {
  $node = $vars['node'];
  if (!empty($vars['elements']['field_dossier_description'])) {
    $vars['description'] = render($vars['elements']['field_dossier_description']);
  }
  // Title.
  $vars['title_link'] = l($node->title, "node/$node->nid");
  // Date.
  $vars['date'] = t(
    'Date @date',
    array('@date' => dssocial_core_date_format($vars['created']))
  );
  // Image.
  if (!empty($vars['content']['field_image'])) {
    $vars['image'] = render($vars['content']['field_image']);
  }
  // Tags.
  $vars['tags'] = theme('dssocial_core_content_tags', array('node' => $node));
  // Category.
  $name_ct = t(node_type_get_name($node));
  $vars['category'] = theme('dssocial_core_content_category_name', array('node' => $node));
  $vars['category'] .= $name_ct;
}

/**
 * Preprocess view mode dossier for article.
 */
function dssocial_preprocess_node__article_dossier(&$vars) {
  $node = $vars['node'];
  // Description.
  if (!empty($vars['elements']['field_article_description'])) {
    $vars['description'] = render($vars['elements']['field_article_description']);
  }
  // Link.
  $vars['link'] = '#';
  if (!empty($vars['node_url'])) {
    $vars['link'] = "node/{$node->nid}";
  }
  // Image.
  if (!empty($vars['field_image'][LANGUAGE_NONE])) {
    $vars['image'] = l(theme('image_style', array(
      'path' => $vars['field_image'][LANGUAGE_NONE][0]['uri'],
      'style_name' => 'article_dossier_view',
    )), $vars['link'], array('html' => TRUE));
  }
  // Title.
  $vars['title'] = l(views_trim_text(
      array('max_length' => 30, 'ellipsis' => TRUE, 'html' => TRUE),
      $node->title
    ),
    $vars['link']
  );
  // Category.
  if (!empty($node->field_content_category[LANGUAGE_NONE][0]['target_id'])) {
    $term = taxonomy_term_load($node->field_content_category[LANGUAGE_NONE][0]['target_id']);
    $term_tid = $term->tid;
    $output = $term->name . ' / ';
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
    $output .= t('Article');
    $vars['content_category_name'] = $output;
  }
  // Name.
  $vars['author'] = $node->name;
  // Type.
  $vars['type'] = $node->type;
  // Date.
  if (!empty($node->field_date[LANGUAGE_NONE][0]['value'])) {
    $vars['article_created'] = format_date($node->field_date[LANGUAGE_NONE][0]['value'], 'custom', 'd/m/Y');
  }
  else {
    $vars['article_created'] = dssocial_core_date_format($node->created);
  }
  // Tags.
  $vars['tags'] = '';
  if (!empty($node->field_tags)) {
    foreach ($node->field_tags[LANGUAGE_NONE] as $tag) {
      $tags = taxonomy_term_load_multiple($tag);
    }
    foreach ($tags as $term) {
      if (!empty($vars['tags'])) {
        $vars['tags'] .= ', ';
      }
      $vars['tags'] .= l($term->name, "taxonomy/term/$term->tid/tag/popularity");
    }
  }
}

/**
 * Preprocess view mode full for section.
 */
function dssocial_preprocess_node__section_full(&$vars) {
  $node = $vars['node'];
  $tabs = array(
    'latest' => 'Latest',
    'popularity' => 'Popularity',
    'comments' => 'Comments',
  );
  $active = 'latest';
  $display = 'section_list_latest';
  if (isset($_GET['type']) && isset($tabs[$_GET['type']])) {
    if ($_GET['type'] == 'popularity') {
      $display = 'section_list_popularity';
    }
    elseif ($_GET['type'] == 'comments') {
      $display = 'section_list_comments';
    }
    $active = $_GET['type'];
  }

  $vars['tabs'] = '';
  foreach ($tabs as $key => $value) {
    $options = array('query' => array('type' => $key));
    if ($key == $active) {
      $options['attributes']['class'] = array('highlight');
    }
    $vars['tabs'] .= l(t($value), "node/$node->nid", $options);
  }
  if (!empty($vars['content']['field_section_description'])) {
    $vars['description'] = render($vars['content']['field_section_description']);
  }
  $vars['dossier_list'] = views_embed_view('section_list', $display, $vars['nid']);
}

/**
 * Process variables for node--article-teaser.tpl.php
 *
 * @see node--article-teaser.tpl.php
 */
function dssocial_preprocess_node__article_teaser(&$vars) {
  $node = $vars['node'];
  $vars['title_link'] = l((dssocial_core_trim_title(($node->title), 60)), "node/{$node->nid}");
  $vars['date'] = t(
    'Date @date',
    array('@date' => dssocial_core_date_format($vars['created']))
  );

  $name_ct = t(node_type_get_name($node));
  $vars['content_category_name'] = theme(
    'dssocial_core_content_category_name',
    array(
      'node' => $node,
    )
  );
  $vars['content_category_name'] .= $name_ct;
  $vars['core_content_tags'] = theme(
    'dssocial_core_content_tags',
    array(
      'node' => $node,
    )
  );
  if (!empty($vars['field_article_summary'][LANGUAGE_NONE][0]['value'])) {
    $vars['summary'] = $vars['field_article_summary'][LANGUAGE_NONE][0]['value'];
  }
  if (!empty($vars['elements']['field_article_description'])) {
    $vars['description'] = render($vars['elements']['field_article_description']);
  }
  if (!empty($vars['content']['field_image'])) {
    $vars['image'] = render($vars['content']['field_image']);
  }
}

/**
 * Preprocess view mode teaser for dossier.
 */
function dssocial_preprocess_comment_form(&$vars) {
  // Comment count.
  if (!empty($vars['form']['#node']->comment_count)) {
    $vars['count_comments'] = format_plural($vars['form']['#node']->comment_count,
      'Comments / <span class="smaller"><b>@count</b> comment</span>',
      'Comments / <span class="smaller"><b>@count</b> comments</span>');
  }
  if (!$vars['user']->uid) {
    // If anonymous.
    $vars['user_name'] = t('Anonymous');
  }
  else {
    // If user.
    $user = user_load($vars['user']->uid);
    $profile = profile2_load_by_user($user);
    $vars['user_name'] = l(t($user->name), 'user/' . $user->uid . '/profile_edit');
    // Logo user.
    if (!empty($profile['main_profile']->field_logo)) {
      $vars['user_logo'] = l(theme('image_style', array(
        'path' => $profile['main_profile']->field_logo[LANGUAGE_NONE][0]['uri'],
        'style_name' => 'user_comment_logo',
      )), 'user/' . $user->uid . '/profile_edit', array('html' => TRUE));
    }
  }
  // Unset title.
  if (!empty($vars['form']['comment_body'][LANGUAGE_NONE][0]['value']['#title'])) {
    unset($vars['form']['comment_body'][LANGUAGE_NONE][0]['value']['#title']);
  }
  // Max letters.
  $vars['comment_max_letters'] = t('Max @count letters', array('@count' => DSSOCIAL_CORE_COMMENT_MAX_LETTERS));
  // Submit text.
  $vars['comment_submit_text'] = t('Send comment');
  // User agreement.
  $commenting_rules = l(t('сommenting rules'), 'node/122');
  $vars['user_agreement'] = t("Thank you for your {$commenting_rules}, otherwise we reserve the right to delete your comment.");
}

/**
 * Preprocess view tags in bottom of page.
 */
function dssocial_preprocess_tags(&$vars) {
  $vars['tags'] = drupal_render($vars['category_name']['term_tid']);
}

/**
 * Preprocess view node teaser for dossier.
 */
function dssocial_preprocess_comment(&$vars) {
  global $user;
  static $indented;
  // Nested comments.
  if (isset($vars['comment']->divs)) {
    if ($vars['comment']->divs > 0) {
      $indented++;
    }
    else {
      $indented = 0;
    }

    if ($indented >= DSSOCIAL_CORE_COMMENT_REPLY_COUNT) {
      unset($vars['elements']['links']['comment']['#links']['comment-reply']);
    }
  }
  foreach ($vars['elements']['links']['comment']['#links'] as $comment_link) {
    $vars['comment_link'][] = '<li>' . l($comment_link['title'], $comment_link['href']) . '</li>';
  }
  if (isset($vars['comment_link'])) {
    $vars['comment_link'] = implode(' - ', $vars['comment_link']);
  }
    // User info.
  if (empty($vars['comment']->registered_name)) {
    // If anonymous.
    $vars['author'] = theme('image', array(
      'path' => DSSOCIAL_CORE_IMAGE_PATH . '/userpic-e.gif',
      'alt' => t('Anonymous'),
      )
    );
  }
  else {
    // If user.
    $user_comment = user_load($vars['comment']->uid);
    $profil = profile2_load_by_user($user_comment);

    if ($user_comment->uid == $user->uid) {
      $user_path = 'user/' . $vars['comment']->uid . '/profile_edit';
    }
    else {
      $user_path = 'user/' . $vars['comment']->uid;
    }

    $vars['author'] = l($vars['comment']->registered_name, $user_path);
    if (!empty($profil['main_profile']->field_information)) {
      $vars['user_information'] = $profil['main_profile']->field_information[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($profil['main_profile']->field_logo)) {
      $vars['user_logo'] = l(theme('image_style', array(
        'path' => $profil['main_profile']->field_logo[LANGUAGE_NONE][0]['uri'],
        'style_name' => 'user_comment_logo',
      )), $user_path, array('html' => TRUE));
    }
  }
  // Date comment.
  $vars['commment_post_date'] = dssocial_core_date_format($vars['comment']->created, 'd-m-y \a H\hi');
}

/**
 * Process variables for node--page-full.tpl.php
 *
 * @see node--page-full.tpl.php
 */
function dssocial_preprocess_node__page_full(&$vars) {
  $node = $vars['node'];
  $vars['title'] = dssocial_core_trim_title(($node->title), 150);
  if (!empty($node->field_body)) {
    $vars['body'] = $node->field_body[LANGUAGE_NONE][0]['value'];
  }
}

/**
 * Process variables for node--poll-full.tpl.php
 *
 * @see node--poll-full.tpl.php
 */
function dssocial_preprocess_node__poll_full(&$vars) {
  $node = $vars['node'];
  if (!empty($node->field_poll_title)) {
    $vars['title_poll'] = dssocial_core_trim_title(($node->field_poll_title[LANGUAGE_NONE][0]['value']), 50);
  }
  else {
    $vars['title_poll'] = dssocial_core_trim_title(($node->title), 50);
  }
}

/**
 * Process variables for node--poll-full.tpl.php
 *
 * @see node--poll-full.tpl.php
 */
function dssocial_preprocess_node__poll_teaser(&$vars) {
  $node = $vars['node'];
  $vars['title_link'] = $vars['title_link'] = l(
    (dssocial_core_trim_title(($node->title), 60)),
    "node/{$node->nid}", array(
      'attributes' => array(
        'class' => 'block-content-header2',
      ),
    )
  );

}

/**
 * Preprocess template emotion.tpl.php.
 */
function dssocial_preprocess_rate_template_emotion(&$vars) {
  $vars['is_like'] = FALSE;
  if (!empty($vars['results']['user_vote']) && $vars['results']['user_vote'] == 'like') {
    $vars['is_like'] = TRUE;
  }

  $vars['buttons'] = array();

  foreach ($vars['links'] as $link) {
    $button = theme('ds_rate_button', array(
      'text' => $link['text'],
      'href' => $link['href'],
      'class' => 'rate-emotion-btn',
      'votes' => $link['votes'],
      'is_like' => $vars['is_like'],
    ));
    $vars['buttons'][] = $button;
  }
}

/**
 * Process variables for html.tpl.php.
 *
 * @see html.tpl.php
 */

function dssocial_preprocess_html(&$variables) {
  global $base_url;
  global $user;
  // Ajax pages.
  if ($base_url == 'http://drupalsib.ru') {
    $variables['add_counters'] = TRUE;
  }
  if ($user->uid == 1) 
    $variables['classes_array'][] = 'admin-class';
}
