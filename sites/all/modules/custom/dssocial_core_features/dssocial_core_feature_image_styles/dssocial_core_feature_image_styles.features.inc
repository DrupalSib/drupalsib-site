<?php
/**
 * @file
 * dssocial_core_feature_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function dssocial_core_feature_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: article_dossier_view.
  $styles['article_dossier_view'] = array(
    'name' => 'article_dossier_view',
    'effects' => array(
      21 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '208',
          'height' => '128',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: article_image_full.
  $styles['article_image_full'] = array(
    'name' => 'article_image_full',
    'effects' => array(
      55 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '464',
          'height' => '288',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: article_image_teaser.
  $styles['article_image_teaser'] = array(
    'name' => 'article_image_teaser',
    'effects' => array(
      54 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '208',
          'height' => '128',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: articles_image.
  $styles['articles_image'] = array(
    'name' => 'articles_image',
    'effects' => array(
      52 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '208',
          'height' => '128',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: author_avatar.
  $styles['author_avatar'] = array(
    'name' => 'author_avatar',
    'effects' => array(
      28 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '32',
          'height' => '32',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: author_image.
  $styles['author_image'] = array(
    'name' => 'author_image',
    'effects' => array(
      51 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '50',
          'height' => '50',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: author_info.
  $styles['author_info'] = array(
    'name' => 'author_info',
    'effects' => array(
      30 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '100',
          'height' => '100',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: dossier_image_teaser.
  $styles['dossier_image_teaser'] = array(
    'name' => 'dossier_image_teaser',
    'effects' => array(
      56 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '208',
          'height' => '128',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: headline_view_teaser.
  $styles['headline_view_teaser'] = array(
    'name' => 'headline_view_teaser',
    'effects' => array(
      46 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '222',
          'height' => '280',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: image_diagramma_small.
  $styles['image_diagramma_small'] = array(
    'name' => 'image_diagramma_small',
    'effects' => array(
      36 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '77',
          'height' => '48',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: login_img.
  $styles['login_img'] = array(
    'name' => 'login_img',
    'effects' => array(
      38 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '24',
          'height' => '24',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: poll_image.
  $styles['poll_image'] = array(
    'name' => 'poll_image',
    'effects' => array(
      53 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '208',
          'height' => '128',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: poll_image_full.
  $styles['poll_image_full'] = array(
    'name' => 'poll_image_full',
    'effects' => array(
      57 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '464',
          'height' => '288',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: poll_image_teaser.
  $styles['poll_image_teaser'] = array(
    'name' => 'poll_image_teaser',
    'effects' => array(
      58 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '208',
          'height' => '128',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: slider_list_view.
  $styles['slider_list_view'] = array(
    'name' => 'slider_list_view',
    'effects' => array(
      49 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '704',
          'height' => '305',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: user_comment_logo.
  $styles['user_comment_logo'] = array(
    'name' => 'user_comment_logo',
    'effects' => array(
      43 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '32',
          'height' => '32',
          'upscale' => 1,
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}
