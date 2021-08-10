#include <string.h>  // std::string

#include <fstream>
#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "catch.hpp"
#include "extras/crcs.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify CRC instance", "[crcs]") {
  string data = "data_piece2;";
  uint16_t result16 = CRC::instance().calculate(data);
  REQUIRE(result16 == 0x48C);
  uint32_t result32 = CRC::instance().calculate(data);
  REQUIRE(result32 == 0xAB5406BC);
  uint64_t result64 = CRC::instance().calculate(data);
  REQUIRE(result64 == 0xE37932611E9B4556);
}
