



## How To Set Up Apache Virtual Hosts on Ubuntu 20.04
> To be able to host multiple websites off one single web server and for those to be https compliant is worth it's weight in gold. This How-To describes how to set up such a platform using Apache, certbot and a well established version of Ubuntu.

 1. **GIVEN** we would like to have multiple websites off one single web server
 2. **WHEN** we use certbot on an apache server on a stable Ubuntu platform
 3. **THEN** we can have all the benefits that come with https for multiple websites

### Prerequisites
 - Ubuntu 20.04 instance
 - Access to the Internet
 - ssh key access 
 - at least two domain names (pointing to the Linux box)

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
 - [ ] **check your domain name A records to ensure they are pointing to the Linux instance IP**
 (make sure you only change the A record for the website, not the A record for your *mail* server)
 - [ ] now add another virtual host
```
sudo mkdir -p /var/www/your_domain_1/public_html
sudo chown -R $USER:$USER /var/www/your_domain_1/public_html
sudo chmod -R 755 /var/www
```
Where your_domain1 is a domain name of yours
 - [ ] now give it some content
```
 vi /var/www/your_domain_1/public_html/index.html
```
 - [ ] the following will do fine
```
<html>
  <head>
    <title>Welcome to your_domain_1!</title>
  </head>
  <body>
    <h1>Success! The your_domain_1 virtual host is working!</h1>
  </body>
</html>
```
repeat the process for each domain name to be hosted 
 - [ ] now add a .conf file for each domain name 
```
sudo vi /etc/apache2/sites-available/freeformjs.org.conf
```
Replace freeformjs.org with a domain name of yours:
 - [ ] add the following for the content of the .conf file:
```
<VirtualHost *:80>
    ServerAdmin admin@freeformjs.org
    ServerName freeformjs.org

     <Directory /var/www/freeformjs.org/public_html>
        Options Indexes FollowSymLinks MultiViews
        AllowOverride All
        Order allow,deny
        allow from all
     </Directory>

    ServerAlias www.freeformjs.org
    DocumentRoot /var/www/freeformjs.org/public_html
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```
Again, replace freeformjs.org with a domain name of yours.
Be sure to use a valid email address  
 - [ ] now enable each of the virtual hosts with apache
```
sudo a2ensite www.freeformjs.org
```
Again, replace freeformjs.org with a domain name of yours.
 - [ ] Make sure the default website is no longer in use
```
sudo a2dissite 000-default.conf
```
 - [ ] Make sure apache2 can digest the setup instructions
```
sudo apache2ctl configtest
```
In the case that you receive the following:
```
Syntax OK
```
In the case any warnings or errors showed up see below
 - [ ] Now reload the apache server
```
sudo systemctl restart apache2
sudo systemctl status apache2
```
 - [ ] Now ping and curl each of your domain names
```
ping domain_name1
curl http://domain_name1 
```
Do this for each domain name
 - [ ] Now check the domain name in your browser
```
http://domain_name1 
```
Note the 'http' protocol (adding 'https' is the next step)
 - [ ] Add SSL certificates for each of the domain names
```
sudo certbot --apache
```
PAY CLOSE ATTENTION to the certbot instructions as your domain name will show up twice, once for the www. version and the other without the .www version. You want to specify both of these names by specifying the number associated for each one. Let's assume 1 and 2 are your menu options, (you'd specify both using a space in between):
- specify "1 2" for both domain names
Do this for each of the domain names you just entered as well as:
- select 2 to Redirect to HTTPS
 - [ ] Now check the domain name in your browser
```
https://domain_name1 
```
You could just reload each domain as they are now setup to redirect http requests to https.

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
### Alternate Case
> **Setting Up Local Hosts File**<br/><br/>
> If you haven’t been using actual domain names that you own to test this procedure, and have been using example domains instead, you can still test the functionality of your virtual host sites by temporarily modifying the hosts file on your local computer. This will intercept any requests for the domains that you configured and point them to your Virtual Private Server (VPS), just as the DNS system would do if you were using registered domains. This will only work from your local computer and is only for testing purposes.
> Make sure you are operating on your local computer for these steps and not your VPS server. You will need to know the computer’s administrative password or otherwise be a member of the administrative group.
```
sudo vi /etc/hosts
```
place your server ip address as follows:
```
127.0.0.1   localhost
127.0.1.1   guest-desktop
your_server_IP your_domain_1
your_server_IP your_domain_2
```
This will direct any requests for your two domains on your local Linux instance and send them to your server at the designated IP address, (save and close the file).

### Alternate Case
> **http://your_ip_address_to_webserver**<br/><br/>
> This should show you the Apache Server startup page.

### Summary 
Now you have a platform with which to install the C++11/17 tools necessary for *(perriera) /  extras_dbo* cloned projects.

### Next Steps
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)

  ### References
 - [How To Set Up Apache Virtual Hosts on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-set-up-apache-virtual-hosts-on-ubuntu-20-04)
