
## How to setup Oracle Instant Client (on Linux, Windows or Mac)
> This is a basic step-by-step guide to how to successfully install the Oracle Instant Client on your Ubuntu instance. The material provided by Ubuntu is good and well researched but recent upgrades to Oracle Instant Client appear to need some refinements as listed in this article.

 1. GIVEN we need to support apps that need Oracle database support
 2. WHEN we install the Oracle Instant Client
 3. THEN we will have access to a Oracle database

### Prerequisites

- [How to setup a development environment (on Linux, Windows or Mac)](https://github.com/perriera/extras_dbo/blob/dev/docs/ENVIRONMENT.md)
- [How to install the tools necessary for C++11/17 projects](https://github.com/perriera/extras_dbo/blob/dev/docs/INSTALL.md)
- [How to clone your project (with this template)](https://github.com/perriera/extras_dbo/blob/dev/docs/CLONE.md)
- [How to setup your changelog.md](https://github.com/perriera/extras_dbo/blob/dev/docs/CHANGELOG.md)

### Resources
[Ubuntu documentation: Oracle Instant Client](https://help.ubuntu.com/community/Oracle%20Instant%20Client)

### Wish Case
> Download the RPM files
 1. Go to [Oracle Instant Client](https://help.ubuntu.com/community/Oracle%20Instant%20Client) and download a specific version of Oracle Instant Client
 2. Select either *Basic* or *Basic Lite* (just one)
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

Now test for **libocci.so** again:
 
	ls $ORACLE_HOME/lib/libocci.so 

It should show up as:

	/usr/lib/oracle/19.15/client64/lib/libocci.so

With that successful run *ldconfig* in order sync everything up (with the Linux way of doing things)

	sudo ldconfig

> Review the Oracle Instant Client SDK installation:

	ls $ORACLE_HOME/bin
	ls $ORACLE_HOME/include
	ls $ORACLE_HOME/lib
	ls $ORACLE_HOME/lib/libclntsh*
	ls $ORACLE_HOME/lib/libocci*

You should see something like this:

	perry@ubuntu:~/Projects/extras_dbo$ ls $ORACLE_HOME/bin
	adrci  exp  expdp  genezi  imp  impdp  odbc_update_ini.sh  sqlldr  sqlplus  wrc
	perry@ubuntu:~/Projects/extras_dbo$ ls $ORACLE_HOME/include
	ldap.h     occiAQ.h       occiData.h     oci1.h    ociapr.h  ocidfn.h   ocikpr.h    ocixstream.h  orid.h  oro.h
	nzerror.h  occiCommon.h   occi.h         oci8dp.h  ocidef.h  ociextp.h  ociver.h    odci.h        ori.h   ort.h
	nzt.h      occiControl.h  occiObjects.h  ociap.h   ocidem.h  oci.h      ocixmldb.h  oratypes.h    orl.h   xa.h
	perry@ubuntu:~/Projects/extras_dbo$ ls $ORACLE_HOME/lib
	glogin.sql             libclntsh.so.10.1  libclntsh.so.19.1  libnfsodm19.so   libociei.so       libsqlplus.so     orai18n.jar
	libclntshcore.so       libclntsh.so.11.1  libheteroxa19.so   libnnz19.so      libocijdbc19.so   libsqora.so.19.1  orai18n-mapping.jar
	libclntshcore.so.19.1  libclntsh.so.12.1  libipc1.so         libocci.so       liboramysql19.so  network           ottclasses.zip
	libclntsh.so           libclntsh.so.18.1  libmql1.so         libocci.so.19.1  libsqlplusic.so   ojdbc8.jar        xstreams.jar
	perry@ubuntu:~/Projects/extras_dbo$ ls $ORACLE_HOME/lib/libclntsh*
	/usr/lib/oracle/19.15/client64/lib/libclntshcore.so       /usr/lib/oracle/19.15/client64/lib/libclntsh.so.11.1
	/usr/lib/oracle/19.15/client64/lib/libclntshcore.so.19.1  /usr/lib/oracle/19.15/client64/lib/libclntsh.so.12.1
	/usr/lib/oracle/19.15/client64/lib/libclntsh.so           /usr/lib/oracle/19.15/client64/lib/libclntsh.so.18.1
	/usr/lib/oracle/19.15/client64/lib/libclntsh.so.10.1      /usr/lib/oracle/19.15/client64/lib/libclntsh.so.19.1
	perry@ubuntu:~/Projects/extras_dbo$ ls $ORACLE_HOME/lib/libocci*
	/usr/lib/oracle/19.15/client64/lib/libocci.so  /usr/lib/oracle/19.15/client64/lib/libocci.so.19.1

> Now check the interactive debugging capabiltites of Visual Studio Code

	cd ~/Projects/extras_dbo
	code .

Now inside Visual Studio Code do a **Ctrl-B** and see a successful build and you should see something like this:

	-- ======================== CMAKE_BUILD_TYPE: Debug ===========================
	-- CMAKE_CXX_FLAGS:  -Wall -Wextra -pedantic --std=c++17 -fPIC -g -Wall -Wextra -pedantic --std=c++17 -fPIC -pthread -g -O0
	-- CMAKE_C_FLAGS:  -Wall -Wextra -pedantic -fPIC -g -Wall -Wextra -pedantic -fPIC -pthread -g -O0
	-- CPM: adding package extras@5.26.0 (v5.26.0 at /home/perry/.cache/CPM/extras/d4c42783a675887008e79728d654420ec80ff550)
	-- Configuring extras build properties
	-- Building tests
	-- Building extras_dbo with Interprocedural Optimization
	-- Configuring done
	-- Generating done
	-- Build files have been written to: /home/perry/Projects/extras_dbo/build
	Consolidate compiler generated dependencies of target extras
	[  4%] Linking CXX shared library libextras.so
	[ 62%] Built target extras
	Consolidate compiler generated dependencies of target extras_dbo
	[ 66%] Building CXX object CMakeFiles/extras_dbo.dir/src/game/ChessGame.cpp.o
	[ 70%] Linking CXX shared library libextras_dbo.so
	[ 70%] Built target extras_dbo
	[ 75%] Building CXX object CMakeFiles/run-unittests-extras_dbo.dir/test/chessgame/mock_ChessGame.cpp.o
	[ 79%] Building CXX object CMakeFiles/run-unittests-extras_dbo.dir/test/chessgame/test_ChessGame.cpp.o
	[ 83%] Building CXX object CMakeFiles/run-unittests-extras_dbo.dir/test/oracle/test_OracleSDK.cpp.o
	[ 87%] Building CXX object CMakeFiles/run-unittests-extras_dbo.dir/test/vendor/main.cpp.o
	[ 91%] Linking CXX executable run-unittests-extras_dbo
	[ 91%] Built target run-unittests-extras_dbo
	[ 95%] Building CXX object CMakeFiles/extras_dbo_app.dir/instances/main.cpp.o
	[100%] Linking CXX executable extras_dbo_app
	[100%] Built target extras_dbo_app

	Terminal will be reused by tasks, press any key to close it.


### Shared Library support
**libextras_dbo.so**</br>
Any and all code (including header files) that you develop (or add on a branch on this project) to this repository will go into this library and can be easily included in other GitHub projects via CPM or sudo checkinstall, (just include the following in your CMakeLists.txt). We recommend you either use (perriera) exrtas_cpp as template project or use the CMakeLists.txt included in this project as a guide.

	#
	# NOTE: "Include 3rd party libraries, Perry and I maintain an open-source extras C++ library, which
	# is used extensively in extras_dbo, it comes bundled with spdlog, cpr, and nlohmann json. extras has
	# project options that allow us to control how other libraries it includes are built. for example we
	# can tell extras to build spdlog as a static library (for faster compile times) by settings
	# MAKE_SPDLOG_SHARED OFF" -- Matt Williams, October, 2021
	#
	CPMAddPackage(
		NAME extras_dbo
		GITHUB_REPOSITORY perriera/extras_dbo
		VERSION 0.4.0
		OPTIONS "MAKE_SPDLOG_SHARED OFF"
		OPTIONS "MAKE_EXTRAS_LIBRARY_ONLY ON"
	)
	if(extras_dbo_ADDED)
		#
		# NOTE:  enable c++11 to avoid compilation errors, and force spdlog into release build
		#
		print(STATUS "Configuring extras_dbo build properties")
		set_target_properties(extras_dbo PROPERTIES CMAKE_BUILD_TYPE Release)
	else()
		print(WARNING "extras_dbo was not configured properly")
	endif()


### Test gdb with Visual Studio Code on Oracle Instant Client:
>Now put a break point on a test case that uses *occi.h* (see *test_OracleSDK.cpp* and place a break point on line 43) and run the interactive debugger (aka. the green arrow next to *run-unittests*)

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


York C++ Uodate
export ORACLE_BASE=/Applications/oracleclient
export ORACLE_HOME=${ORACLE_BASE}/product/instantclient_12_2
export PATH=${ORACLE_HOME}:${PATH}
export DYLD_LIBRARY_PATH=${ORACLE_HOME}/lib
export TNS_ADMIN=${ORACLE_BASE}/admin/network
export SQLPATH=${SQLPATH}:${ORACLE_HOME}/sqlplus/admin
export NLS_LANG=AMERICAN_AMERICA.WE8ISO8859P1

https://oracle-base.com/articles/misc/oracle-instant-client-installation

