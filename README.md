
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
>In the case of someone writing C++ code and they need a little **'extra'** help this collection of C++ libraries can make the C++ programming experience a lot easier, (and more enjoyable). At present there is **'extras support'** for  CRC calculations, pseudo C++ keywords, command line options, standard string manipulation and interface drive programming, (GoF Abstract Factory Pattern).
>

	#include <extras/crcs.hpp>
	#include <extras/vendor/cxxopts.hpp>
	#include <extras/interfaces.hpp>
	#include <extras/vendor/json.hpp>
	#include <extras/keywords.hpp>
	#include <extras/strings.hpp>
	#include <extras/support.hpp>
	
>
> Presently supporting Linux platforms is portable to Android, iPhone, iOS, Windows environments.
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

 After installation the **'extras support'**  should be found in your **/usr/local/include** and your **/usr/local/lib** directories. Also, set LD_LIBRARY_PATH, (if you haven't already done so). 

     export LD_LIBRARY_PATH=/usr/local/lib
     
If you happen to be adding features to the extras library and wish to debug it, be sure to put your build directory ahead of the install location, (otherwise the linking process will only use the installed version of the **'extras support'** ).

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

While it may seem odd to have to uninstall the **'extras support'**  package, future upgrades to the extras package will prefer if there is a clean install for you to work with.

## CMakeLists.txt
You just include the **extras** library to any targets in your CMakeLists.txt target_include_libraries specs

For example:

    target_link_libraries(run-unittests
       chessmind::library
       extras
    )
    
The 2.3.8 version of the extras libraries installs the debug version by default. If you wish to use a production version of the library you can either comment out this line in the main CMakeLists.txt file and recompile:

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

## extras/crcs
 > add **extras/crcs.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
Use of this library will give your application quick access to either crc16, crc32, or crc64 bit calculations.

    #include  <iostream>
    #include  <extras/crcs.hpp>
    #include "catch.hpp"

    using namespace extras;

    SCENARIO("Verify CRC instance", "[crcs]") {
        std::string data = "data_piece2;";
        auto& crc = CRC::instance().calculate(data);
        uint16_t result16 = crc;
        REQUIRE(result16 == 0x48C);
        uint32_t result32 = crc;
        REQUIRE(result32 == 0xAB5406BC);
        uint64_t result64 = crc;
        REQUIRE(result64 == 0xE37932611E9B4556);
    }


## extras/vendor/cxxopts
 > add **extras/vencor/cxxopts.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
 > 
This is a lightweight C++ option parser library, supporting the standard GNU style syntax for options.</br>
https://github.com/jarro2783/cxxopts/blob/master/LICENSE</br>
Copyright (c) 2014 Jarryd Beck 

    #include  <iostream>
    #include  <extras/vendor/cxxopts.hpp>
    #include "catch.hpp"

    using namespace extras;

    SCENARIO("Verify CXXOPTS instance", "[cxxopts]")
    {
        cxxopts::Options options("MyProgram", "One line description of MyProgram");
        options.add_options()
		  ("d,debug", "Enable debugging") // a bool parameter
		  ("i,integer", "Int param", cxxopts::value<int>())
		  ("f,file", "File name", cxxopts::value<std::string>())
		  ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));
    }

## extras/interfaces
 > add **extras/interfaces.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
Especially useful to programmers that like to program using interfaces, (aka. GoF: Abstract factory pattern))

    #include <iostream>
    #include <extras/interfaces.hpp>

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

## extras/vendor/json
 > add **extras/vendor/json.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
 > 
This is JSON for C++</br>
https://github.com/nlohmann/json/blob/develop/LICENSE.MIT</br>
Copyright (c) 2013-2019 Niels Lohmann <http://nlohmann.me>

	namespace ns {
	    // a simple struct to model a person
	    struct person {
	        std::string name;
	        std::string address;
	        int age;
	    };
	}

	ns::person p = {"Ned Flanders", "744 Evergreen Terrace", 60};
	// convert to JSON: copy each value into the JSON object
	json j;
	j["name"] = p.name;
	j["address"] = p.address;
	j["age"] = p.age;

	{
	  "pi": 3.141,
	  "happy": true,
	  "name": "Niels",
	  "nothing": null,
	  "answer": {
	    "everything": 42
	  },
	  "list": [1, 0, 2],
	  "object": {
	    "currency": "USD",
	    "value": 42.99
	  }
	}

