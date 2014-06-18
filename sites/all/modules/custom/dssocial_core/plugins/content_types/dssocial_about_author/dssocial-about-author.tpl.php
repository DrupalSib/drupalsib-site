<?php

/**
 * @file
 * About the author.
 */
?>
<?php if (!empty($vars['user_information'])): ?>
  <div id="ds_article_box">
    <h3>
      <?php print t('About the author'); ?>
    </h3>
  </div>
  <div id="ds_author_box">
    <?php $information = $vars['user_information']; $logo = $vars['user_logo']; $name = $vars['name']; $about_user_articles = $vars['about_user_articles']; ?>
    <span class="ds_author_name">
      <?php if(!empty($logo)): ?>
        <?php print $logo ?>
      <?php endif; ?>
        <?php print $name ?>
    </span>
    <div class="ds_author_desc">
      <?php print $information; ?>
    </div>
    <?php if(!empty($about_user_articles)): ?>
      <div class="ds_author_link">
        <?php print $about_user_articles; ?>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
