-- Créer la base de données WordPress
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

-- Créer l'utilisateur WordPress
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;

-- Ajouter les utilisateurs WordPress
USE ${MYSQL_DATABASE};

INSERT INTO wp_users (user_login, user_pass, user_nicename, user_email, user_status)
VALUES ('${WP_ADMIN_USER}', MD5('${WP_ADMIN_PASSWORD}'), 'Root User', '${WP_ADMIN_EMAIL}', 0);

INSERT INTO wp_users (user_login, user_pass, user_nicename, user_email, user_status)
VALUES ('${WP_USER}', MD5('${WP_USER_PASSWORD}'), 'Regular User', '${WP_USER_EMAIL}', 0);

INSERT INTO wp_usermeta (user_id, meta_key, meta_value)
VALUES (1, 'wp_capabilities', 'a:1:{s:13:"administrator";b:1;}');

INSERT INTO wp_usermeta (user_id, meta_key, meta_value)
VALUES (1, 'wp_user_level', '10');