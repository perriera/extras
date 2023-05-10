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

#
# check the required parameters 
#

if [ -z "$1" ]; then
  echo "You must specify a domain name to be setup as a virtual host"
  exit
fi

#
# declare the domain name to be setup
#
domain_name=$1
virtual_host_location=/var/www/$1

echo "You specified $1 as a domain name"
public_html_dir=$virtual_host_location/public_html
echo "$public_html_dir is your public_html folder"

if [ -d "$public_html_dir" ]; then
  echo "$public_html_dir already exist."
  echo "do a '$0_clean $0' to erase it"
  exit
fi

sudo mkdir -p $public_html_dir
sudo chown -R $USER:$USER $public_html_dir
sudo chmod -R 755 /var/www

if [ -d "$public_html_dir" ]; then
  echo "$public_html_dir created"
else
  echo "$public_html_dir not created"
fi

#
# determine the location of the bin script
#
script_path="$(dirname -- "${BASH_SOURCE[0]}")"

#
# create a very basic html page
#
index_page_template=$script_path/txt/index.html
index_page=$public_html_dir/index.html
sed "s/freeformjs.org/$domain_name/" $index_page_template > /tmp/updated.txt
cp /tmp/updated.txt $index_page
sudo cat $index_page

#
# create a very basic virtual host file
#
freeformjs_conf_template=$script_path/txt/freeformjs.org.conf
new_conf=/etc/apache2/sites-available/$domain_name.conf
sed "s/freeformjs.org/$domain_name/" $freeformjs_conf_template > /tmp/updated.txt
sudo cp /tmp/updated.txt $new_conf
sudo ls /etc/apache2/sites-available/ -la
sudo ls $new_conf -la
sudo cat $new_conf

#
# enable the virtual host 
#
sudo a2ensite $domain_name
echo "$old_conf a2ensite'd"

sudo apache2ctl configtest
sudo systemctl restart apache2
sudo systemctl status apache2

#
# status
#
curl http://$domain_name
echo curl http://$domain_name 
ping $domain_name 
