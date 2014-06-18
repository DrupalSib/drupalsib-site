<?php
/**
 * @file
 * Default theme implementation for assets.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) asset label.
 * - $url: Direct url of the current asset if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-asset
 *   - {asset}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_preprocess_asset()
 * @see template_process()
 */
?>
<?php if (!$page): ?>
  <strong <?php print $title_attributes; ?>>
    <?php print $title; ?>
  </strong>
<?php endif; ?>

<div class="content"<?php print $content_attributes; ?>>
  <?php print render($content); ?>
</div>
