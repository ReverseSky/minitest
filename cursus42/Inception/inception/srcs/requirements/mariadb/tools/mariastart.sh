#!/bin/bash
set -e  # Stoppe le script en cas d'erreur

# Créer un fichier temporaire avec les variables remplacées
sed -e "s|${MYSQL_DATABASE}|$MYSQL_DATABASE|g" \
    -e "s|${MYSQL_USER}|$MYSQL_USER|g" \
    -e "s|${MYSQL_PASSWORD}|$MYSQL_PASSWORD|g" \
    -e "s|${WP_ADMIN_USER}|$WP_ADMIN_USER|g" \
    -e "s|${WP_ADMIN_PASSWORD}|$WP_ADMIN_PASSWORD|g" \
    -e "s|${WP_ADMIN_EMAIL}|$WP_ADMIN_EMAIL|g" \
    -e "s|${WP_USER}|$WP_USER|g" \
    -e "s|${WP_USER_PASSWORD}|$WP_USER_PASSWORD|g" \
    -e "s|${WP_USER_EMAIL}|$WP_USER_EMAIL|g" \
    /docker-entrypoint-initdb.d/init.sql > /tmp/init.sql

# Définition du dossier où stocker la base de données
DB_DIR="/var/lib/mysql"

# Vérifier et préparer les permissions du dossier de stockage
mkdir -p "$DB_DIR"
chown -R mysql:mysql "$DB_DIR"
chmod 700 "$DB_DIR"

echo "Vérification des variables d'environnement..."
if [ -z "$MYSQL_ROOT_PASSWORD" ]; then
    echo "Erreur : MYSQL_ROOT_PASSWORD n'est pas défini."
    exit 1
fi

if [ -z "$MYSQL_PASSWORD" ] || [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ]; then
    echo "Erreur : Les variables d'environnement pour la base de données ne sont pas définies."
    exit 1
fi

# Vérifier si la base de données est déjà initialisée correctement
if [ ! -d "$DB_DIR/mysql" ]; then
    echo "Initialisation de MariaDB..."
    mariadb-install-db --user=mysql --datadir="$DB_DIR"

    echo "Démarrage temporaire de MariaDB..."
    mysqld --skip-networking=0 --socket=/var/run/mysqld/mysqld.sock &
    PID=$!

    # Attendre que MariaDB soit prêt avant d'exécuter les commandes SQL
    echo "Attente de la disponibilité de MariaDB..."
    for i in {30..0}; do
        if mariadb -u root -e "SELECT 1" &> /dev/null; then
            break
        fi
        echo "MariaDB n'est pas encore prêt, attente..."
        sleep 2
    done

    if [ "$i" = 0 ]; then
        echo "Erreur : MariaDB ne s'est pas lancé correctement."
        exit 1
    fi

    echo "Création de la base de données et des utilisateurs..."
    mariadb -u root -e "
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
    "

    echo "Arrêt de MariaDB temporaire..."
    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
fi

echo "Démarrage de MariaDB..."
exec mysqld --user=mysql --datadir="$DB_DIR"