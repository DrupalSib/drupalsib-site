<?php
/**
 * Тип вывода FIELDS во views dossier
 */
?>
<div class="block-item">
<?php print $fields['field_image']->content; ?>
<h4><?php print $fields['type']->content; ?></h4>
<span class="info"><?php print $fields['created']->label_html.$fields['created']->content; ?></span>
<h5><?php print $fields['title']->content; ?></h5>
<?php print $fields['body']->content; ?><!--
<?php// print $fields['field_tags']->content; ?>-->
</div>