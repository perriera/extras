## How to install your own GitHub Server onto Ubuntu 20.04
> Setting up a local git server requires an SSH server setup for two accounts setup first. One for the user and another for the server.

 1. **GIVEN** that a local GitHub server has better privacy capabilties
 2. **WHEN** we install the GitHub open source code
 3. **THEN** we can enjoy the benefits of a locally managed GitHub server

### Prerequisites
  - [How to install a Linux Platform (Ubuntu 20.04.4)](https://github.com/perriera/extras_dbo/blob/dev/docs/UBUNTU.md)
  - A Ubuntu 20.04 installed [dedicated server](https://www.hostnextra.com/dedicated-server.html) or [KVM VPS](https://www.hostnextra.com/vps-hosting.html).
-   A root user access or normal user with administrative privileges.
-   Add DNS A record of your server’s hostname. 
- OpenSSH installed and running


### Wish Case
#### install ssh
 - [ ] Test to see that you have SSH already installed

		ssh -V 

 - [ ] You should see something like 

		OpenSSH_8.2p1 Ubuntu-4ubuntu0.4, OpenSSL 1.1.1f  31 Mar 2020 

#### install git
 - [ ] Now copy and paste the following for a Linux environment

		sudo apt update -y
		sudo apt install git openssh-server -y

 - [ ] Verify it's installation

		git --version

#### configure server side git
 - [ ] Add user to handle the repositories:

		sudo adduser git
		
 - [ ] Log in as a git user
		
		su - git

 - [ ] Initiate a new empty repository using following command:

		git init --bare ~/hostnextra.git

 - [ ] Enable post-update hook by copying the sample file as follows:

		cd hostnextra.git/hooks/
		cp post-update.sample post-update

- [ ] now exit (or open another terminal window)

		exit 

#### configure client side ssh

- [ ] Configure for localhost

		git config --global user.name “git”  
		git config --global user.email “git@localhost”

- [ ] Create a key

		ssh-keygen -t ed25519 -C “git@localhost”

- [ ] Now copy the public key to where it can be copied
 
		 cat ~/.ssh/id_ed25519.pub > /tmp/key.txt

  
#### configure server side ssh

 - [ ] Log in as a git user  (or switch to another terminal window)
		
		su -- git

- [ ] To create the SSH directory and file for holding the authorized ssh key for git user, run the following commands:

		mkdir -p ~/.ssh
		chmod 700 ~/.ssh
		touch ~/.ssh/authorized_keys
		chmod 600 ~/.ssh/authorized_keys

- [ ] now add the key.txt created above
 
		 cat /tmp/key.txt >> ~/.ssh/authorized_keys
		 rm /tmp/key.txt

- [ ] now exit (or open another terminal window)

		exit 

#### configure client side git

- [ ] now restart ssh

		sudo systemctl restart ssh
		sudo systemctl status sshd

- [ ] Create a directory where you can keep all your projects

		mkdir ~/dev
		cd ~/dev
		
- [ ] Now, create a clone the hostnextra.git repository that we have created earlier in the server

		git clone git@localhost:~/hostnextra.git hostnextra.git

- [ ] Go to respository

		cd hostnextra.git

- [ ] You can see the repository is empty, so lets create some files

		echo “my test file” > file1.txt

- [ ] Add these file to our git repository

		git add .
		git commit -m "update"

- [ ] Push these changes to the remote git repository at localhost

		git push origin master

- [ ] Verify the changes, log back into the git user account

		su -- git

- [ ] access the git server and run following command to check the logs

		cd ~/hostnextra.git
		git log
		
- [ ] if you see the following your git server is operational (at the most basic level)

		commit 53f5f0ec459bb5dc9b9107f0caf1fb9ca8c1466f (HEAD -> master)
		Author: “git” <“git@localhost”>
		Date:   Wed May 11 14:51:12 2022 -0700

			update

- [ ] To see this in motion install GitKraken

		sudo snap install gitkraken --classic 


### Alternate Case 
> **Do you have a DNS A record for your server’s hostname?** </br>
>	Use your DNS A record hostname wherever localhost is mentioned above. </br>
>Additional information on firewalls can be found in the external reference section (below)

### Alternate Case 
> **You don't have SSH installed?** </br>
>
>		sudo apt install openssh-server -y

### Summary 
Now you have an operational GitHub server running locally on your Ubuntu box. This should address the issue being encountered with CPM and public URLs.

### Next Steps
 - [How to setup your localhost GitHub https:// access]((https://github.com/perriera/extras_dbo/blob/dev/docs/GITHUBHTTPS.md))
 - [How to setup your changelog.md](https://github.com/perriera/extras_dbo/blob/dev/docs/CHANGELOG.md)

#### External References
- [How to install GITHUB on Ubuntu : Step by Step](https://linuxtechlab.com/how-to-install-github-on-ubuntu-step-by-step/)</br>
- [How to Setup Git Server on Ubuntu 20.04](https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/)
- [How To Install and Enable SSH Server on Ubuntu 20.04](https://devconnected.com/how-to-install-and-enable-ssh-server-on-ubuntu-20-04/)
- [Ubuntu 20.04 SSH Server](https://linuxconfig.org/ubuntu-20-04-ssh-server)
- [How To Install and Configure GitLab on Ubuntu 18.04](https://www.digitalocean.com/community/tutorials/how-to-install-and-configure-gitlab-on-ubuntu-18-04)
- [Install and Configure Git Server on Ubuntu 20.04](https://www.hostnextra.com/kb/install-and-configure-git-server-on-ubuntu/)
- https://github.com/cpm-cmake/CPM.cmake/issues/132
- https://github.com/cpm-cmake/CPM.cmake/wiki/More-Snippets
- https://github.com/cpm-cmake/CPM.cmake
- https://git-scm.com/download/gui/linux
- https://snapcraft.io/gitkraken

- https://ubuntututorials.org/set-up-private-git-server-ubuntu-2004/
- https://www.andrewhoog.com/post/howto-setup-a-private-git-server-on-ubuntu-18.04/
- https://www.linux.com/training-tutorials/how-run-your-own-git-server/
- https://git-scm.com/book/en/v2/Git-on-the-Server-Setting-Up-the-Server
- https://git-scm.com/book/en/v2/Git-on-the-Server-Git-Daemon
- https://linuxways.net/ubuntu/how-to-setup-git-server-on-ubuntu-20-04/

- https://yunwuxin1.gitbooks.io/git/content/en/17950f608975b8c96cebaaa17b3904d1/a5209e0c593176dd3285b76799bafb1f.html

