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
    #include "../vendor/catch.hpp"

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

## extras/dotenv
 > add **extras/devices/dotenv.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
Use of this class will give you a simpler means of managing environment variables

    #include  <iostream>
    #include  <extras/devices/dotenv.hpp>
    #include "../vendor/catch.hpp"

    using namespace extras;

    SCENARIO("Test DotENV load token file", "[test_dotenv]") {

        /**
        * @brief The DotENVInterface handles a lot of the
        * common issues with formatting Unix/Linux style
        * parameters.
        */

        extras::DotENV dotENV;
        std::stringstream ss;
        ss << "# ASYNC accepted values [ on : off ]" << std::endl;
        ss << "ASYNC=on" << std::endl;
        ss << "YOURAPPTOKEN=dev" << std::endl;
        ss << "CLIENT_ID=dsfs-fsdf-sdf-sfdsdf-sdfsdf" << std::endl;
        ss << "CLIENT_SECRET=34343-dfdfd-3343-fsfdf-334-sd" << std::endl;
        ss << "AUDIENCE=https://jackpot_pc_salmon" << std::endl;
        ss << "COOKIE=dskjfhksjdhdhfkjsdf-sdhfkjdsf-Q; ";
        ss << "did_compatible=sdfssdf-sdf sddf-sd f-sdce-" << std::endl;
        ss >> dotENV;
        std::stringstream test;
        std::stringstream ss2;
        ss2 << dotENV;
        extras::DotENV dotENV_compare;
        ss2 >> dotENV_compare;
        REQUIRE(dotENV == dotENV_compare);
        REQUIRE(dotENV.value("YOURAPPTOKEN") == "dev");
    }


## extras/vendor/cxxopts
 > add **extras/vendor/cxxopts.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
 > 
This is a lightweight C++ option parser library, supporting the standard GNU style syntax for options.</br>
https://github.com/jarro2783/cxxopts/blob/master/LICENSE</br>
Copyright (c) 2014 Jarryd Beck 

    #include  <iostream>
    #include  <extras/vendor/cxxopts.hpp>
    #include "../vendor/catch.hpp"

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

## extras/exceptions
 > add **extras/language/exceptions.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
 > 
Custom exceptions are now possible in your applications with the use of **ExtrasExceptionInterface**</br>
https://github.com/perriera/extras/blob/main/include/extras/language/exceptions.hpp</br>
(See [test/mock_exceptions.cpp](https://github.com/perriera/extras/blob/main/test/mock_exceptions.cpp), [test/test_exceptions.cpp](https://github.com/perriera/extras/blob/main/test/test_exceptions.cpp) & [OctalException](https://github.com/perriera/extras/blob/main/include/extras/crcs/octal_support.hpp) for more on this)


    #include  <iostream>
    #include  <extras/language/exceptions.hpp>
    #include "../vendor/catch.hpp"

    using namespace extras;

    SCENARIO(
        "Test SpecificCustomException: demonstration (with assertion() methods)",
        "[exceptions_testcases]") {
        try {
            std::string port = "8080";
            SpecificCustomException::assertion(port, __INFO__);
            int a = 3;
            int b = 7;
            SpecificCustomException::assertion(a, b, __INFO__);
            FAIL("SpecificCustomException not thrown");
        } catch (SpecificCustomException& ex) {
            SUCCEED("SpecificCustomException thrown");
        } catch (GroupCustomException& ex) {
            FAIL("GroupCustomException thrown, (instead)");
        } catch (std::exception& ex) {
            FAIL("std::exception thrown, (instead)");
        } catch (...) {
            FAIL("... thrown, (instead)");
        }
    }


## extras/interfaces
 > add **extras/language/interfaces.hpp** to your C++ source</br>
 > (this library is header only at this point in time)</br>
 > **using namespace extras;**</br>
Especially useful to programmers that like to program using interfaces, (aka. GoF: Abstract factory pattern))

    #include <iostream>
    #include <extras/language/interfaces.hpp>

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
         void  train(const  StatLines &statLines) override;
         void  predict(const  FENLine &line) override;
         void  size() const  override;
         void  verbose(bool  on_or_off)  override;
    };

### FakeIt Mock Framework support, ([OctalInterface](https://github.com/perriera/extras/blob/main/include/extras/crcs/octal_support.hpp))
 > View **extras/octal_suppoer.hpp** to see a simple interface</br>
 > (see **mock_octal.cpp** in the **test/** directory)</br>
 > **using namespace extras;**</br>

To anyone wishing to know how to use mocks to write interfaces see the **OctalInterface** and the test cases written in the test/ directory.

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

## extras/keywords, (now known as extras/language/types.hpp)
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
    
## extras/paths
 > add **extras/filesystem/paths.hpp** to your C++ source</br>
 > add **extras** library to your CMakeLists.txt target</br>
 > **using namespace extras;**</br>
For sublties such as replacing the '~' character in a path to it's home value we have the **Paths** class

    #include <cstdint>
    #include <extras/filesystem/paths.hpp>
    #include <extras/strings.hpp>

    #include "../vendor/catch.hpp"

    using namespace extras;

    SCENARIO("Verify PathsInterface default", "[paths_support]") {
        std::string value = Paths::instance().actualPath("~/Downloads");
        REQUIRE(value != "~/Downloads");
        REQUIRE(extras::contains(value, "/home/"));
        REQUIRE(!extras::contains(value, "~"));
    }

For **badness** the '~()' is overloaded to carry out this function

    /**
     * @brief overloaded ~() operator to remove the ~ from the path
     * @return the full path, (where the '~' is replaced with home path)
     */
    Paths &operator~() noexcept { return *this; }
    operator std::string() { return actualPath(_path); }

The test case:

    SCENARIO("Verify PathsInterface operator~()", "[paths_support]") {
        Paths path("~/Downloads");
        std::string value = ~path;
        REQUIRE(value != "~/Downloads");
        REQUIRE(extras::contains(value, "/home/"));
        REQUIRE(!extras::contains(value, "~"));
        std::cout << value << std::endl;
    }

Output the following:

    /home/perry/Downloads

This is rather ironic and kinda against recommended coding practises, (as we are inserting here subtle changes in the expected behavior of the operator). But given the ironic nature that the same '~' is being used to remove another '~' character causes me to ponder about the meaning of life, (or at least mine).


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

## Acknowledgements
> **(perriera) extras** has been brought to you by these fine vendors:
- [clang-format configurator](https://zed0.co.uk/clang-format-configurator/)</br>

After you:

        sudo apt update
        sudo apt install clangd
        sudo apt install cppcqheck
        sudo apt install clang-tidy
        sudo apt install python3-pip
        pip install clang-format
        pip install cmake-format

Be sure to use [clang-format configurator](https://zed0.co.uk/clang-format-configurator/) for all for custom clang-format needs :)

Where you .clang-format can be as small as:

        BasedOnStyle: Google
        IncludeBlocks: Regroup

- [Matt Williams, Victoria, BC](https://www.linkedin.com/in/matt-williams-1291a8151/)</br>
  * Matt's attention to detail and knowledge of modern C++ coding techniques and standards have been an incredible [**Boost**](https://www.boost.org) to this library.
  * Thank you [Matt](https://github.com/mattcoding4days), :)
