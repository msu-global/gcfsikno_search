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
  $page->admin_description = 'The search results page.';
  $page->path = 'search';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search__panel_context_4732c350-4677-49eb-a7d8-a06cafb8c3d4';
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
  $display->title = 'Search';
  $display->uuid = '368d66e5-5372-46ad-a513-be8595dc8132';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-95fdafe2-5685-45b9-a54a-d0b8f6831f5b';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'search-panel_pane_1';
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
    $pane->uuid = '95fdafe2-5685-45b9-a54a-d0b8f6831f5b';
    $display->content['new-95fdafe2-5685-45b9-a54a-d0b8f6831f5b'] = $pane;
    $display->panels['left'][0] = 'new-95fdafe2-5685-45b9-a54a-d0b8f6831f5b';
    $pane = new stdClass();
    $pane->pid = 'new-d71a5bbd-8a52-4506-842c-fb7bbd36834b';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-nX7OckzG8ZuopQWtdC7zOIap6bK7v15R';
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
    $pane->uuid = 'd71a5bbd-8a52-4506-842c-fb7bbd36834b';
    $display->content['new-d71a5bbd-8a52-4506-842c-fb7bbd36834b'] = $pane;
    $display->panels['right'][0] = 'new-d71a5bbd-8a52-4506-842c-fb7bbd36834b';
    $pane = new stdClass();
    $pane->pid = 'new-3e353f6d-0775-4ec1-ac1b-8231f6f923de';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zIH8EsYFkvWKeMtTZTGLEm1GrYlAarmk';
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
    $pane->uuid = '3e353f6d-0775-4ec1-ac1b-8231f6f923de';
    $display->content['new-3e353f6d-0775-4ec1-ac1b-8231f6f923de'] = $pane;
    $display->panels['right'][1] = 'new-3e353f6d-0775-4ec1-ac1b-8231f6f923de';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-95fdafe2-5685-45b9-a54a-d0b8f6831f5b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
