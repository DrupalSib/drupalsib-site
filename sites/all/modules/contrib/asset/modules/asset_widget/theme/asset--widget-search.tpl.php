<?php
/**
 * @file
 * asset--widget-search.tpl.php
 *
 * Template for asset in widget-search view mode.
 */
?>
<div class="item-inner">
  <div class="pic tooltip-call <?php print "$asset->type order-$asset->aid"; ?>">
    <?php if (!empty($media_field)): ?>
      <?php print render($media_field); ?>
    <?php else: ?>
      <span class="placeholder"></span>
    <?php endif; ?>
    <span class="ico"></span>
  </div>

  <div class="title">
    <?php print $title; ?>
  </div>

  <?php if (!empty($short_copyright)): ?>
    <div class="descrip">
      <?php print render($short_copyright); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($short_description)): ?>
    <div class="descrip">
      <?php print render($short_description); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($view_mode_switch)): ?>
    <?php print $view_mode_switch; ?>
  <?php endif; ?>

</div>
<?php print $buttons; ?>
