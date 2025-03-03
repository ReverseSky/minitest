FROM debian:bullseye

# Installation des paquets nécessaires
RUN apt update && apt install -y \
    php7.4 php7.4-fpm php7.4-mysql php7.4-xml php7.4-mbstring php7.4-curl php7.4-zip \
    php7.4-opcache php7.4-gd php-cli mariadb-client netcat lsof curl net-tools iputils-ping procps \
    && apt clean && rm -rf /var/lib/apt/lists/*

# Installation de WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

# Définir le dossier de travail
WORKDIR /var/www/html

# Copier le script de démarrage
COPY tools/wordpress_start.sh /wordpress_start.sh
RUN chmod +x /wordpress_start.sh

# Exposer le port 9000 (utilisé par PHP-FPM)
EXPOSE 9000

# Lancer le script au démarrage du conteneur
ENTRYPOINT ["/wordpress_start.sh"]