<?php

/**
 * Generic controller for entity-bases resources.
 */
class ServicesEntityResourceController implements ServicesResourceControllerInterface {

  /**
   * Implements ServicesResourceControllerInterface::access().
   */
  public function access($op, $args) {
    if ($op == 'index') {
      // Access is handled per-entity by index().
      return TRUE;
    }
    if ($op == 'create') {
      list($entity_type) = $args;
      // Pass the entity to the access control.
      return entity_access($op, $entity_type);
    }
    else {
      // Retrieve, Delete, Update.
      list($entity_type, $entity_id) = $args;

      $entity = entity_load_single($entity_type, $entity_id);

      // Pass the entity to the access control.
      return entity_access($op, $entity_type, $entity);
    }
  }

  /**
   * Implements ServicesResourceControllerInterface::create().
   */
  public function create($entity_type, array $values) {
    $entity = entity_create($entity_type, $values);
    if (!entity_save($entity_type, $entity)) {
      services_error('Error saving entity.', 406);
    }
    return $entity->id;
  }

  /**
   * Implements ServicesResourceControllerInterface::retrieve().
   */
  public function retrieve($entity_type, $entity_id, $fields) {
    $entity = entity_load_single($entity_type, $entity_id);
    if (!$entity) {
      services_error('Entity not found', 404);
    }
    return $this->limit_fields($entity, $fields);
  }

  /**
   * Implements ServicesResourceControllerInterface::update().
   */
  public function update($entity_type, $entity_id, array $values) {
    $entity = entity_metadata_wrapper($entity_type, (object) $values);
    if ($entity_id == $entity->getIdentifier()) {
      return $entity->save();
    }
    else {
      services_error('Invalid Entity Identifier. You can only update the entity referenced in the URL.', 406);
    }
  }

  /**
   * Implements ServicesResourceControllerInterface::delete().
   */
  public function delete($entity_type, $entity_id) {
    entity_delete($entity_type, $entity_id);
  }

  /**
   * Implements ServicesResourceControllerInterface::index().
   */
  public function index($entity_type, $fields, $parameters, $page, $pagesize, $sort, $direction) {
    // Make sure the pagesize is not too large.
    $max_pagesize = variable_get('services_entity_max_pagesize', 100);
    $pagesize = ($max_pagesize < $pagesize) ? $max_page_size : $pagesize;

    // Build an EFQ based on the arguments.
    $query = new EntityFieldQuery();
    $query
        ->entityCondition('entity_type', $entity_type)
        ->range($page * $pagesize, $pagesize);

    if (!empty($parameters)) {
      foreach ($parameters as $field => $value) {
        $this->propertyQueryOperation($entity_type, $query, 'Condition', $field, $value);
      }
    }
    if ($sort != '') {
      $direction = ($direction == 'DESC') ? 'DESC' : 'ASC'; // Ensure a valid direction
      $this->propertyQueryOperation($entity_type, $query, 'OrderBy', $sort, $direction);
    }

    $result = $query->execute();

    if (empty($result)) {
      return services_error(t('No entities found.'), 404);
    }
    // Convert to actual entities.
    $entities = entity_load($entity_type, array_keys($result[$entity_type]));

    foreach ($entities as $id => $entity) {
      if (entity_access('view', $entity_type, $entity)) {
        $return[] = $this->limit_fields($entity, $fields);
      }
    }

    return $return;
  }

  /**
   * Implements ServicesResourceControllerInterface::field().
   */
  public function field($entity_type, $entity_id, $field_name, $fields = '*', $raw = FALSE) {
    $entity = entity_load_single($entity_type, $entity_id);
    if (!$entity) {
      services_error('Entity not found', 404);
    }

    $wrapper = entity_metadata_wrapper($entity_type, $entity_id);
    if ($raw) {
      $return = $wrapper->{$field_name}->raw();
    }
    else {
      $return = $wrapper->{$field_name}->value();
    }

    $field = field_info_field($field_name);

    // Special handling for entityreference fields: run the new entities through
    // limit fields.
    if ($field['type'] == 'entityreference' && !$raw) {
      $entities = $return;
      $return = array();

      foreach ($entities as $id => $entity) {
        // The entity type here is the target type of the entityreference field.
        if (entity_access('view', $field['settings']['target_type'], $entity)) {
          $return[] = $this->limit_fields($entity, $fields);
        }
      }
    }

    return $return;
  }

  // Limit fields to the list provided.
  protected function limit_fields($entity, $fields) {
    if ($fields == '*') {
      return $entity;
    }
    $field_array = explode(',', $fields);
    foreach ($entity as $field => $value) {
      if (!in_array($field, $field_array)) {
        unset($entity->{$field});
      }
    }
    return $entity;
  }

  /**
   * Helper function which takes care of distinguishing between fields and
   * entity properties and executes the right EntityFieldQuery function for it.
   *
   * @param string $entity_type
   *   The EntityFieldQuery pointer which should be used.
   *
   * @param EntityFieldQuery $query
   *   The EntityFieldQuery pointer which should be used.
   *
   * @param string $operation
   *   The general function name, without the words 'property' or 'field'.
   *
   * @param string $property
   *   The property or field which should be used.
   *
   * @param string|array $value
   *   The value for the function.
   */
  protected function propertyQueryOperation($entity_type, EntityFieldQuery $query, $operation, $property, $value) {
    $properties = entity_get_all_property_info($entity_type);

    // If field is not set, then the filter is a property and we can extract
    // the schema field from the property array.
    if (empty($properties[$property]['field'])) {
      $column = $properties[$property]['schema field'];
      $operation = 'property' . $operation;
      $query->$operation($column, $value);
    }
    else {
      // For fields we need the field info to get the right column for the
      // query.
      $field_info = field_info_field($property);
      $operation = 'field' . $operation;
      if (is_array($value)) {
        // Specific column filters are given, so add a query condition for each
        // one of them.
        foreach ($value as $column => $val) {
          $query->$operation($field_info, $column, $val);
        }
      }
      else {
        // Just pick the first field column for the operation.
        $columns = array_keys($field_info['columns']);
        $column = $columns[0];
        $query->$operation($field_info, $column, $value);
      }
    }
  }

}
