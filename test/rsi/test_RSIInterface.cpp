
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Test RSIInterface", "[RSIInterface]") {
  bool async_mode = true;
  RSIUpload rsi;
  REQUIRE(rsi.async() == async_mode);
  REQUIRE(rsi.request() != "");
  REQUIRE(rsi.response() != "");
}
