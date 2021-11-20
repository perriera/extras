#include <extras/status/StatusLine.hpp>
#include <extras/strings.hpp>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"

using namespace extras;

//
// printf("[+]File data downloaded successfully.\n");
//

SCENARIO("Test StatusLineInterface", "[StatusLineInterface]") {
  extras::StatusLineMsg good = "File data downloaded successfully";
  extras::StatusLineMsg bad = "Error in socket";
  extras::StatusLine testcase;

  extras::StatusLineInterface& i = testcase;
  REQUIRE(extras::contains(i.pass(good), good));
  REQUIRE(extras::contains(i.fail(bad), bad));
}
