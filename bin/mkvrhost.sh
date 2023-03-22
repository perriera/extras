if [ -z "$1" ]; then
  echo "You must specify a domain name to be setup as a virtual host"
  exit
fi

echo "You specified $1 as a domain name"
public_html_dir=/var/www/$1/public_html
echo "$public_html_dir is your public_html folder"

if [ -d "$public_html_dir" ]; then
  echo "$public_html_dir already exist."
  echo "do a '$0_clean $0' to erase it"
  exit
fi

sudo mkdir -p $public_html_dir
sudo chown -R $USER:$USER $public_html_dir
sudo chmod -R 755 /var/www

if [ ! -d "$public_html_dir" ]; then
  echo "$public_html_dir created"
  exit
else
  echo "$public_html_dir not created"
fi
