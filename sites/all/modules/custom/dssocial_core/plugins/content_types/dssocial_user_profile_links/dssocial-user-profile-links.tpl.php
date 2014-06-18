<?php
/**
 * @file
 * User profile links.
 */
?>
<div class="block-profil-links">
  <div class="block-links">
    <div class="item-list">
      <ul class="actions-list">
        <li class="item-editer">
          <?php if (!empty($link)): ?>
            <?php print $link; ?>
          <?php endif; ?>
        </li>
      </ul>
    </div>
  </div>
</div>
