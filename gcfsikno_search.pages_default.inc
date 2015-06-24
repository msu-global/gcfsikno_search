<?php
/**
 * @file
 * gcfsikno_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function gcfsikno_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = 'A page that displays a View of search results, which are generated via an exposed filter embedded in the search bar.';
  $page->path = 'search';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search__panel_context_ffeebbfb-778f-4ba5-a5f9-ce597f381077';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'spartan_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'GCFSI Knowledge Platform Search';
  $display->uuid = '49ac17a1-a1d0-445c-bc13-d64486e53f72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b3f8459f-d036-4f3b-a198-6fc7ee498e95';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'gcfsikno_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b3f8459f-d036-4f3b-a198-6fc7ee498e95';
    $display->content['new-b3f8459f-d036-4f3b-a198-6fc7ee498e95'] = $pane;
    $display->panels['left'][0] = 'new-b3f8459f-d036-4f3b-a198-6fc7ee498e95';
    $pane = new stdClass();
    $pane->pid = 'new-31a71468-bd86-4cd8-86ab-cf98fca6999f';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zDj51V96vHTNBMHdEAW4FyHkRRQ4dX9t';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '31a71468-bd86-4cd8-86ab-cf98fca6999f';
    $display->content['new-31a71468-bd86-4cd8-86ab-cf98fca6999f'] = $pane;
    $display->panels['right'][0] = 'new-31a71468-bd86-4cd8-86ab-cf98fca6999f';
    $pane = new stdClass();
    $pane->pid = 'new-7eaaadd0-ac04-44e5-a0e2-abf1df363c1c';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2iqH2FAiucuNSnIt77jytTSS327TIzZs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7eaaadd0-ac04-44e5-a0e2-abf1df363c1c';
    $display->content['new-7eaaadd0-ac04-44e5-a0e2-abf1df363c1c'] = $pane;
    $display->panels['right'][1] = 'new-7eaaadd0-ac04-44e5-a0e2-abf1df363c1c';
    $pane = new stdClass();
    $pane->pid = 'new-913d609e-850b-4925-a3e6-6751c568589f';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Aqyhn77ZCPByAHeNiHseVuNY1O6sSYQf';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '913d609e-850b-4925-a3e6-6751c568589f';
    $display->content['new-913d609e-850b-4925-a3e6-6751c568589f'] = $pane;
    $display->panels['right'][2] = 'new-913d609e-850b-4925-a3e6-6751c568589f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
