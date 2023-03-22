


## How To Set Up Apache Virtual Hosts on Ubuntu 20.04
> To be able to host multiple websites off one single web server and for those to be https compliant is worth it's weight in gold. This How-To describes how to set up such a platform using Apache, certbot and a well established version of Ubuntu.

 1. **GIVEN** we would like to have multiple websites off one single web server
 2. **WHEN** we use certbot on an apache server on a stable Ubuntu platform
 3. **THEN** we can have all the benefits that come with https for multiple websites

### Prerequisites
 - Ubuntu 20.04 instance
 - Access to the Internet
 - ssh key access 
 - at least 

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
 - [ ] now add apache
```
sudo apt install -y apache2
```
 - [ ] now adjust the firewall
```
sudo ufw app list
sudo ufw allow 'Apache'
sudo ufw status
```
 - [ ] now check the web server
```
sudo systemctl status apache2
```
 - [ ] now get your IP address
```
hostname -I
curl -4 icanhazip.com
```
 - [ ] now ping the ip address (from an external Linux box)
```
ping your_ip_address_to_webserver
```
 - [ ] now curl the ip address
```
curl http://your_ip_address_to_webserver
```
The contents of the apache server startup page should display.

At this point you should back up your Ubuntu instance before continuing.

### Alternate Case
> **http://your_ip_address_to_webserver**<br/><br/>
> This should show you the Apache Server startup page.

### Summary 
Now you have a platform with which to install the C++11/17 tools necessary for *(perriera) /  extras_dbo* cloned projects.

### Next Steps
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)

  ### References
 - [How To Set Up Apache Virtual Hosts on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-set-up-apache-virtual-hosts-on-ubuntu-20-04)
