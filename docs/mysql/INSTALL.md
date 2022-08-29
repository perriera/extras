


## How to install mysql onto Ubuntu
> In this step we need to install mysql software onto a Ubuntu 20.04 platform

 1. **GIVEN** we need to use a mysql database on a Ubuntu platform
 2. **WHEN** we activate the mysql support available from the Ubuntu repos
 3. **THEN** we can access all the features of mysql

### Prerequisites
  - [How to install a Linux Platform (Ubuntu 20.04.4)](https://github.com/perriera/extras_dbo/blob/dev/docs/UBUNTU.md)
  - [How to clone your project (with this template)](https://github.com/perriera/extras_dbo/blob/dev/docs/CLONE.md)

 
### Wish Case
Setting up mysql software onto Ubuntu is not that difficult. However, there are a variety of options available for more advanced purposes. In our case we just want to use myself for database testing purposes. So, we'll will stick witht the most basic instructions here.

  - [ ] First go into sudo mode

		sudo ls

  - [ ] Then update your Ubuntu
	
		sudo apt update -y
		sudo apt upgrade -y
		sudo reboot
	
 - [ ] Now mysql support onto Ubuntu

		sudo apt install mysql-server

 - [ ] Now start myself-server as a service

		sudo systemctl start mysql.service

 - [ ] Now open mysql as root 

		sudo mysql
		
 - [ ] Now add a user to the it
		
		CREATE USER 'sammy'@'localhost' IDENTIFIED BY 'password';

 - [ ] Now grant certain privileges to that user

		GRANT CREATE, ALTER, DROP, INSERT, UPDATE, DELETE, SELECT, REFERENCES, RELOAD on *.* TO 'sammy'@'localhost' WITH GRANT OPTION;
		FLUSH PRIVILEGES;

 - [ ] Now exit mysql as root and relog as the new user

		exit
		mysql -u sammy -p

 - [ ] Enter the password (as 'password' in this case) and you should see the mysql prompt

		Welcome to the MySQL monitor.  Commands end with ; or \g.
		Your MySQL connection id is 17
		Server version: 8.0.29-0ubuntu0.20.04.3 (Ubuntu)

		Copyright (c) 2000, 2022, Oracle and/or its affiliates.

		Oracle is a registered trademark of Oracle Corporation and/or its
		affiliates. Other names may be trademarks of their respective
		owners.

		Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

		mysql> 

 - [ ] While you are there add a 'test' database

		create database test;
		
 - [ ] You have just installed mysql and setup a user account successfully

		exit
	

### Alternate Case 
> **You need something more advanced?** </br>
>	Check out this external how-to from which this page derived for more info on the more refined aspects of setting up mysql (on Ubuntu):
[How To Install MySQL on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-20-04)

### Summary 
Now you have installed the mysql database (as a service) on Ubuntu 20.04 as well as have added a user with basic privileges. The next step now maybe to add C++ support as well as setting up a test databse.

### Next Steps
 - [How to install mysql C++ support onto Ubuntu](https://github.com/perriera/extras_dbo/blob/dev/docs/mysql/CPP.md)


