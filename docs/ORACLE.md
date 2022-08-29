
- https://www.nakivo.com/blog/how-to-install-oracle-on-ubuntu-linux-waltkhrough/


## How to setup Oracle Database Express Edition (on Linux, Windows or Mac)
> This is a basic step-by-step guide to how to successfully install the Oracle Instant Client on your Ubuntu instance. The material provided by Ubuntu is good and well researched but recent upgrades to Oracle Instant Client appear to need some refinements as listed in this article.

**GIVEN**  we need to install an Oracle database for development
**WHEN**  we install Oracle Database Express Edition
**THEN**  we can test the various features of that database

### Prerequisites

- [Oracle Cloud Free Tier](https://www.oracle.com/cloud/free/)
- [How to setup a development environment (on Linux, Windows or Mac)](https://github.com/perriera/extras_dbo/blob/dev/docs/ENVIRONMENT.md)
- [How to install the tools necessary for C++11/17 projects](https://github.com/perriera/extras_dbo/blob/dev/docs/INSTALL.md)
- [How to clone your project (with this template)](https://github.com/perriera/extras_dbo/blob/dev/docs/CLONE.md)
- [How to setup your changelog.md](https://github.com/perriera/extras_dbo/blob/dev/docs/CHANGELOG.md)

### Resources
[How to install Oracle 11gR2 on Ubuntu 14.04?](https://askubuntu.com/questions/566734/how-to-install-oracle-11gr2-on-ubuntu-14-04)

https://stackoverflow.com/questions/66830312/trying-to-install-oracle-xe-18c-in-linux-mint-but-getting-error-any-suggestions
https://lignux.com/instalacion-y-configuracion-de-oracle-database-18c-express-edition/
https://stackoverflow.com/questions/53580196/issue-in-installing-oracle-18cxe-on-ubuntu-18-04
https://www.youtube.com/watch?v=RcZLD2l6WTw

https://docs.oracle.com/en/database/oracle/oracle-database/18/xeinl/procedure-installing-oracle-database-xe.html

https://www.oracle.com/downloads/developer-vm/community-downloads.html#dbapp
https://www.oracle.com/database/technologies/databaseappdev-vm.html
https://www.oracle.com/virtualization/technologies/vm/downloads/virtualbox-downloads.html


### Wish Case

This lab is done on Ubuntu 16.04 with Oracle Database 18c Express Edition.

	wget https://download.oracle.com/otn-pub/otn_software/db-express/oracle-database-xe-18c-1.0-1.x86_64.rpm

As you may have noticed, the installation file format is RPM which is used by Red Hat based distributions. But we are on Ubuntu based on Debian which uses the DEB format. So how can we install a package in a format that is incompatible with Debian-based distributions? It's simple, converting the package to DEB.

To do this we first need: alien and its dependencies that are responsible for performing this task:

	sudo apt install alien libaio1 unixodbc net-tools

We convert the package:

	sudo alien  --scripts  -d  oracle-database-xe-18c-1.0-1.x86_64.rpm

English

The conversion takes about 1h 30m depending on the power of your computer. When it's done, we save it.

Before installing the package, we have to configure a few things. We start by creating a script:

	sudo vi  /sbin/chkconfig

And we copy these lines into the file:

	#!/bin/bash
	# Oracle XE installer chkconfig hack for Ubuntu
	file=/etc/init.d/oracle-xe
	if  [[  !  `tail  -n1  $file  |  grep  INIT`  ]];  then
		echo  >>  $file
		echo  '### BEGIN INIT INFO'  >>  $file
		echo  '# Provides: OracleXE'  >>  $file
		echo  '# Required-Start: $remote_fs $syslog'  >>  $file
		echo  '# Required-Stop: $remote_fs $syslog'  >>  $file
		echo  '# Default-Start: 2 3 4 5'  >>  $file
		echo  '# Default-Stop: 0 1 6'  >>  $file
		echo  '# Short-Description: Oracle 11g Express Edition'  >>  $file
		echo  '### END INIT INFO'  >>  $file
	fi
	update-rc.d  oracle-xe defaults  80  01

We give the necessary permissions to the file:

	sudo chmod  755  /sbin/chkconfig

Oracle 18c XE requires a special kernel configuration to work. So we need to add some parameters to it.

	sudo vi  /etc/sysctl.d/60-oracle.conf

We copy the following and save.

	fs.file-max=6815744
	net.ipv4.ip_local_port_range=9000 65000
	kernel.sem=250 32000 100 128
	kernel.shmmax=536870912

To load kernel parameters without rebooting:

	sudo service procps start

### Installing Oracle 18c

And now yes, we finally install the package that previously took us so long to convert:

	sudo dpkg -i oracle-database-xe-18c_1.0-2_amd64.deb

After about 10 minutes the process will end. We execute the following command to configure the database administrator password and other things:

	sudo /etc/init.d/oracle-xe-18c configure

We will see what is wrong. That's because the configure script is missing a parameter. 

	Configuring Oracle Listener.
	Listener configuration failed. Check log '/opt/oracle/cfgtoollogs/netca/netca_configure_out.log' for more details.

To add it we enter the script with:

	sudo vi /etc/init.d/oracle-xe-18c

We look for the line the text:

	-J-Doracle.assistants.dbca.validate.DBCredentials=false 

And right after we add the parameter:

	-J-Doracle.assistants.dbca.validate.ConfigurationParams=false
 
 
 Being this way:

Now we try again:

	sudo /etc/init.d/oracle-xe-18c configure

We add the environment variables to bash:

	vi ~/.bashrc

We copy the following lines at the end of the file:

	export ORACLE_HOME=/opt/oracle/product/18c/dbhomeXE
	export ORACLE_SID=XE
	export ORACLE_BASE=/opt/oracle
	export LD_LIBRARY_PATH=$ORACLE_HOME/lib:$LD_LIBRARY_PATH
	export PATH=$ORACLE_HOME/bin:$PATH

#### Verification

To do this we first have to log in with SQL*Plus, or as in my case with Oracle SQL Developer. By command line (SQL*Plus) we enter with this command:

	sql sys as sysdba

We can verify that everything works correctly by making a query to the database.

As I usually tell you, if you have any questions, ask in the comments or in the LiGNUx Telegram group @liGNUx.

I hope it has been useful to you 🙂

We read!




> Download the RPM files
 1. Go to [Oracle Database XE Downloads](https://www.oracle.com/database/technologies/xe-downloads.html) and download a specific version of Oracle Database Express Edition
 2. Install the following:

		sudo apt-get install alien libaio1 unixodbc # still works in 22.04

 3. Download all supporting .rpm files for everything under that specific version (ignore the _Precompiler Downloads_)
> Install the RPM files
 4. Open a Terminal box:
 
		sudo apt-get install alien
		 
 8. Using the alien installer install each of the .rpm files, (do **not** use the *--scripts* parameter).
 9. (aka. in this case version 12 was downloaded)

		cd ~/Downloads
		ls 
This will show you all your .rpm files (for example):

	oracle-instantclient19.15-basic-19.15.0.0.0-1.x86_64.rpm
	oracle-instantclient19.15-devel-19.15.0.0.0-1.x86_64.rpm
	oracle-instantclient19.15-jdbc-19.15.0.0.0-1.x86_64.rpm
	oracle-instantclient19.15-sqlplus-19.15.0.0.0-1.x86_64.rpm
	oracle-instantclient19.15-tools-19.15.0.0.0-1.x86_64.rpm

After which you can type in:

	sudo alien -i oracle-ins

Then press TAB to where it will complete the line up to a point:

	sudo alien -i oracle-instantclient12.1-

From here enter the first letter, in this case it is a '**b**' and press TAB again, (again do **not** use the *--scripts* parameter).

	sudo alien -i oracle-instantclient19.15-basic-19.15.0.0.0-1.x86_64.rpm

Hit enter and repeat that for all the .rpm files you downloaded
> Set the ORACLE_HOME environment variable

7. As soon as those are completed 

		ls /usr/lib/oracle

8. You should see a number, (it should be the version number you selected for install). In this case the version number is 19.15:

		ls /usr/lib/oracle/19.15

9. You should see a directory called **client64**

		ls /usr/lib/oracle/19.15/client64

10. That entire path is known as your ORACLE_HOME directory and you must declare this environment variable somewhere during your session initialization. The .bashrc is an idea place (other tools might use .profile, it's up to you).

		vi ~/.bashrc

11. Append this to the end of the file:

		export ORACLE_HOME=/usr/lib/oracle/19.15/client64
		export PATH=$PATH:$ORACLE_HOME/bin
		export LD_LIBRARY_PATH=$ORACLE_HOME/lib:${LD_LIBRARY_PATH}

12. In your case replace 19.15 with the version you installed (if required.
13. Also install a required library: 

		sudo apt-get install libaio1

14. And source ~/.bashrc

		source ~/.bashrc

> Test the Oracle Instant Client installation
15. Now test the client:

		sqlplus username/password@//dbhost:1521/SID

16. Output should be similar to the following:

		SQL*Plus: Release 19.0.0.0.0 - Production on Tue Apr 26 20:43:08 2022
		Version 19.1.0.0.0
		Copyright (c) 1982, 2022, Oracle.  All rights reserved.
		Enter user-name:
> Add the C++ include path for the Oracle Instant Client SDK
	
	ls $ORACLE_HOME

This should show the following:

	bin lib

It should be

	bin include lib

So add it in:

	sudo ln -s /usr/include/oracle/19.15/client64/ $ORACLE_HOME/include

Now do  it again:

	ls $ORACLE_HOME

And make sure it says:

	bin include lib


18. In your CMakeLists.txt add ${ORACLE_INCLUDE} to any targets that need them

		target_include_directories(${TEST_EXEC} PUBLIC ${INCLUDES}  ${ORACLE_INCLUDE})

> Add the C++ link path for the Oracle Instant Client SDK

]20. In your CMakeLists.txt add **occi**  **chntsh** and **Threads::Threads** to any targets that need them

	target_link_libraries(${TEST_EXEC} PRIVATE ${PROJECT_NAME} stdc++fs extras occi clntsh Threads::Threads)

> Now register the libraries with ldconfig

	sudo vi /etc/ld.so.conf.d/oracle.conf

Add a single line 

	/usr/lib/oracle/19.15/client64/lib/

Change it's permissions 

	sudo chmod o+r /etc/ld.so.conf.d/oracle.conf

> Fix a missing link

24. A mistep in version 19.15 does not include the symbolic link **libocci.so**, (oddly enough the symbolic link is provided in version 18.5). Therefore we have to inspect the lib directory to ensure the symbolic links are there. 

		ls $ORACLE_HOME/lib/libclntsh.so

It should show up as:

	/usr/lib/oracle/19.15/client64/lib/libclntsh.so

Now do the same for the -locci error:
 
	ls $ORACLE_HOME/lib/libocci.so 

In 19.15 this symbolc link is missing:

	ls: cannot access '/usr/lib/oracle/19.15/client64/lib/libocci.so': No such file or directory

So add it back:

	sudo ln -s /usr/lib/oracle/19.15/client64/lib/libocci.so.19.1 /usr/lib/oracle/19.15/client64/lib/libocci.so

Then when that is successful, commit it using *ldconfig*

	sudo ldconfig

> Review the Oracle Instant Client SDK installation:

	ls $ORACLE_HOME/bin
	ls $ORACLE_HOME/include
	ls $ORACLE_HOME/lib
	ls $ORACLE_HOME/lib/libclntsh*
	ls $ORACLE_HOME/lib/libocci*

> Now check the interactive debugging capabiltites of Visual Studio Code

	cd ~/Projects/extras_dbo
	code .

Now inside Visual Studio Code do a **Ctrl-B** and see a successful build then put a break point on a test case that uses *occi.h* (see *test_OracleSDK.cpp* and place a break point on line 43) and run the interactive debugger (aka. the green arrow next to *run-unittests*)

The program should compile, make, run and land on that break point.

> Review the contents of cmake/FindOracle.cmake
34. In this project there is a file called *FileOracle.cmake* (which gets included in *CMakeLists.txt*). It originally contained the following:

		set(ORACLE_HOME $ENV{ORACLE_HOME})
		set(ORACLE_INCLUDE "${ORACLE_HOME}/include")
		set(ORACLE_LIB "${ORACLE_HOME}/lib")
		set(ORACLE_BIN "${ORACLE_HOME}/bin")
		link_directories(BEFORE "${ORACLE_LIB}" )
35. The above are cmake 3.21 instructions that allow the CMake to be able to find the Oracle installation. It is all based on the environment variable *$ORACLE_HOME*. 

### Alternate Case
> **How to remove RED SQUIGGLY LINES in Visual Studio Code**<br/>
> Inside the editor press ***Shift-Ctrl-P*** and type in ***CMake: Build*** (enter)<br/>
> This will cause the editor to rescan it's header includes and attempt to resolve the red squiggly lines (without having to restart the editor)

### Summary
> This shows the Oracle Instant Client has been installed successfully however you still need to see if the development portion is setup correctly. These instructions would be great if the entire process could be automated, but for now being able to install Oracle Instant Client at all with just the instructions in this markdown file is a milestone (as material on this process is rather sporatric across the Internet at this point in time).

### Next Steps
- [How to setup a local Oracle database (for testing purposes)](https://www2.hawaii.edu/~lipyeow/ics321/2015spr/installoracle11g.html)
- [How to install Oracle 11gR2 on Ubuntu 14.04?](https://askubuntu.com/questions/566734/how-to-install-oracle-11gr2-on-ubuntu-14-04)
- How to setup JDBC connectivity to Oracle
- How to setup ODBC connectivity to Oracle



