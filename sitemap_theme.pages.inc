<?php

function _sitemap_theme_page()
{
    $items = array();
    $menu = menu_tree('main-menu');

    foreach ($menu as $key => $item) {
        if ((int)$key > 0) {
            $items[$key] = array(
                'title' => $item['#title'],
                'url' => url($item['#href']),
            );
            if (!empty($item['#below'])) {
                $children = array();
                foreach ($item['#below'] as $k => $child) {
                    if ((int)$k > 0) {
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

    return theme('theme_sitemap_page', array(
        'items' => $items
    ));
}