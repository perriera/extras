if [ -z "$1" ]; then
  echo "You must specify a domain name to erase as a virtual host"
  exit
fi

echo "You specified $1 as a domain name"
public_html_dir=/var/www/$1/public_html
echo "$public_html_dir is your public_html folder"

if [ ! -d "$public_html_dir" ]; then
  echo "$public_html_dir does not exist."
  exit
fi

sudo rm -rf $public_html_dir

if [ ! -d "$public_html_dir" ]; then
  echo "$public_html_dir erased"
  exit
else
  echo "$public_html_dir did not erase"
fi
