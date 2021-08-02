#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string
#include <filesystem>
namespace fs = std::filesystem;

#include "catch.hpp"
#include "extra/Directory.hpp"
#include "extra/ansi_colors.hpp"
#include "extra/crc32_support.hpp"
#include "extra/crc64_support.hpp"
#include "extra/string_support.hpp"

using namespace std;
using namespace extras;

static string test_fullpath = "extra/include/extra/docopt_private.h";
static string test_filename = "docopt_private.h";
static string test_pathname = "extra/include/extra/";

static string whereAmI()
{
  if (fs::exists("run-unittests"))
    return "../";
  return "";
}

static string getFullPath()
{
  return whereAmI() + test_fullpath;
}

static string getPathname()
{
  return whereAmI() + test_pathname;
}

SCENARIO("Verify Directory.filename()", "[Directory]")
{

  string a = getFullPath();
  auto b = Directory(a).filename();
  REQUIRE(a != b);
  REQUIRE(b == test_filename);
}

SCENARIO("Verify Directory.pathname()", "[Directory]")
{

  string a = getFullPath();
  auto b = Directory(a).pathname();
  REQUIRE(a != b);
  REQUIRE(b == getPathname());
}

SCENARIO("Verify Directory.listing() 'path exists'", "[Directory]")
{

  string a = getFullPath();
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 21);
}

SCENARIO("Verify Directory.listing() 'path does not exists'", "[Directory]")
{

  string a = "garabage";
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 0);
}

SCENARIO("Verify Directory.listing() 'only path given'", "[Directory]")
{

  string a = getPathname();
  auto b = Directory(a).listing();
  REQUIRE(b.size() == 21);
}

SCENARIO("Verify Directory.listing() 'no path given'", "[Directory]")
{

  string a = "";
  auto b = Directory(a).listing();
  REQUIRE(b.size() > 0);
}

SCENARIO("Verify Directory ", "[Directory]")
{

  string filename = getFullPath();
  auto fileExists = Directory(filename).fileExists();
  REQUIRE(fileExists);
}
