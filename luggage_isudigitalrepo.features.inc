<?php
/**
 * @file
 * luggage_isudigitalrepo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_isudigitalrepo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "plugins") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function luggage_isudigitalrepo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function luggage_isudigitalrepo_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
