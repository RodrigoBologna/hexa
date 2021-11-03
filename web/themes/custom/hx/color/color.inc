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
$nav_bg = '#f8f8f8';
$active = '#555555';
$hover = '#222222';
$hover_bg = '#dddddd';
$dots = '#c7254e';
$dots_active = '#f9f2f4';
$shadow = '#eeeeee';
$bg = '#ffffff';
$text = '#333333';

$logo_url = theme_get_setting('logo.url', 'hx');

//if (empty($logo_url)) {
  $logo_url = 'logo.svg';
//}

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'header' => t('Header'),
    'footer' => t('Footer'),
    'nav' => t('Navigation'),
    'nav_bg' => t('Navigation background'),
    'active' => t('Active'),
    'dots' => t('Dots'),
    'dots_active' => t('Dots active'),
    'shadow' => t('Shadow'),
    'hover' => t('Hover'),
    'hover_background' => t('Hover background'),
    'background' => t('Background'),
    'text' => t('Text'),
  ],
  'schemes' => [
    'default' => [
      'title' => t('Default'),
      'colors' => [
        'header' => $header,
        'footer' => $footer,
        'nav' => $nav_item,
        'nav_bg' => $nav_bg,
        'active' => $active,
        'dots' => $dots,
        'dots_active' => $dots_active,
        'shadow' => $shadow,
        'hover' => $hover,
        'hover_background' => $hover_bg,
        'background' => $bg,
        'text' => $text,
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
