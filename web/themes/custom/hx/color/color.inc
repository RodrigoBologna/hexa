<?php

/**
 * @file
 * Lists available colors and color schemes.
 */

$header = '#111111';
$footer = '#f51167';
$shadow = '#dadce0';
$hover = '#f51144';
$hover_background = '#f0e9e9';
$background = '#ffffff';
$text = '#000000';

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'header' => t('Header'),
    'footer' => t('Footer'),
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
        'shadow' => $shadow,
        'hover' => $hover,
        'hover_background' => $hover_background,
        'background' => $background,
        'text' => $text,
      ],
    ],
    'red' => [
      'title' => t('Dark red'),
      'colors' => [
        'header' => '#a20f0f',
        'footer' => '#e54237',
        'shadow' => $shadow,
        'hover' => '#e54237',
        'hover_background' => $background,
        'background' => $text,
        'text' => $background,
      ]
    ],
    'green' => [
      'title' => t('Dark green'),
      'colors' => [
        'header' => '#296315',
        'footer' => '#40c312',
        'shadow' => $shadow,
        'hover' => '#40c312',
        'hover_background' => $background,
        'background' => $text,
        'text' => $background,
      ]
    ],
    'blue' => [
      'title' => t('Dark blue'),
      'colors' => [
        'header' => '#0f0fa2',
        'footer' => '#13c7bb',
        'shadow' => $shadow,
        'hover' => '#13c7bb',
        'hover_background' => $background,
        'background' => $text,
        'text' => $background,
      ]
    ]
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'css/colors.css',
  ],

  // Files to copy.
  'copy' => [
    theme_get_setting('logo.url', 'hx'),
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
