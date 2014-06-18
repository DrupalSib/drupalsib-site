<?php
/**
 * @file
 * Template for asset form.
 */
?>
<?php if (!empty($title)): ?>
  <div id='page-title'>
    <div class='limiter clearfix'>
      <h1 class='page-title<?php if (!empty($page_icon_class)) { print ' ' . $page_icon_class; } ?>'>
        <?php if (!empty($page_icon_class)): ?>
          <span class='icon'></span>
        <?php endif; ?>
        <?php print $title; ?>
      </h1>
    </div>
  </div>
<?php endif; ?>

<?php if ($show_messages && $messages): ?>
  <div id='console'>
    <div class='limiter clearfix'>
      <?php print $messages; ?>
    </div>
  </div>
<?php endif; ?>

<div id='page'>
  <div id='main-content' class='limiter clearfix'>
    <?php if (!empty($page['help'])): ?>
      <?php print render($page['help']); ?>
    <?php endif; ?>

    <div id='content' class='page-content clearfix'>
      <?php if (!empty($page['content'])): ?>
        <?php print render($page['content']); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
