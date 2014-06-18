<?php
/**
 * @file
 * Article this theme.
 */
?>

<div id="ds_article_box">
  <h3><?php print $conf['title']; ?></h3>
</div>
<?php if (!empty($articles_also)): ?>
  <div id="ds_article_right_box">
  <?php foreach ($articles_also as $key => $article): ?>
    <div class="ds_box_img">
      <a href="<?php print $article['link'];?>">
        <?php if (!empty($article['image'])): ?>
          <?php print $article['image']; ?>
        <?php endif; ?>
        <div class="ds_artimg_desc">
          <div class="ds_artimg_text"><?php print $article['title'];?></div>
        </div>
      </a>
    </div>
  <?php endforeach; ?>
  </div>
<?php endif; ?>
