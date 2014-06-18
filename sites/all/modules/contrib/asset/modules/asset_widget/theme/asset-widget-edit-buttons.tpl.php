<?php
/**
 * @file
 * Template for asset widget edit buttons
 */
 ?>
<?php if (!empty($preview_link) || !empty($edit_link)): ?>
  <div class="buttons buttons-2<?php if (empty($preview_link) || empty($edit_link)) print ' button-single'; ?>">
    <?php if (!empty($preview_link)): ?>
      <div class="button button-afficher button-preview button-ico">
        <?php print $preview_link; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($edit_link)): ?>
      <div class="button button-modifier button-ico">
        <?php print $edit_link; ?>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
