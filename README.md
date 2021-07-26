
# (perriera) extras
> This is a collection of C++ based tools to simplify the software development process.</br>
> It is composed, (at present) of the following sub-libraries:</br>
> 
 - extra_colors
 - extra_crcs
 - extra_files
 - extra_keywords
 - extra_options
 - extra_strings
 
 # Installation
 Assuming you are using a gcc/g++ environment on a Linux platform:
 
     git clone https://github.com/perriera/extras.git 
     cd extras
     mkdir build
     cd build
     cmake ..
     make
     sudo make install

 After installation the extra_ libraries should be found in your **/usr/local/include** and your **/usr/local/lib** directories. Also, set LD_LIBRARY_PATH, (if you haven't already done so). 

     export LD_LIBRARY_PATH=/usr/local/lib
     
If you happen to be adding features to the extras library and wish to debug it, be sure to put your build directory ahead of the install location, (otherwise the linking process will only use the installed version of the extra_ libraries).

    export LD_LIBRARY_PATH=build:/usr/local/lib
    
## CMakeLists.txt
Typically you would just include the extra_ library of your choice. However, some extra_ libraries are interdependent. So, the following is a complete listing of the libraries, (where you strip down the ones you don't need). Typically, they are required in **link** portions of your CMakeLists.txt targets, (as the system standard **/usr/local/include** path is assumed by the compiler). However, if you are directly working on the extra_ libraries then you might need to add them to the target_include_libraries as well.

     extra_colors
     extra_crcs
     extra_files
     extra_keywords
     extra_options
     extra_strings
For example:

    target_link_libraries(run-unittests
       chessmind::library
       extra_crcs
       extra_colors
       extra_keywords
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
    sudo make install

## namespace
As of 1.2.3 the extra_ libraries are not using namespace designationas, (as of yet). 

 ## extra_colors
 > add **extra_colors** to your CMakeLists.txt
 Use of this library will give you the ability to add color to your C++ console based applications for your typical Xterm based window. 

    #include  <iostream>
    #include  "chessmind/helloworld.hpp"
    #include  "extra/colors.hpp"

    using  namespace  std;
    void  Hello::hello() const
    {
       cout << red << "Hello" << endl;
       cout << green << "Hello" << endl;
       cout << blue << "Hello" << endl;
       cout << reset << "Hello" << endl;
    };

## extra_crcs
 > add **extra_crcs** to your CMakeLists.txt
Use of this library will give your application quick access to either crc16, crc32, or crc64 bit calculations.

    #include <iostream>
    #include "extra/crcs.hpp"

    SCENARIO("Verify crc32 default", "[crc32]") {
    {
       string  data_piece4 = "data_piece2;";
       crc32  crc;
       uint32_t  crc4 = crc.update(data_piece4);
       REQUIRE(crc4 == 2874410684);
    }

## extra_files
 > add **extra_files** to your CMakeLists.txt
Use of this library will give you easier access to files in the underlying operating system, (only tested on Linux as of 1.2.1).

    #include <iostream>
    #include "extra/files.hpp"

    SCENARIO("Verify Directory.filename()", "[Directory]") {
       string  a = "extra_options/include/extra/docopt_private.h";
       auto  b = Directory(a).filename();
       REQUIRE(a  !=  b);
       REQUIRE(b  ==  "docopt_private.h");
    }

## extra_keywords
 > add **extra_keywords** to your CMakeLists.txt
Use of this library will add extra keywords to your C++ syntax, (especially useful to programmers that like to program using interfaces, (aka. Design by Interface))

    #include <iostream>
    #include "extra/keywords.hpp"

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

## extra_options
 > add **extra_options** to your CMakeLists.txt
Use of this library will give you better main(argc,argv) capabilities as it parses command line arguments in an intelligent manner, (source code is Copyright (c) 2013 Jared Grubb, MIT license). 

    #include <iostream>
    #include "extra/options.hpp"

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
 > add **extra_strings** to your CMakeLists.txt
How many times how you wanted to do something really simple with strings but found yourself re-inventing the wheel all the time. Well, this library is merely a collection of popular std::string manipulation techniques, (based on the C++ STL library). Expect additional features to be added as time goes on:

    #include <iostream>
    #include "extra/strings.hpp"

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
    

# TODO:
The following are a series of features to be added to the extra_ libraries in the near future

## namespace
Expect one of the following to be the namespace paradyms to be used starting with release 2.0.0

    using namespace perrier::extras;
    using namespace perrier::extras::crcs;
    using namespace perrier::extras::files;
    using namespace perrier::extras::keywords;
    using namespace perrier::extras::options;
    using namespace perrier::extras::strings;

A simpler version of the above would be:

    using namespace extras;
    using namespace extras::crcs;
    using namespace extras::files;
    using namespace extras::keywords;
    using namespace extras::options;
    using namespace extras::strings;

Let us known which style you'd prefer at: perry.anderson@gmail.com, (or perry@exparx.com)

