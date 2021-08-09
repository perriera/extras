[![CMake](https://github.com/mattcoding4days/extras/actions/workflows/cmake.yml/badge.svg?branch=dev)](https://github.com/mattcoding4days/extras/actions/workflows/cmake.yml)

<div align="center">
  <img width="442" height="320" src="assets/extras.png">
  <br>
</div>


###   Description
> This is a collection of C++ based tools to simplify the software development process.</br> 
> 
>*Why would someone want to use this?*
>
>In the case of someone writing C++ code and they need a little **'extra'** help this collection of C++ libraries can make the C++ programming experience a lot easier, (and more enjoyable). At present there are **'extra_ libraries'** for ANSI colours, crc calculations, directory and file I/O, pseudo C++ keywords, command line options and standard string manipulation, (utilities).
 >
> It is presently composed of the following sub-libraries:</br>
> 
> - extra_colors
> - extra_crcs
> - extra_files
> - extra_interfaces
> - extra_options
> - extra_strings
>
> Presently supporting Linux platforms but can be ported to Android, iPhone, iOS, Windows environments.
>
 # Installation
 Assuming you are using a gcc/g++ environment on a Linux platform:
 
     git clone https://github.com/perriera/extras.git 
     cd extras
     mkdir build
     cd build
     cmake ..
     make
     ./run-unittests
     sudo make install

**Note**: **run-unittests** needs to be run from inside the build directory. 

 After installation the extra_ libraries should be found in your **/usr/local/include** and your **/usr/local/lib** directories. Also, set LD_LIBRARY_PATH, (if you haven't already done so). 

     export LD_LIBRARY_PATH=/usr/local/lib
     
If you happen to be adding features to the extras library and wish to debug it, be sure to put your build directory ahead of the install location, (otherwise the linking process will only use the installed version of the extra_ libraries).

    export LD_LIBRARY_PATH=build:/usr/local/lib

## sudo checkinstall
While the above will work for most applications, should you wish to uninstall you will need to install **extras** using a slightly different approach. To be able to uninstall you will need to install the Ubuntu **checkinstall** package: [here](https://help.ubuntu.com/community/CheckInstall). 

`sudo apt-get update && sudo apt-get install checkinstall`

With the checkinstall package installed your installation process now becomes:
    
     git clone https://github.com/perriera/extras.git 
     cd extras
     mkdir build
     cd build
     cmake ..
     make
     ./run-unittests
     sudo checkinstall

**Note**: During the checkinstall process be sure to change the name of the package from the default: **build** to **extras**. It'll be item #2 on the checkinstall parameter listings, (you can safely use the defaults for the rest of the items on the checkinstall).

Then when you need to uninstall this package:

    sudo dpkg -r extras

Should you run into a strange situation to where you issued the above command but the **extras** package appears to still be installed, run the following:

    sudo dpkg -r build

As you may have installed it earlier without changing the name of the package from **build** to **extras**.

While it may seem odd to have to uninstall the extra_ libraries package, future upgrades to the extras package will prefer if there is a clean install for you to work with.

## CMakeLists.txt
Typically you would just include the extra_ library of your choice. However, some extra_ libraries are interdependent. So, the following is a complete listing of the libraries, (where you strip down the ones you don't need). Typically, they are required in **link** portions of your CMakeLists.txt targets, (as the system standard **/usr/local/include** path is assumed by the compiler). However, if you are directly working on the extra_ libraries then you might need to add them to the target_include_libraries as well.

     extra_colors
     extra_crcs
     extra_files
     extra_interfaces
     extra_options
     extra_strings

For example:

    target_link_libraries(run-unittests
       chessmind::library
       extra_crcs
       extra_colors
       extra_interfaces
       extra_files
       extra_options
       extra_strings
    )
The 1.2.2 version of the extra_ libraries installs the debug version by default. If you wish to use a production version of the library you can either comment out this line in the main CMakeLists.txt file and recompile:

    set(CMAKE_BUILD_TYPE Debug)

Or, as of 1.2.3 you can define PRODUCTION on the command line of the cmake command and it will cause a production version of the library to be generated instead, (just be sure to delete the build directory before hand):

    cd ..
    rm -rf build
    cd build
    cmake -DPRODUCTION=true ..
    make
    ./run-unittests
    sudo make install

## C++ namespace support
As of version 2.0.0 the (perriera) **extras** package now requires the use of the namespace **extras**.

    using namespace extras;

With one exception, use of the **extra_options** package requires use of the namespace **docopt**.
   
    using namespace docopt;

If you wish to use the none-namespace version of **extras** simply use versions earlier than 2.0.0, (or modify your local implementation of the **extras** package). 

Change

	namespace extras {
To

	namespace {

In each of the header files of the **extras** package. A full recompilation would be necessary along with a complete reinstall of the library. 
 ## extra_colors
 > add **extra/colors.hpp** to your C++ source</br>
 > add **extra_colors** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
 Use of this library will give you the ability to add color to your C++ console based applications for your typical Xterm based window. 

    #include  <iostream>
    #include  <extra/colors.hpp>
    #include  "chessmind/helloworld.hpp"

    using  namespace  std;
    using  namespace  extras;

    void  Hello::hello() const
    {
       cout << red << "Hello" << endl;
       cout << green << "Hello" << endl;
       cout << blue << "Hello" << endl;
       cout << reset << "Hello" << endl;
    };

## extra_crcs
 > add **extra/crcs.hpp** to your C++ source</br>
 > add **extra_crcs** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
Use of this library will give your application quick access to either crc16, crc32, or crc64 bit calculations.

    #include <iostream>
    #include <extra/crcs.hpp>

    using  namespace  std;
    using  namespace  extras;

    SCENARIO("Verify crc32 default", "[crc32]") {
    {
       string  data_piece4 = "data_piece2;";
       crc32  crc;
       uint32_t  crc4 = crc.update(data_piece4);
       REQUIRE(crc4 == 2874410684);
    }

## extra_files
 > add **extra/files.hpp** to your C++ source</br>
 > add **extra_files** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
Use of this library will give you easier access to files in the underlying operating system, (only tested on Linux as of 1.2.1).

    #include <iostream>
    #include <extra/files.hpp>

    using  namespace  std;
    using  namespace  extras;

    SCENARIO("Verify Directory.filename()", "[Directory]") {
       string  a = "extra_options/include/extra/docopt_private.h";
       auto  b = Directory(a).filename();
       REQUIRE(a  !=  b);
       REQUIRE(b  ==  "docopt_private.h");
    }

## extra_interfaces
 > add **extra/interfaces.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
Especially useful to programmers that like to program using interfaces, (aka. GoF: Abstract factory pattern))

    #include <iostream>
    #include <extra/interfaces.hpp>

    //
    // CrossTableInterface
    // Encapsulates all behaviour CrossTableInterface
    //
    interface  CrossTableMapInterface {
       virtual  void  train(const  StatLines &statLines) pure;
       virtual  void  predict(const  FENLine &line) pure;
       virtual  void  size() const  pure;
       virtual  void  verbose(bool  on_or_off) pure;
    };

    concrete class CrossTableMap implements CrossTableMapInterface {
       virtual  void  train(const  StatLines &statLines);
       virtual  void  predict(const  FENLine &line);
       virtual  void  size() const;
       virtual  void  verbose(bool  on_or_off);
    };

## extra_keywords
 > add **extra/extra_keywords.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
This header file includes **extra_interfaces** but any keywords that are not interface related would be included here, (at present only keywords related to interfaces are in use at this time).

## extra_options
 > add **extra/options.hpp** to your C++ source</br>
 > add **extra_options** library to your CMakeLists.txt target</br>
 > **using namespace docopt;**</br>
Use of this library will give you better main(argc,argv) capabilities as it parses command line arguments in an intelligent manner, (source code is Copyright (c) 2013 Jared Grubb, MIT license). 

    #include <iostream>
    #include <extra/options.hpp>

    using  namespace  std;
    using  namespace  docopt;
    
    int  main(int  argc, const  char  *argv[])
    {
       std::map<std::string, docopt::value> args = docopt::docopt(
       USAGE, {argv + 1, argv + argc}, true, "ChessMind 1.0");
       std::string  name = "";
       if (args["<name>"] && args["<name>"].isString())
       {
          name = args["<name>"].asString();
          cout  <<  name  <<  endl;
       }
       return  0;
    }

## extra_strings
 > add **extra/strings.hpp** to your C++ source</br>
 > add **extra_strings** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
How many times how you wanted to do something really simple with strings but found yourself re-inventing the wheel all the time. Well, this library is merely a collection of popular std::string manipulation techniques, (based on the C++ STL library). Expect additional features to be added as time goes on:

    #include <iostream>
    #include <extra/strings.hpp>

    using  namespace  std;
    using  namespace  extras;

    static  inline  void  ltrim(std::string  &s);
    static  inline  void  rtrim(std::string  &s) ;
    static  inline  void  trim(std::string  &s);
    static  inline  std::string  ltrim_copy(const  std::string  &s) ;
    static  inline  std::string  rtrim_copy(const  std::string  &s) ;
    static  inline  std::string  trim_copy(const  std::string  &s) ;
    std::deque<std::string> split(const  std::string  &s, char  delim);
    std::string  replace_all(const  std::string  &s, char  a, char  b);
    std::string  remove_all(const  std::string  &s, char  a);
    std::string  replace_all(std::string  str, const  std::string  &from, const  std::string  &to);
    inline  bool  ends_with(std::string  const  &value, std::string  const  &ending) ;;
    inline  bool  starts_with(std::string  const  &value, std::string  const  &beginning) 
    inline  bool  contains(std::string  const  &s1, std::string  const  &s2);
    inline  std::string  to_lower(const  std::string  &data) ;
    
     ## extra_support
 > add **extra/support.hpp** to your C++ source</br>
 > (each individual extras library that use will have to be added to your CMakeLists.txt target)</br>
 > **using namespace extras;**</br>
 Use of this general purpose header file will simplify extras support in your source code as it includes ALL other header files. But to link to the extra_ library that you are using you still need to add a link to that particular library.

    #include  <iostream>
    #include  <extra/support.hpp>
    #include  "chessmind/helloworld.hpp"

    using  namespace  std;
    using  namespace  extras;

    void  Hello::hello() const
    {
       cout << red << "Hello" << endl;
       cout << green << "Hello" << endl;
       cout << blue << "Hello" << endl;
       cout << reset << "Hello" << endl;
    };


## Todo List:
The following are a series of features to be added to the extra_ libraries in the near future.
If there is anything you'd like to see added to the extras package please email us at perry.anderson@gmail.com, (or perry@exparx.com)

## Android support
Expect support for the Android platform in the near future
## iOS support
Expect support for the iOS platform in the near future
## iPhone support
Expect support for the iPhone platform in the near future

## Windows support
Expect support for the Windows platform in the near future
