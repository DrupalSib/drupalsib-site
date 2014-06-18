<?php

/**
 * @file
 * Default theme implementation to display voting form for a poll.
 *
 * - $choice: The radio buttons for the choices in the poll.
 * - $title: The title of the poll.
 * - $block: True if this is being displayed as a block.
 * - $vote: The vote button
 * - $rest: Anything else in the form that may have been added via
 *   form_alter hooks.
 *
 * @see template_preprocess_poll_vote()
 */
hide($content['field_section']);
$votes = '';
?>
<?php foreach ($choice as $chvote) : ?>
  <?php $votes += (int) $chvote['chvotes']; ?>
<?php endforeach; ?>
<div class="block-content-header">
  <h1><?php print $title_poll; ?></h1>
  <div class="block-motscles">
    <div class="block-for-motscles"></div>
  </div>
</div>
<div class="content-left">
  <?php if (!empty($content['field_image']) && (!isset($field_image[0]['is_default']))) : ?>
    <div class="content">
      <?php print render($content['field_image']); ?>
      <p></p>
    </div>
  <?php endif; ?>
  <div class="actions-list-vote">
    <input id="current-rubric" type="hidden" value="">
  </div>
  <div class="poll">
    <div class="poll-list-item item-with-image">
      <div class="block-poll-result block-poll-result-nbb">
        <div class="comment-title-wrapper">
          <h2 class="comments"><?php print t('Result'); ?></h2>
        </div>
        <h3><?php print t('Survey : @title', array('@title' => $title)); ?></h3>
        <ul>
          <?php if (isset($content['poll_view_results'])) : ?>
            <?php print render($content['poll_view_results']); ?>
          <?php else : ?>
            <?php print render($content['poll_view_voting']); ?>
          <?php endif; ?>
        </ul>
        <div class="results-count"><?php print t('number of votes : @votes', array('@votes' => $votes)); ?></div>
      </div>
    </div>
  </div>
</div>
