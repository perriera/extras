#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../include/HelloWorld/HelloWorld.hpp"
#include "catch.hpp"
#include "extra/Directory.hpp"
#include "extra/ansi_colors.hpp"
#include "extra/crc32_support.hpp"
#include "extra/crc64_support.hpp"
#include "extra/string_support.hpp"

using namespace std;

SCENARIO("Verify HelloWorld", "[HelloWorld]") {

  HelloWorld helloWorld;
  REQUIRE(helloWorld.say_hello() == "Hello, world");
}
