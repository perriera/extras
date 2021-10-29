
#include <extras/rsi/interfaces.hpp>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"

using namespace extras;
using namespace std;

SCENARIO("Test RSIInterface streams", "[RSIRequestInterface]") {
  extras::RSIMacro macro1("filename", "ip", 9000, true, "upload");
  extras::RSIMacro macro2("filename", "ip", 8080, false, "download");
  REQUIRE(macro1 != macro2);
  stringstream ss;
  ss << macro1;
  ss >> macro2;
  REQUIRE(macro1 == macro2);
}
