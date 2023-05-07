


## How To Set Up Apache Virtual Hosts with certbot (Ubuntu 20.04.4)
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


 - [ ] Goto Ubuntu.com and download [Ubuntu 20.04.4](https://releases.ubuntu.com/20.04/)
 - [ ] Press the + button to the top right corner of Parallels Desktop Control Center
 - [ ] Select *Install Windows or another OS from a DVD or image file*
 - [ ] Press *Continue*
 - [ ] Select *ubuntu-20.04.4-desktop-amd64.iso* in *~/Downloads* 
 - [ ] Fill out the details for an *Express Installation*
 - [ ] Rename the installation *Ubuntu 20.04.4 LTS* (for clarity)
 - [ ] Select *Customize settings before installation*
 - [ ] Press *Create*
 - [ ] Under *Options -> Sharing* share the Home folder (and unselect everything else)
 - [ ] Under *Options -> CPU & Memory* set Memory to 8192 
 - [ ] Under *Options -> Mouse & Keyboard* set Mouse & Keyboard to *Don't optimize for games*
 - [ ] Close the dialog and press the blue *Continue* button
 - [ ] Wait for the install to complete
 - [ ] Login in with the login credentials you provided
 - [ ] (Optional) connect to any online accounts you may wish to include 
 - [ ] (Optional) Setup a Ubuntu One / Live Patch account
 - [ ] Click *Next* until you see the desktop
 - [ ] Select *Update Now* on the Software Updater
 - [ ] To the left you should now see a small icon with a status bar slowly going right
 - [ ] That status bar shows you updates being installed (wait for that to complete)
 - [ ] Click on the icon you see In the bottom left corner 
 - [ ] Type "ter" in the search box, select Terminal
 - [ ] When the Terminal box opens execute the following
 - [ ] **sudo apt update**
 - [ ] **sudo apt upgrade**
 - [ ] **sudo apt autoremove** (click yes)
 - [ ] **sudo apt update**
 - [ ]  This time you should see the message "*All packages are up to date*."
 - [ ] **sudo reboot**
 - [ ] When you login again you now have a fully working Ubuntu instance
 - [ ] Shutdown the Ubuntu instance (top right corner click on the icon)
 - [ ] Select *Power Off -> Power Off*
 - [ ] Now in the Parallels Desktop Control Center select *Ubuntu 20.04.4 LTS*
 - [ ] Click the *Reclaim* button to reclaim unused hard disk space
 - [ ] Close the *Configuration* dialog
 - [ ] Right mouse click on *Ubuntu 20.04.4 LTS* and select *Clone...*
 - [ ] Replace the name *Copy of Ubuntu 20.04.4 LTS* with something meaningful (ex. buntu 20.04.4 <your project name>"
 - [ ] Start your cloned Ubuntu instance for your project (keeping the original one in reserve as a backup)

### Alternate Case
> **In the case of some other Linux installation / hardware configuration**<br/><br/>
> You do not need to use Ubuntu (or an iMac), (if you have some other hardware or software arrangement that is perfectly fine). As long as your system is supporting Linux kernel 5.13 or greater you should be able to use the tools necessary to compile a C++11/17 based project in a GUI environment capable of supporting Visual Studio Code (or similair tool).
> You do not need to use Ubuntu (or an iMac), (if you have some other hardware or software arrangement that is perfectly fine). As long as your system is supporting Linux kernel 5.13 or greater you should be able to use the tools necessary to compile a C++11/17 based project in a GUI environment capable of supporting Visual Studio Code (or similair tool).

### Summary 
Now you have a platform with which to install the C++11/17 tools necessary for *(perriera) /  extras_dbo* cloned projects.

### Next Steps
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)

  ### References
 - [Initial Server Setup with Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04)
