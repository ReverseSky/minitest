<?php
define('DB_NAME', getenv('MYSQL_DATABASE'));
define('DB_USER', getenv('MYSQL_USER'));
define('DB_PASSWORD', getenv('MYSQL_PASSWORD'));
define('DB_HOST', getenv('DB_HOST') ?: 'mariadb:3306');

define('WP_DEBUG', false);
define('WP_DEBUG_LOG', false);
define('WP_DEBUG_DISPLAY', false);

define('FORCE_SSL_ADMIN', true);
define('FORCE_SSL_LOGIN', true);
$_SERVER['HTTPS'] = 'on';
define('WP_HOME', 'https://grobledo.42.fr');
define('WP_SITEURL', 'https://grobledo.42.fr');

$table_prefix = 'wp_';

define('FS_METHOD', 'direct');

if (!defined('ABSPATH')) {
    define('ABSPATH', dirname(__FILE__) . '/');
}
require_once ABSPATH . 'wp_settings.php';
?>