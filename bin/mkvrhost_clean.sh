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

#!/bin/bash
#
# @brief The MIT License (MIT)
# @copyright © 2023 Perry Anderson, (perry@exparx.ca)
#
# Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
# a copy of this software and associated documentation files (the “Software”),
# to deal in the Software  without restriction,  including  without limitation
# the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
# and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice  and this permission  notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
# OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
# LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#

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
