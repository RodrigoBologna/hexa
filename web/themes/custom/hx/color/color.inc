<?php

/**
 * @file
 * Lists available colors and color schemes.
 */

/**
 * These colors are imported from Bootstrap (similar variables).
 *
 * @see _color.scss
 */
$header = '#e5e5e5';
$footer = '#f5f5f5';
$nav_item = '#777777';
$nav_item_footer = '#428bca';
$nav_bg = '#f8f8f8';
$active = '#555555';
$hover_bg = '#dddddd';
$dots = '#c7254e';
$dots_active = '#f9f2f4';
$shadow = '#eeeeee';
$bg = '#ffffff';
$text = '#333333';
$text_hover = '#333';

// $logo_url = theme_get_setting('logo.url', 'hx');
$logo_url = 'logo.svg';

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'header' => t('Header (region) - background'),
    'footer' => t('Footer (region) - background'),
    'nav_item' => t('Navigation (links)'),
    'nav_item_footer' => t('Navigation (links) - footer'),
    'nav_bg' => t('Navigation (region) - background'),
    'active' => t('Active (items)'),
    'hover_background' => t('Hover - background'),
    'dots' => t('Dots'),
    'dots_active' => t('Dots active'),
    'shadow' => t('Shadow (borders)'),
    'background' => t('Background (page)'),
    'text' => t('Text'),
    'text_hover' => t('Text (hover)'),
  ],
  'schemes' => [
    'default' => [
      'title' => t('Default'),
      'colors' => [
        'header' => $header,
        'footer' => $footer,
        'nav_item' => $nav_item,
        'nav_item_footer' => $nav_item_footer,
        'nav_bg' => $nav_bg,
        'active' => $active,
        'hover_background' => $hover_bg,
        'dots' => $dots,
        'dots_active' => $dots_active,
        'shadow' => $shadow,
        'background' => $bg,
        'text' => $text,
        'text_hover' => $text_hover,
      ],
    ],
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'css/color.css',
  ],

  // Files to copy.
  'copy' => [
    $logo_url,
  ],

  '#attached' => [
    'drupalSettings' => [
      'color' => [
        // Put the logo path into JavaScript for the live preview.
        'logo' => theme_get_setting('logo.url', 'hx'),
      ],
    ],
  ],
];
