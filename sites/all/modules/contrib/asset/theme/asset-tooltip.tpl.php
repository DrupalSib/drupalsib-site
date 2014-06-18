<?php
/**
 * @file
 * Default theme implementation to display an asset tooltip in the overlay.
 *
 * @see template_preprocess()
 * @see template_process_asset_tooltip()
 * @see template_process()
 */
?>
<div class="tooltip-iframe-body-element">
  <div class="tooltip-iframe-elements">
    <?php print render($page['content']); ?>
  </div>
</div>
