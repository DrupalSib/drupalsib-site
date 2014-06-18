<?php

/**
 * @file
 * Operations with files for DCQ module.
 */

define('DCQ_DRUPAL_PATH', realpath(drupal_get_path('module', 'node') . '/../..'));
define('DCQ_GIT_HOOKS_PATH', DCQ_DRUPAL_PATH . '/.git/hooks');
define('DCQ_RUN_SCRIPT_NAME', 'pre-commit');
define('DCQ_CHECK_SCRIPT_NAME', 'pre-commit_dcq');


/**
 * This function try to copy scripts files.
 */
function dcq_install_scripts() {
  // Installation check scripts.
  if (is_writable(DCQ_GIT_HOOKS_PATH)) {
    // Delete old files.
    if (file_exists(DCQ_GIT_HOOKS_PATH . '/' . DCQ_RUN_SCRIPT_NAME)) {
      unlink(file_exists(DCQ_GIT_HOOKS_PATH . '/' . DCQ_RUN_SCRIPT_NAME));
    }

    if (file_exists(DCQ_GIT_HOOKS_PATH . '/' . DCQ_CHECK_SCRIPT_NAME)) {
      unlink(file_exists(DCQ_GIT_HOOKS_PATH . '/' . DCQ_CHECK_SCRIPT_NAME));
    }

    // Copy new files.
    if (copy(__DIR__ . '/' . DCQ_RUN_SCRIPT_NAME, DCQ_GIT_HOOKS_PATH . '/' . DCQ_RUN_SCRIPT_NAME)
        && copy(__DIR__ . '/' . DCQ_CHECK_SCRIPT_NAME, DCQ_GIT_HOOKS_PATH . '/' . DCQ_CHECK_SCRIPT_NAME)) {
      chmod(DCQ_GIT_HOOKS_PATH . '/' . DCQ_RUN_SCRIPT_NAME, 0755);
      chmod(DCQ_GIT_HOOKS_PATH . '/' . DCQ_CHECK_SCRIPT_NAME, 0755);
      drupal_set_message(t('DCQ has been installed successfully.'));
    }
  }
  else {
    drupal_set_message(
      t(
        'DCQ: !dir is not writable. You should allow write permissions for your www-data
        user or copy !file1 and !file2 files from DCQ module directory into !dir
        and allow execute permissions manually.',
        array(
          '!dir' => DCQ_GIT_HOOKS_PATH,
          '!file1' => DCQ_RUN_SCRIPT_NAME,
          '!file2' => DCQ_CHECK_SCRIPT_NAME,
        )
      ),
      'error'
    );
  }
}
