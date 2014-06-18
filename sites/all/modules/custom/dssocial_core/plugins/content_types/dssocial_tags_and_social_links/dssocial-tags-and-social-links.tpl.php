<?php
/**
 * @file
 * Tags and social button this theme.
 */
?>
<?php if (!empty($conf)): ?>
    <div id="ds_footer_social"<?php if ($conf['selected_type'] == DSSSOCIAL_TAGS_AND_SOCIAL_LINKS_BIG): ?><?php endif; ?>>
      <?php if (!empty($conf['left'])): ?>
        <?php print $conf['left']; ?>
      <?php endif; ?>
      <?php if (!empty($conf['right'])): ?>
        <?php print $conf['right']; ?>
      <?php endif; ?>
      <!-- AddThis Button BEGIN -->
      <div class="addthis_toolbox addthis_default_style addthis_32x32_style addthis_icon">
        <a class="addthis_button_vk"></a>
        <a class="addthis_button_twitter"></a>
        <a class="addthis_button_pinterest_share"></a>
        <a class="addthis_button_facebook"></a>
        <a class="addthis_button_pocket"></a>
        <a class="addthis_button_google_plusone_share"></a>
        <a class="addthis_button_compact"></a><a class="addthis_counter addthis_bubble_style"></a>
      </div>
      <script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-52a997d025ed041b"></script>
      <!-- AddThis Button END -->
    </div>
<?php endif; ?>
