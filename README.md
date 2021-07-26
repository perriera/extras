# (perriera) extras
> This is a collection of C++ based tools to simplify the software development process..</br>
> It is composed, (at present) of the following sub-libraries:</br>
> 
 - extra_colors
 - extra_crcs
 - extra_files
 - extra_keywords
 - extra_options
 - extra_strings
 
 # Installation
 git clone https://github.com/perriera/extras.git </br>
 cd extras</br>
 mkdir build</br>
 cd build</br>
 cmake ...</br>
 make</br>
 sudo make install</br>
 
 ## extra_colors
 > add **extra_colors** to your CMakeLists.txt
 Use of this library will give you the ability to add color to your C++ console based applications for your typical Xterm based window. 

    #include  "libdmg/helloworld.hpp"
    #include  "extra/ansi_colors.hpp"
    #include  <iostream>
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

    SCENARIO("Verify Directory.filename()", "[Directory]") {
       string  a = "extra_options/include/extra/docopt_private.h";
       auto  b = Directory(a).filename();
       REQUIRE(a  !=  b);
       REQUIRE(b  ==  "docopt_private.h");
    }

## extra_keywords
 > add **extra_keywords** to your CMakeLists.txt
Use of this library will add extra keywords to your C++ syntax, (especially useful to programmers that like to program using interfaces, (aka. Design by Interface)

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
    


