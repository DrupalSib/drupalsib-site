<?php
/**
 * @file
 * Template for a 2 column panel layout.
 */
?>
<div class="block-content-header">
  <h1><?php print $title; ?></h1>
  <?php if (!empty($tags)) : ?>
    <div class="block-motscles">
      <div class="block-for-motscles">
        <?php print t('tags :'); ?>
        <?php print $tags;?>
      </div>
    </div>
  <?php endif ?>
</div>
<div class="clear"></div>
<div id="ds_article_left">
  <div id="viewer-block">
    <?php if (!empty($image)) : ?>
    <div class="content">
      <?php print $image; ?>
      <p></p>
    </div>
  <?php endif; ?>
    <?php if (!empty($video)): ?>
      <?php print $video; ?>
    <?php endif ?>
    <?php if (!empty($slides)): ?>
    <div class="sep">
      <div class="sep-block">
        <?php print $previous; ?>
        <span class="sep-sur"><span id="currSlide"></span>&nbsp;<?php print t('sur'); ?>&nbsp;<span id="totalSlide"></span></span>
        <?php print $next; ?>
      </div>
      <div class="open-close-block">
        <?php print $close_block; ?>
        <span class="open close-sep"></span>
        <?php print $close_sep; ?>
      </div>
    </div>
    <?php print $top_next; ?>
    <?php print $top_prev; ?>
    <div id="deck-container" class="hide-description" >
      <?php foreach ($slides as $key => $uri): ?>
        <div id="nb<?php print $key; ?>" class="slide">
          <div class="media">
            <?php print $uri; ?>
              <div class="desc">
                <h3><?php print t('Carbomètre'); ?></h3>
              </div>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
      <div id="viewer-nav-bottom" class="gallery-block">
        <div class="image-container preview-image ">
          <ul class="disable-tips">
            <?php foreach ($diagramms as $key => $uri): ?>
              <li onclick="jQuery('#deck-container').cycle(<?php print $key; ?>)">
                <?php print $uri; ?>
              </li>
            <?php endforeach ?>
          </ul>
        </div>
      </div>
      <?php endif ?>
  </div>
  <?php if (!empty($description)): ?>
    <p><?php print t($description); ?></p>
  <?php endif; ?>
</div>
