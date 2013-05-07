<?php
/**
 * @file
 * devudo_servers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function devudo_servers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function devudo_servers_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function devudo_servers_node_info() {
  $items = array(
    'server' => array(
      'name' => t('Server'),
      'base' => 'node_content',
      'description' => t('A DevShop server.'),
      'has_title' => '1',
      'title_label' => t('Server Name'),
      'help' => '',
    ),
  );
  return $items;
}
