<?php
/**
 * @file
 * devudo_servers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function devudo_servers_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_config|node|server|form';
  $field_group->group_name = 'group_config';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'server';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Configuration',
    'weight' => '11',
    'children' => array(
      0 => 'field_rackspace_id',
      1 => 'field_attr_newrelic_license',
      2 => 'field_attr_php_memory_limit',
      3 => 'field_attr_php_version',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_config|node|server|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|server|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'server';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '3',
    'children' => array(
      0 => 'group_settings',
      1 => 'group_share',
      2 => 'group_config',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_group|node|server|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_settings|node|server|form';
  $field_group->group_name = 'group_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'server';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Server Options',
    'weight' => '10',
    'children' => array(
      0 => 'field_rackspace_flavor',
      1 => 'field_services',
      2 => 'field_devshop',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_settings|node|server|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share|node|server|form';
  $field_group->group_name = 'group_share';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'server';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Share',
    'weight' => '12',
    'children' => array(
      0 => 'field_server_users',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_share|node|server|form'] = $field_group;

  return $export;
}
