<?php
/**
 * @file
 * Displays templates article on the page of dossier.
 */
?>
<?php if (!empty($image)): ?>
  <div class="block-img">
    <?php print $image; ?>
  </div>
<?php endif; ?>
<?php if (!empty($content_category_name)): ?>
  <h4><?php print $content_category_name; ?></h4>
<?php endif; ?>
<?php if (!empty($article_created)): ?>
  <span class="info">
    <?php print t('By @created', array('@created' => $article_created)); ?>
  </span>
<?php endif; ?>
<?php if (!empty($title)): ?>
  <h5>
    <?php print $title; ?>
  </h5>
<?php endif; ?>
<?php if (!empty($author)): ?>
  <span class="from">
    <?php print $author;  ?>
  </span>
<?php endif; ?>
<?php if (!empty($description)): ?>
  <p>
    <?php print t($description); ?>
  </p>
<?php endif; ?>
<?php if (!empty($tags)): ?>
  <div class="ds_tags_teaser_article">
    <b><?php print t('Tags'); ?></b><?php print $tags; ?>
  </div>
<?php endif; ?>
