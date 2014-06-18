<?php
/**
 * @file
 * Article this theme.
 */
?>
<div id="ds_article_box">
  <h3><?php print $conf['title']; ?></h3>
</div>
<?php  ?>
<?php if (!empty($poll_also)): ?>
  <div id="ds_article_right_box">
  <?php foreach ($poll_also as $key => $poll): ?>
    <div class="ds_box_img">
      <a href="<?php print $poll['link'];?>">
        <?php if (!empty($poll['image'])): ?>
          <?php print $poll['image']; ?>
        <?php endif; ?>
        <div class="ds_artimg_desc">
          <div class="ds_artimg_text"><?php print $poll['title'];?></div>
        </div>
      </a>
    </div>
  <?php endforeach; ?>
  </div>
<?php endif; ?>
