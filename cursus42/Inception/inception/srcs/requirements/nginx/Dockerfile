FROM debian:bullseye

# Installer Nginx, OpenSSL et outils réseau
RUN apt update && apt install -y \
    nginx openssl net-tools lsof netcat curl iputils-ping \
    && apt clean && rm -rf /var/lib/apt/lists/*

# Créer les répertoires nécessaires
RUN mkdir -p /etc/nginx/ssl /var/www/html

# Copier la configuration Nginx
COPY /conf/default.conf /etc/nginx/conf.d/default.conf

# Copier le script de démarrage et lui donner les permissions d'exécution
COPY tools/nginx_start.sh /nginx_start.sh
RUN chmod +x /nginx_start.sh

# Donner les bonnes permissions au dossier où Nginx va servir WordPress
RUN chown -R www-data:www-data /var/www/html

# Exposer uniquement le port 443 (HTTPS)
EXPOSE 443

# Lancer le script de démarrage au démarrage du conteneur
ENTRYPOINT ["/nginx_start.sh"]