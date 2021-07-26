#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "catch.hpp"
#include "extra/Directory.hpp"
#include "extra/ansi_colors.hpp"
#include "extra/crc32_support.hpp"
#include "extra/crc64_support.hpp"
#include "extra/string_support.hpp"

using namespace std;
using namespace extras;

static string test_fullpath = "../extra_options/include/extra/docopt_private.h";
static string test_filename = "docopt_private.h";
static string test_pathname = "../extra_options/include/extra/";

SCENARIO("Verify Directory.filename()", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).filename();
  REQUIRE(a != b);
  REQUIRE(b == test_filename);
}

SCENARIO("Verify Directory.pathname()", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).pathname();
  REQUIRE(a != b);
  REQUIRE(b == test_pathname);
}

SCENARIO("Verify Directory.listing() 'path exists'", "[Directory]") {

  string a = test_fullpath;
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 5);
}

SCENARIO("Verify Directory.listing() 'path does not exists'", "[Directory]") {

  string a = "garabage";
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 0);
}

SCENARIO("Verify Directory.listing() 'only path given'", "[Directory]") {

  string a = test_pathname;
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 5);
}

SCENARIO("Verify Directory.listing() 'no path given'", "[Directory]") {

  string a = "";
  auto b = Directory(a).listing();
  REQUIRE(b.size() > 0);
}

SCENARIO("Verify Directory ", "[Directory]") {

  string filename = test_fullpath;
  auto fileExists = Directory(filename).fileExists();
  REQUIRE(fileExists);
}
