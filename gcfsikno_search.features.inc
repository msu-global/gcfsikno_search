<?php
/**
 * @file
 * gcfsikno_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gcfsikno_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gcfsikno_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function gcfsikno_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default Node Index",
    "machine_name" : "default_node_index",
    "description" : "The default index that contains all nodes on the site.",
    "server" : "local_database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "200",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_copyright" : { "type" : "text" },
        "field_document_author" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_related_event" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_related_project" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "taxonomy_forums" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "blog" : "blog",
              "event" : "event",
              "forum" : "forum",
              "biblio" : "biblio"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "type" : true, "title" : true, "field_copyright" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "type" : true, "title" : true, "field_copyright" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "type" : true, "title" : true, "field_copyright" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "type" : true, "title" : true, "field_copyright" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "type" : true, "title" : true, "field_copyright" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function gcfsikno_search_default_search_api_server() {
  $items = array();
  $items['local_database'] = entity_import('search_api_server', '{
    "name" : "Local Database",
    "machine_name" : "local_database",
    "description" : "A search server that resides on the local database.  Meant to be used as a simple server, where high performance and advanced features are not needed.  Does not index within files.",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_document_author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_document_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_default_node_index_field_categories",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "taxonomy_forums" : {
            "table" : "search_api_db_default_node_index",
            "column" : "taxonomy_forums",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_related_event" : {
            "table" : "search_api_db_default_node_index_field_related_event",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_default_node_index_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_related_project" : {
            "table" : "search_api_db_default_node_index_field_related_project",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_copyright" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
