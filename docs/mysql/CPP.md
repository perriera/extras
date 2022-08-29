## How to install mysql C++ support onto Ubuntu
> In this step we need to install mysql software onto a Ubuntu 20.04 platform

 1. **GIVEN** we need to access a mysql database from C++ (on a Ubuntu platform)
 2. **WHEN** we install mysql's Connector/C++  available from mysql support
 3. **THEN** we can access a mysql database from C++

### Prerequisites
  - [How to install mysql onto Ubuntu)](https://github.com/perriera/extras_dbo/blob/dev/docs/mysql/INSTALL.md)

 
### Wish Case
Setting up mysql C++ support onto Ubuntu is not that difficult. It basically consists of adding a dev package and running ldconfig.
	
 - [ ] Add mysql C++ support, (aka. Connector/C++)

		sudo apt-get install libmysqlcppconn-dev

 - [ ] Now check out the standard include directory

		ls /usr/include/cppconn/

 - [ ] Now check out mysql C++ extensions went

		find /usr -name mysql
		
 - [ ] You should see something like
		
		/usr/lib/mysql
		/usr/share/bash-completion/completions/mysql
		/usr/share/mysql
		/usr/bin/mysql

 - [ ] In your CMakeLists.txt you need to add **mysqlcppconn**:
		
        set(EXTRAS_DBO_LIBS_NEEDED stdc++fs extras occi clntsh mysqlcppconn Threads::Threads)

 - [ ] In your header includes you need to add:
		
        #include <cppconn/driver.h>
        #include <cppconn/exception.h>
        #include <cppconn/resultset.h>
        #include <cppconn/statement.h>

 - [ ] Now open your Visual Studio Code editor and add this as a test case

		sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "sammy", "password");
        /* Connect to the MySQL test database */
        con->setSchema("test");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;

 - [ ] If you used the same username and password as the previous how to then the above test code should fail (that is, till you manually add a test database to mysql). So, add a test database first then try the test case again:

		mysql -u sammy -p 
		create database test;
		exit

 - [ ] By default, a table called _message will be created and it will have a single record containing the words "Hello, world". To verify this while inside mysql do this:

		mysql> SELECT 'Hello World!' AS _message

 - [ ] You have just accessed a mysql from C++ and a record was retrieved

		exit
	

### Alternate Case 
> **You need something more advanced?** </br>
>	Check out this external how-to from which this page derived for more info on the more refined aspects of setting up mysql (on Ubuntu):
[How To Install MySQL on Ubuntu 20.04](https://www.digitalocean.com/community/tutorials/how-to-install-mysql-on-ubuntu-20-04)

### Summary 
You have just accessed a mysql from C++ and a record was retrieved.

### Next Steps
 - [How to install mysql C++ support onto Ubuntu](https://github.com/perriera/extras_dbo/blob/dev/docs/mysql/CPP.md)
 - https://www.learnsqlonline.org/en/Hello,_World!
 - https://blog.devart.com/creating-a-new-database-in-mysql-tutorial-with-examples.html
 - https://aaronxu17.github.io/blog/install-mysql-connector/
 - https://askubuntu.com/questions/165868/installing-mysql-connector-c
 - https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-examples-complete-example-1.html
 - https://www.digitalocean.com/community/tutorials/initial-server-setup-with-ubuntu-20-04
 



