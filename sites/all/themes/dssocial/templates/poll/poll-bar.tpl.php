<?php
/**
 * @file
 * Default theme implementation to display the bar for a single choice in a
 * poll.
 *
 * Variables available:
 * - $title: The title of the poll.
 * - $votes: The number of votes for this choice
 * - $total_votes: The number of votes for this choice
 * - $percentage: The percentage of votes for this choice.
 * - $vote: The choice number of the current user's vote.
 * - $voted: Set to TRUE if the user voted for this choice.
 *
 * @see template_preprocess_poll_bar()
 */
?>
<li>
  <span class="title"><?php print $title; ?></span>
  <span class="scale">
    <img width="<?php print $percentage; ?>%" height="8" src="/<?php print DSSOCIAL_CORE_IMAGE_PATH; ?>/spacer.gif" alt="">
    <span class="result-text"><?php print $percentage; ?>%</span>
  </span>
</li>
