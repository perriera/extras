


## How To Set Up an Initial Server Setup with Ubuntu 20.04
> To be able to host multiple websites off one single web server and for those to be https compliant is worth it's weight in gold. This How-To describes how to set up such a platform using Apache, certbot and a well established version of Ubuntu.

 1. **GIVEN** we would like to have multiple websites off one single web server
 2. **WHEN** we use certbot on an apache server on a stable Ubuntu platform
 3. **THEN** we can have all the benefits that come with https for multiple websites

### Prerequisites
 - Ubuntu 20.04 instance
 - Access to the Internet
 - ssh key access 

### Wish Case
Assuming you have an Ubuntu instance with ssh key access ready to go:
 - [ ] ssh into the Ubuntu instance:
```
ssh root@your_server_ip
```
 - [ ] make sure it is up to date
```
sudo apt -y update
sudo apt -y upgrade
sudo apt -y autoremove
sudo reboot
```
 - [ ] relog back into Ubuntu instance
 - [ ] now add a user account
```
adduser sammy
```
 - [ ] supply a password and add to the sudo users group
```
usermod -aG sudo sammy
```
 - [ ] now activate your firewall
```
ufw app list
ufw allow OpenSSH
ufw enable
```
```
ufw status
```
 - [ ] now give the new user ssh access
```
rsync --archive --chown=sammy:sammy ~/.ssh /home/sammy
```
 - [ ] now relog into the Ubuntu instance with the user account
```
ssh sammy@your_server_ip
```
At this point you should back up your Ubuntu instance before continuing.

### Alternate Case
> **no ssh key setup**<br/><br/>
> (See [How to generate a new SSH key for your GitHub.com account](https://github.com/perriera/extras/blob/dev/docs/SSHKEY.md))

### Summary 
Now you have a platform with which to install the C++11/17 tools necessary for *(perriera) /  extras_dbo* cloned projects.

### Next Steps
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)

  ### References
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)