## extras/keywords
 > add **extras/keywords.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
This header file defines constructs like the byte keyword:

	namespace extras
	{

	    /**
	     * @brief bytes
	     * 
	     * " Of the same size as char, but guaranteed to be unsigned. 
	     *   Contains at least the [0, 255] range.[5] ""
	     *    -- https://en.wikipedia.org/wiki/C_data_types
	     *    -- Wikipedia, August 6, 2021
	     * 
	     * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37, 
	     * § 6.2.6.1 Representations of types – General. 
	     * 
	     */

	    using byte = unsigned char;
	    using bytes = byte *;

	}

## extras/spdlog, (as a shared library)
 > when you git clone this repository to your directory structure and build it using the install 
 > procedure, (defined above), the ever popular spdlog library will now be available to you as a shared 
 > library, (aka. libspdlogd.so). The need for this came about when the header-only version of spdlog
 > kept showing up as a static library, so we found a way to make it into a shared library for projects
 > that run into the same situaiton. 
 > 
Very fast, header-only/compiled, C++ logging library. </br>
https://github.com/gabime/spdlog/blob/v1.x/LICENSE</br>
Copyright (c) 2016 Gabi Melman.


    # Add spdlog which includes fmt library as well (two for one) 
    # This should install on the system when extras in included in 
    # another project
    CPMAddPackage(
        GITHUB_REPOSITORY gabime/spdlog
        VERSION 1.9.1
        OPTIONS "SPDLOG_BUILD_SHARED ON"  "SPDLOG_BUILD_EXAMPLE OFF"  "SPDLOG_BUILD_TESTS OFF"
        "SPDLOG_BUILD_EXAMPLE OFF"  "SPDLOG_ENABLE_PCH ON"  "SPDLOG_INSTALL ON"
    )

## extras/strings
 > add **extras/strings.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
How many times how you wanted to do something really simple with strings but found yourself re-inventing the wheel all the time. Well, this library is merely a collection of popular std::string manipulation techniques, (based on the C++ STL library). Expect additional features to be added as time goes on:

    #include <iostream>
    #include <extras/strings.hpp>

    using  namespace  std;
    using  namespace  extras;

    static  inline  void  ltrim(std::string  &s);
    static  inline  void  rtrim(std::string  &s);
    static  inline  void  trim(std::string  &s);
    static  inline  std::string  ltrim_copy(const  std::string  &s);
    static  inline  std::string  rtrim_copy(const  std::string  &s);
    static  inline  std::string  trim_copy(const  std::string  &s);
    std::deque<std::string> split(const  std::string  &s, char  delim);
    std::string  replace_all(const  std::string  &s, char  a, char  b);
    std::string  remove_all(const  std::string  &s, char  a);
    std::string  replace_all(std::string  str, const  std::string  &from, const  std::string  &to);
    inline  bool  ends_with(std::string  const  &value, std::string  const  &ending);
    inline  bool  starts_with(std::string  const  &value, std::string  const  &beginning);
    inline  bool  contains(std::string  const  &s1, std::string  const  &s2);
    inline  std::string  to_lower(const  std::string  &data);
    
    
## extras/support
 > add **extras/support.hpp** to your C++ source</br>
 > This will include all the head files available in the extras/ directory.</br>
 > **using namespace extras;**</br>

## extras/CPM.cmake
 > when you git clone this repository to your directory structure you will see that our
 > CMakeLists.txt makes use of the CPM.cmake construct. When it comes to including other
 > git repositories inside your own, we have found no other tool as refined as this package 
 > as it includes a very used 'OPTIONS" parameter where C++ parameters necessary for the
 > repository you are including will be passed to the make file seemlessly, (see our spdlog
 > entry above))
 > 
Setup-free CMake dependency management</br>
https://github.com/cpm-cmake/CPM.cmake/blob/master/LICENSE</br>
Copyright (c) 2019 Lars Melchior

https://github.com/cpm-cmake/CPM.cmake

## Todo List:
The following are a series of features to be added to (perriera) extras in the near future. If there is anything you'd like to see added to the extras package please email us at perry.anderson@gmail.com, (or perry@exparx.com)

## Android support
Expect support for the Android platform in the near future
## iOS support
Expect support for the iOS platform in the near future
## iPhone support
Expect support for the iPhone platform in the near future
## Windows support
Expect support for the Windows platform in the near future
