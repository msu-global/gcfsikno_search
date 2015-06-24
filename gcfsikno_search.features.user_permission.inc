<?php
/**
 * @file
 * gcfsikno_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gcfsikno_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(),
    'module' => 'search_api',
  );

  // Exported permission: 'administer select2'.
  $permissions['administer select2'] = array(
    'name' => 'administer select2',
    'roles' => array(),
    'module' => 'select2',
  );

  return $permissions;
}
