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
  if ($module == "strongarm" && $api == "strongarm") {
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
  $items['gcfsikno_node'] = entity_import('search_api_index', '{
    "name" : "GCFSI Knowledge Platform Node Index",
    "machine_name" : "gcfsikno_node",
    "description" : "This index walks through all of the nodes on the site, to make their contents available to the search engine.  Nodes could be blog posts, forum posts, or library resources.\\r\\n\\r\\nAn important thing to consider, is that  some entities are NOT nodes.  Users, flaggings, messages, and other entity types are not captured by this index.",
    "server" : "gcfsikno_database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:field_user_bio" : { "type" : "text", "boost" : "0.5" },
        "author:name" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "field_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "taxonomy_forums" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "taxonomy_forums:name" : { "type" : "text", "boost" : "0.8" },
        "title" : { "type" : "text", "boost" : "5.0" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "author:name" : true,
              "author:field_user_bio" : true,
              "body:value" : true,
              "body:summary" : true,
              "taxonomy_forums:name" : true,
              "field_categories:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "body:value" : true,
              "body:summary" : true,
              "taxonomy_forums:name" : true,
              "field_categories:name" : true
            },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "author:name" : true,
              "author:field_user_bio" : true,
              "body:value" : true,
              "body:summary" : true,
              "taxonomy_forums:name" : true,
              "field_categories:name" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "author:name" : true,
              "author:field_user_bio" : true,
              "body:value" : true,
              "body:summary" : true,
              "taxonomy_forums:name" : true,
              "field_categories:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "author:name" : true,
              "author:field_user_bio" : true,
              "body:value" : true,
              "body:summary" : true,
              "taxonomy_forums:name" : true,
              "field_categories:name" : true
            },
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
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function gcfsikno_search_default_search_api_server() {
  $items = array();
  $items['gcfsikno_database'] = entity_import('search_api_server', '{
    "name" : "GCFSI Knowledge Platform Local Database",
    "machine_name" : "gcfsikno_database",
    "description" : "The default database search server.  This server operates on the Drupal database itself, for simplicity and ease of installation.  At a later time, this server can be replaced by an Apache SOLR backend, to increase performance, and allow searching through binary formats, such as documents.\\r\\n\\r\\nTo improve performance, this server only indexes words 3 characters or above, and can search on parts of a word.",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "gcfsikno_node" : {
          "title" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_gcfsikno_node",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "author:name" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "author:field_user_bio" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "body:value" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "taxonomy_forums:name" : {
            "table" : "search_api_db_gcfsikno_node_text",
            "type" : "text",
            "boost" : "0.8"
          },
          "field_categories" : {
            "table" : "search_api_db_gcfsikno_node_field_categories",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_gcfsikno_node",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "taxonomy_forums" : {
            "table" : "search_api_db_gcfsikno_node",
            "column" : "taxonomy_forums",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
