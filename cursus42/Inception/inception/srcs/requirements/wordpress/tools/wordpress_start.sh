#!/bin/bash
set -e  # Stoppe le script en cas d erreur

# Creation du dossier necessaire pour PHP-FPM
mkdir -p /run/php/

echo "Verification des variables d environnement..."
if [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ] || [ -z "$MYSQL_PASSWORD" ] || \
   [ -z "$DOMAIN_NAME" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_PASSWORD" ] || \
   [ -z "$WP_ADMIN_EMAIL" ] || [ -z "$WP_USER" ] || [ -z "$WP_USER_EMAIL" ] || [ -z "$WP_USER_PASSWORD" ]; then
    echo "Erreur : Une ou plusieurs variables d environnement ne sont pas definies."
    exit 1
fi

# Verifier que MariaDB est pret avant d installer WordPress
echo "Verification de la connexion a MariaDB..."
until mariadb -h mariadb -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" -e "SELECT 1;" &> /dev/null; do
    echo "MariaDB n est pas encore pret, attente..."
    sleep 2
done
echo "MariaDB est pret !"

# Verifier si WordPress est deja installe
if [ ! -f /var/www/html/wp-config.php ]; then
    if [ -d "/var/www/html/wp-content" ]; then
        echo "WordPress semble deja installe. Suppression des anciens fichiers..."
        rm -rf /var/www/html/*
    fi

    echo "Telechargement de WordPress..."
    wp core download --allow-root

    echo "Configuration de WordPress..."
    wp config create --allow-root \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost=mariadb:3306

    echo "Installation de WordPress..."
    wp core install --allow-root \
        --url="https://$DOMAIN_NAME" \
        --title="Inception Project" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL"

    if ! wp user get "$WP_USER" --allow-root &> /dev/null; then
        echo "Ajout de l utilisateur standard..."
        wp user create "$WP_USER" "$WP_USER_EMAIL" --user_pass="$WP_USER_PASSWORD" --allow-root
    else
        echo "L utilisateur standard existe deja."
    fi
fi

# Donner les bonnes permissions aux fichiers WordPress
chown -R www-data:www-data /var/www/html

# Modifier la configuration de PHP-FPM pour ecouter sur le port 9000
sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 0.0.0.0:9000|' /etc/php/7.4/fpm/pool.d/www.conf
sed -i 's|listen.allowed_clients = 127.0.0.1|listen.allowed_clients = 0.0.0.0|' /etc/php/7.4/fpm/pool.d/www.conf

# Verifier si l'utilisateur admin existe avant de le creer
if ! wp user get "$WP_ADMIN_USER" --allow-root &> /dev/null; then
    echo "Ajout de l'utilisateur standard user42..."
    wp user create "$WP_ADMIN_USER" "$WP_ADMIN_EMAIL" --user_pass="$WP_ADMIN_PASSWORD" --role=administrator --allow-root
else
    echo "L'utilisateur admin existe deja, pas besoin de le recreer."
fi


# Verifier si l'utilisateur existe avant de le creer
if ! wp user get "$WP_USER" --allow-root &> /dev/null; then
    echo "Ajout de l'utilisateur standard user42..."
    wp user create "$WP_USER" "$WP_USER_EMAIL" --user_pass="$WP_USER_PASSWORD" --role=subscriber --allow-root
else
    echo "L'utilisateur standard existe deja, pas besoin de le recreer."
fi

echo "Demarrage de PHP-FPM..."
exec php-fpm7.4 -F