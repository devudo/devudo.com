<?php
/**
 * @file
 * devudo_connect.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function devudo_connect_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "oauthconnector" && $api == "") {
    return array("version" => "");
  }
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}
