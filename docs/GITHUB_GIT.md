

## How to set up your own GitHub server using git protocol (on Ubuntu 20.04)
> Now let’s set up a daemon serving repositories using the “Git” protocol. This is a common choice for fast, unauthenticated access to your Git data. Remember that since this is not an authenticated service, anything you serve over this protocol is public within its network.

 1. **GIVEN** that your private GitHub server should be a service
 2. **WHEN** we configure Ubuntu to load the git server as a service
 3. **THEN** we can support other features such as git over http 

### Prerequisites
- [How to set up your own GitHub server using ssh protocol (on Ubuntu 20.04)](https://github.com/perriera/extras_dbo/blob/dev/docs/GITHUB_SSH.md)


### Wish Case
#### install git
 - [ ] First, run gitserver directly to see if it works

		git daemon --base-path=/srv/git --export-all --enable=receive-pack --reuseaddr --informative-errors --verbose

 - [ ] The words "Ready to rumble" should appear:

		[XXXX] Ready to rumble

 - [ ] Now open another terminal box and test it:

		cd dev
		mkdir test
		cd test
		git clone git://gitserver/xyzutil.git

 - [ ] That should have resulted in:

		Cloning into 'xyzutil'...
		remote: Enumerating objects: 3, done.
		remote: Counting objects: 100% (3/3), done.
		remote: Total 3 (delta 0), reused 0 (delta 0)
		Receiving objects: 100% (3/3), done.

 - [ ] Now to add this as a service (stop the other terminal) and add this to **systemd**:

		sudo vi /etc/systemd/system/git-daemon.service

 - [ ] In that file add the following (if you had to modify the daemon parameters adjust as necessary):

		[Unit]
		Description=Start Git Daemon

		[Service]
		ExecStart=/usr/bin/git daemon --base-path=/srv/git --export-all --enable=receive-pack --reuseaddr --informative-errors --verbose

		Restart=always
		RestartSec=500ms

		StandardOutput=syslog
		StandardError=syslog
		SyslogIdentifier=git-daemon

		User=git
		Group=git

		[Install]
		WantedBy=multi-user.target

 - [ ] Now enter the following to enable the service:

		sudo systemctl enable git-daemon
		sudo reboot

 - [ ] Now test your private GitHub server (using git protocol):

		cd dev
		rm -rf test
		mkdir test
		cd test
		git clone git://gitserver/xyzutil.git
		
 - [ ] You now have an operational private GitHub server (as a standard Ubuntu service).

### Alternate Case 
> **Starting and stopping the daemon manually**</br>
>	As per standard Ubuntu/Linux service commands: </br>

	sudo systemctl start git-daemon
	sudo systemctl stop git-daemon

### Alternate Case 
> **Want to add more projects?** </br>
>	Just like in the real github.com you need to create the project on the server first, (but the major difference here is that you do not specify the directory information).</br>

	sh git
	cd /srv/git
	git init --bare (new project name).git
	cd (new project name).git/hooks
	cp post-update.sample post-update
	exit
	cd dev
	git clone git@gitserver/(new project name).git

### Alternate Case 
> **Want to clone using ssh format?** </br>
>	You just need to change the format of the url for a ssh git clone request. However, (in this case) you will also have to add back in directory information</br>

		git clone git://gitserver/xyzutil.git

Becomes:

		git clone git@gitserver:/srv/git/xyzutil.git

> Mind you, if you use the home directory of the user git instead of a seperate directory you might not need to specify directory information here, (too be tested).

### Summary 
Now that you have an operational GitHub server running locally on your Ubuntu box (as a standard Ubuntu service) you no longer have to add additional directory information. Hence, it now acts a lot more like the actual GitHub.com server (complete with a host name of your choosing).   

### Next Steps
- [How to set up your own GitHub server using http protocol on Ubuntu 20.04](https://github.com/perriera/extras_dbo/blob/dev/docs/GITHUB_HTTP.md)
 - [How to setup your changelog.md](https://github.com/perriera/extras_dbo/blob/dev/docs/CHANGELOG.md)



