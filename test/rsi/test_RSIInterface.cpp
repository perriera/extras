
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Test RSIInterface", "[RSIInterface]") {
  bool async_mode = true;
  RSIUpload rsi_upload("send.txt", "159.223.103.27", 9000, true);
  REQUIRE(rsi_upload.async() == async_mode);
  REQUIRE(rsi_upload.client() != "");
  REQUIRE(rsi_upload.server() != "");
}
