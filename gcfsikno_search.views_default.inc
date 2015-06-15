<?php
/**
 * @file
 * gcfsikno_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gcfsikno_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gcfsikno_search';
  $view->description = 'This View displays a page of search results, and provides an exposed filter as a block that can be used as a search bar.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_gcfsikno_node';
  $view->human_name = 'Search Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'well well-sm';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['element_type'] = 'em';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_categories_name']['id'] = 'field_categories_name';
  $handler->display->display_options['fields']['field_categories_name']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['fields']['field_categories_name']['field'] = 'field_categories_name';
  $handler->display->display_options['fields']['field_categories_name']['label'] = '';
  $handler->display->display_options['fields']['field_categories_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories_name']['hide_empty'] = TRUE;
  /* Field: Indexed Node: Forums */
  $handler->display->display_options['fields']['taxonomy_forums']['id'] = 'taxonomy_forums';
  $handler->display->display_options['fields']['taxonomy_forums']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['fields']['taxonomy_forums']['field'] = 'taxonomy_forums';
  $handler->display->display_options['fields']['taxonomy_forums']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_forums']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_forums']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_forums']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['taxonomy_forums']['view_mode'] = 'full';
  $handler->display->display_options['fields']['taxonomy_forums']['bypass_access'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_gcfsikno_node';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    5 => 0,
    7 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['link_url'] = 'search';
  $handler->display->display_options['exposed_block'] = TRUE;
  $export['gcfsikno_search'] = $view;

  return $export;
}
