#!/bin/sh

VAGRANT_VIRTUALBOX_MACHINE=$HOME/.vagrant.d/boxes/precise32/virtualbox
VAGRANT_HOME_DIR=$HOME/workspace/works/redmine/vagrant
BACKUP_DIR="$HOME/Ubuntu One/redmine-backup"

echo "Halting Vagrant machine"
cd $VAGRANT_HOME_DIR
vagrant halt
echo "Copying $VAGRANT_VIRTUALBOX_MACHINE to $BACKUP_DIR"
cp -pr "$VAGRANT_VIRTUALBOX_MACHINE" "$BACKUP_DIR"
echo "running Vagrant again"
vagrant up
echo "done"
