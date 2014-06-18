<?php
/**
 * @file
 * Template comment.
 */
?>
<div id="ds_comment_block">
  <div class="ds_comment_top">
    <div class="ds_comment_image">
      <?php if (!empty($user_logo)): ?>
        <?php print $user_logo; ?>
      <?php endif; ?>
      <span class="ds_comment_title">
        <?php if (!empty($author)): ?> 
          <?php print $author; ?>
        <?php endif; ?>
        <span class="ds_comment_ratespacer">/</span>
        <span class="ds_comment_ratespacer"><?php print $commment_post_date; ?></span>
      </span>
      <?php if (!empty($comment->comment_body[LANGUAGE_NONE][0]['value'])): ?>
        <span class="ds_comment_post"><?php print $comment->comment_body[LANGUAGE_NONE][0]['value']; ?></span>
      <?php endif; ?>
    </div>
  </div>
  <div class="clear"></div>
  <div id="ds_comment_bot">
    <span id="ds_comment_rateL">
      <ul class="links inline">
        <?php if (!empty($comment_link)): ?>
          <?php print $comment_link; ?>
        <?php endif; ?>
      </ul>
    </span>
    <span id="ds_comment_rateR">
    </span>
  </div>
  <?php if (!empty($content['rate_comments']['#markup'])) : ?>
    <?php print $content['rate_comments']['#markup']; ?>
  <?php endif; ?>
</div>
<div style="display:none">
  <?php print drupal_render_children($elements); ?>
</div>
