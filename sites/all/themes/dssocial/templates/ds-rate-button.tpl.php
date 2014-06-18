<?php
/**
 * @file
 * Template rate button.
 * $is_like -> if user already liked.
 * $votes -> count votes for this content.
 * Use get_defined_vars() for get all variables.
 */
?>
<ul class="actions-list">
  <li class="item-favor item-favor-txt">
    <?php if (!empty($is_like) || user_is_anonymous()): ?>
      <a><span class="act"><?php print $votes; ?></span><span><?php print t('like'); ?></span></a>
    <?php else: ?>
      <a href="<?php print $href; ?>"><span class="act"><?php print t('like'); ?></span><span><?php print t('like'); ?></span></a>
    <?php endif; ?>
  </li>
</ul>
