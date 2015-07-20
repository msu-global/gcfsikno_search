<?php
/**
 * @file
 * gcfsikno_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function gcfsikno_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'gcfsikno_node' => array(
      'search_api_views:gcfsikno_search:page' => 'search_api_views:gcfsikno_search:page',
      'search_api_views:gcfsikno_search:panel_pane_1' => 'search_api_views:gcfsikno_search:panel_pane_1',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_compression_type';
  $strongarm->value = 'minified';
  $export['select2_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_disable_jq_version_check';
  $strongarm->value = 0;
  $export['select2_disable_jq_version_check'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_excluded_cleasses';
  $strongarm->value = '';
  $export['select2_excluded_cleasses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_excluded_ids';
  $strongarm->value = '';
  $export['select2_excluded_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_excluded_selectors';
  $strongarm->value = '';
  $export['select2_excluded_selectors'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_min_options_count_for_search';
  $strongarm->value = '6';
  $export['select2_min_options_count_for_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_update_settings_by_ajax';
  $strongarm->value = 0;
  $export['select2_update_settings_by_ajax'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_use_for_ac_elements';
  $strongarm->value = 0;
  $export['select2_use_for_ac_elements'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_use_for_all_select_elements';
  $strongarm->value = 1;
  $export['select2_use_for_all_select_elements'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'select2_use_for_all_select_elements_for_admin_pages';
  $strongarm->value = 0;
  $export['select2_use_for_all_select_elements_for_admin_pages'] = $strongarm;

  return $export;
}
