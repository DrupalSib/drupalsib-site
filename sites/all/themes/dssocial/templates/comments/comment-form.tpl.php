<?php
/**
 * @file
 * comment-form.tpl.php Template comment.
 */
?>
<?php if (!empty($count_comments)): ?>
  <div id="ds_comment_ncounter">
    <div id="ds_comment_ncount">
      <?php print $count_comments; ?>
    </div>
  </div>
<?php endif; ?>
<div id="ds_comment_avatarbox">
  <?php if (empty($user->uid)): ?>
    <img src="/<?php print DSSOCIAL_CORE_IMAGE_PATH; ?>/userpic-e.gif" alt="" />
  <?php elseif (!empty($user_logo)): ?>
      <?php print $user_logo; ?>
  <?php endif; ?>
  <span>
    <strong>
      <div id="ds_comment_user">
        <?php print $user_name; ?>
      </div>
    </strong>
  </span>
</div>
<div id="ds_comment_maxchar"><h4><?php print $comment_max_letters; ?></h4></div>
<div id="ds_comment_formwrapper">
  <div id="ds_comment_textform">
   <div id="ds_comment_form">
    <form action="textarea1.php" method="post">
      <?php print drupal_render($form['comment_body']); ?>
      <div class="text_field_decor"></div>
      <?php if (!empty($user_agreement)): ?>
        <span class="ds_comment_desc"><?php print $user_agreement; ?></span>
      <?php endif; ?>
      <input type="submit" value="<?php print $comment_submit_text; ?>">
    </form>
    </div>
  </div>
</div>
<div style="display:none">
  <?php print drupal_render_children($form); ?>
</div>
