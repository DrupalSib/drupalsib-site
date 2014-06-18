<?php


class views_fb_like_plugin_display extends views_periodic_execution_plugin_display {

  var $node_nid_alias;

  function execute() {
    // Execute the view.
    $this->view->execute($this->display->id);

    // Update the FB like counts for those nodes
    $results = $this->view->result;

    $nodes = array();

    foreach ($results as $result) {
      $nodes[] = $result->{$this->node_nid_alias};
    }

    // Update those nodes.
    views_fb_like_update_nodes($nodes);

    // We don't use render:
    // Record that we were executed:
    if (empty($this->view->live_preview)) {
      $this->set_last_execution_time();
    }

    $this->tear_down();

  }

  function uses_exposed() {
    return FALSE;
  }

  function query() {
    $this->view->is_cacheable = FALSE;

    // Remove the existing sorts, and add on ours.
    $this->view->query->orderby = array();
    $this->view->query->add_orderby('views_fb_like', 'last_updated', 'ASC');
    $this->node_nid_alias = $this->view->query->add_field('node', 'nid');

  }
}