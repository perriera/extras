


## How To Secure Apache with Let's Encrypt on Ubuntu 20.04
> To be able to host multiple websites off one single web server and for those to be https compliant is worth it's weight in gold. This How-To describes how to set up such a platform using Apache, certbot and a well established version of Ubuntu.

 1. **GIVEN** we would like to have multiple websites off one single web server
 2. **WHEN** we use certbot on an apache server on a stable Ubuntu platform
 3. **THEN** we can have all the benefits that come with https for multiple websites

### Prerequisites
 - Ubuntu 20.04 instance
 - Access to the Internet
 - ssh key access 
 - a domain name pointing towards the Linux box 

### Wish Case
Assuming you have an Ubuntu instance with ssh key access ready to go:
 - [ ] ssh into the Ubuntu instance:
```
ssh sammy@your_server_ip
```
 - [ ] make sure it is up to date
```
sudo apt -y update
sudo apt -y upgrade
sudo apt -y autoremove
sudo reboot
```
 - [ ] relog back into Ubuntu instance
 - [ ] now add an a virtual host configuration 
```
sudo vi /etc/apache2/sites-available/freeformjs.org.conf
```
 - [ ] now the following contents (and replace 'freeformjs.org'
```
<VirtualHost *:80>
    ServerAdmin admin@cplusplus.org
    ServerName cplusplus.org

     <Directory /var/www/cplusplus.org/public_html>
        Options Indexes FollowSymLinks MultiViews
        AllowOverride All
        Order allow,deny
        allow from all
     </Directory>

    ServerAlias www.cplusplus.org
    DocumentRoot /var/www/cplusplus.org/public_html
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```
 - [ ] now create a place for the virtual host
```
sudo mkdir -p /var/www/freeformjs.org/public_html
sudo chown -R $USER:$USER /var/www/freeformjs.org/public_html
vi /var/www/freeformjs.org/public_html/index.html
```
Add the following:
```
<html>
    <head>
        <title>Welcome to Your_domain!</title>
    </head>
    <body>
        <h1>Success!  The your_domain virtual host is working!</h1>
    </body>
</html>
```
 - [ ] now enable the new virtual host (and disable the default one):
```
sudo a2ensite freeformjs.org.conf
sudo a2dissite 000-default.conf
sudo systemctl restart apache2
```
 - [ ] now test that apach2 can digest the above
```
sudo apache2ctl configtest
```
You should see only:
```
Syntax OK
```
 - [ ] now add apache2 HTTPS support to the firewall
```
sudo ufw status
sudo ufw allow 'Apache Full'
sudo ufw delete allow 'Apache'
sudo ufw status
```
 - [ ] now make sure your domain name is pointing to this Linux server
 - [ ] (check that the A record is pointing the desired ip address)
```
ping ip_address
ping domain name
```
The ip values should be the same
 - [ ] now add an SSL Certificate (compliments certbot):
```
sudo certbot --apache
```
PAY CLOSE ATTENTION to the dialog that comes up on the screen:

 - add your email
 - accept the license
 - say Yes
 - specify "1 2" for both domain names
 - select 2 to Redirect to HTTPS
 - [ ] now curl the ip address
```
curl http://freeformjs.org
```
The contents of the apache server startup page should display.
 - [ ] now setup certbot to automatically keep the certificates updated
```
sudo systemctl status certbot.timer
```

At this point you should back up your Ubuntu instance before continuing.

### Alternate Case
> **AH00558: apache2: Could not reliably determine**<br/><br/>
> This might show up and it means there is something missing from apache2 setup:
```
sudo vi /etc/apache2/apache2.conf
```
Add this to the bottom:
```
# Include the virtual host configurations:
IncludeOptional sites-enabled/*.conf
# vim: syntax=apache ts=4 sw=4 sts=4 sr noet
ServerName 127.0.0.1
```
Then rerun the test:
```
sudo apache2ctl configtest
```


### Summary 
Now you have a platform with which to install the C++11/17 tools necessary for *(perriera) /  extras_dbo* cloned projects.

### Next Steps
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)

  ### References
 - [How To Secure Apache with Let's Encrypt on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-secure-apache-with-let-s-encrypt-on-ubuntu-20-04)
 - [Apache Configuration Error AH00558: Could not reliably determine the server's fully qualified domain name](https://www.digitalocean.com/community/tutorials/apache-configuration-error-ah00558-could-not-reliably-determine-the-server-s-fully-qualified-domain-name)
