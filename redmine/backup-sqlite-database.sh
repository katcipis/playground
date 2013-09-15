#!/bin/sh

USER=katcipis
HOME=/home/$USER
REDMINE_SQLITE_DATABASE="/var/lib/dbconfig-common/sqlite3/redmine"
BACKUP_BASE_DIR="$HOME/Ubuntu One/redmine-backup"
NOW=$(date +"%F")
BACKUP_DIR=$BACKUP_BASE_DIR/$NOW/redmine

echo "This script must be run as sudo, just trust me :-)"
echo "It works for Redmine with sqlite under Apache"

echo "Creating backup dir["$BACKUP_DIR"]"
mkdir -p "$BACKUP_DIR"

echo "Stopping apache to avoid redmine being used while we backup"
service apache2 stop

echo "Copying redmine database from["$REDMINE_SQLITE_DATABASE"] to ["$BACKUP_DIR"]"
cp -pr "$REDMINE_SQLITE_DATABASE"/* "$BACKUP_DIR"

echo "The backup will be owned by["$USER"]"
chmod -R 751 "$BACKUP_BASE_DIR"
chown -R $USER "$BACKUP_BASE_DIR"

echo "Starting apache back"
service apache2 start
