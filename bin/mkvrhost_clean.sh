#!/bin/bash

#
# check the required parameters 
#

if [ -z "$1" ]; then
  echo "You must specify a domain name to erase as a virtual host"
  exit
fi

#
# declare the domain name to be setup
#
domain_name=$1
virtual_host_location=/var/www/$1

echo "You specified $domain_name as a domain name"
public_html_dir=$virtual_host_location/public_html
echo "$public_html_dir is your public_html folder"

if [ ! -d "$virtual_host_location" ]; then
  echo "$virtual_host_location does not exist."
else
  sudo rm -rf $virtual_host_location
fi

if [ ! -d "$virtual_host_location" ]; then
  echo "$virtual_host_location erased"
else
  echo "$virtual_host_location did not erase"
fi

#
# disable the virtual host
#
sudo a2dissite $domain_name
echo "$old_conf a2dissite'd"
sudo systemctl restart apache2
sudo systemctl status apache2

old_conf=/etc/apache2/sites-available/$domain_name.conf
sudo rm $old_conf
echo "$old_conf erased"
sudo ls /etc/apache2/sites-available/ -la

