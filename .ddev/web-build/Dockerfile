ARG BASE_IMAGE
FROM $BASE_IMAGE

# NVM
ENV NVM_DIR=/usr/local/nvm
ENV NODE_DEFAULT_VERSION=v16.4.0
RUN curl -sL https://raw.githubusercontent.com/nvm-sh/nvm/v0.38.0/install.sh -o install_nvm.sh
RUN mkdir -p $NVM_DIR && bash install_nvm.sh
RUN echo "source $NVM_DIR/nvm.sh" >>/etc/profile
RUN bash -ic "nvm install $NODE_DEFAULT_VERSION && nvm use $NODE_DEFAULT_VERSION"
RUN chmod -R ugo+w $NVM_DIR

# PNGQUANT & JPEGOPTIM
RUN apt -y update
RUN apt -y install pngquant
RUN apt -y install jpegoptim

# JSMIN & IMAGEMAGICK
RUN apt -y install libcurl3-openssl-dev
RUN apt -y install php7.4-dev
RUN apt -y install php7.4-imagick
RUN apt -y install php-pear
RUN pecl channel-update pecl.php.net
RUN pecl update-channels
RUN pecl install pecl_http
RUN pecl install jsmin
#RUN yum install -y ImageMagick ImageMagick-devel ImageMagick-perl # Use instead of GD2.
