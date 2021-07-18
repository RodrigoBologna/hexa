#!/bin/bash
## Description: Run the initial setup.

cd /var/www/html/

# Install the Composer packages.
composer install

cd web/themes/custom/hx

# Install the theme dependencies.
if [ -d "node_modules" ]; then
  exit 0
fi

npm install gulp \
  gulp-cli \
  gulp-autoprefixer \
  gulp-beautify \
  gulp-eslint \
  gulp-imagemin \
  gulp-if \
  gulp-jshint \
  gulp-livereload \
  gulp-load-plugins \
  gulp-notify \
  gulp-sass \
  gulp-sourcemaps \
  gulp-uglify \
  imagemin-pngquant \
  jshint-stylish
npm audit fix
