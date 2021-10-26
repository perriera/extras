#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>
#include <fstream>

#include "vendor/catch.hpp"

using namespace extras;

SCENARIO("Verify PathsInterface default", "[paths_support]") {
  std::string value = Paths::instance().actualPath("~/Downloads");
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
}

SCENARIO("Verify PathsInterface operator~()", "[paths_support]") {
  Paths path("~/Downloads");
  std::string value = ~path;
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
  std::cout << value << std::endl;
}

SCENARIO("Verify PathsInterface filename", "[paths_support]") {
  std::string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  Paths path(filename);
  Path actual_path = ~path;
  std::cout << actual_path << std::endl;
  std::ifstream myfile(actual_path);
  REQUIRE(myfile.good());
  std::string value = ~path;
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
  std::cout << value << std::endl;
}
