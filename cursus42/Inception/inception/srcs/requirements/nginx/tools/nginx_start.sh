#!/bin/bash
set -e  # Stoppe le script en cas d'erreur

SSL_DIR="/data/nginx/ssl"
CERT_FILE="$SSL_DIR/grobledo.crt"
KEY_FILE="$SSL_DIR/grobledo.key"

# Vérifier et créer le dossier des certificats s'il n'existe pas
if [ ! -d "$SSL_DIR" ]; then
    echo "Création du dossier SSL..."
    mkdir -p "$SSL_DIR"
fi

# Vérifier et générer les certificats SSL s'ils sont absents
if [ ! -f "$CERT_FILE" ] || [ ! -f "$KEY_FILE" ]; then
    echo "Les certificats SSL sont absents, génération de certificats auto-signés..."
    openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out "$CERT_FILE" \
        -keyout "$KEY_FILE" \
        -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=grobledo/CN=grobledo.42.fr"
fi

# Vérifier que WordPress est accessible avant de démarrer Nginx
echo "Vérification de la connexion à WordPress..."
until nc -z wordpress 9000; do
    echo "Attente de WordPress..."
    sleep 2
done

echo "WordPress est prêt, démarrage de Nginx..."

# Lancer Nginx en mode foreground
exec nginx -g "daemon off;"