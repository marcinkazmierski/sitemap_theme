<?php

/**
 * Callback function.
 */
function _sitemap_theme_page()
{
    $items = array();
    $menu = menu_tree('main-menu'); //TODO: configurable in admin

    if (!empty($menu)) {
        foreach ($menu as $key => $item) { // TODO: recursion function
            if ((int)$key > 0 && !empty($item['#title']) && !empty($item['#title'])) {
                $items[$key] = array(
                    'title' => $item['#title'],
                    'url' => url($item['#href']),
                );
                if (!empty($item['#below'])) {
                    $children = array();
                    foreach ($item['#below'] as $k => $child) {
                        if ((int)$k > 0 && !empty($child['#title']) && !empty($child['#title'])) {
                            $children[$k] = array(
                                'title' => $child['#title'],
                                'url' => url($child['#href']),
                            );
                        }
                    }
                    $items[$key]['children'] = $children;
                }
            }
        }
    }

    return theme('theme_sitemap_page', array(
        'items' => $items
    ));
}