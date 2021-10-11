#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>

#include "catch.hpp"

using namespace extras;

SCENARIO("Verify PathsInterface default", "[paths_support]") {
  std::string value = Paths::instance().actualPath("~/Downloads");
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
}
