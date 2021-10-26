#include <string.h>  // std::string

#include <fstream>
#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "../vendor/catch.hpp"
#include "extras/crcs/crcs.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify CRC instance", "[crcs]") {
  std::string data = "data_piece2;";
  auto& crc = CRC::instance().calculate(data);
  uint16_t result16 = crc;
  REQUIRE(result16 == 0x48C);
  uint32_t result32 = crc;
  REQUIRE(result32 == 0xAB5406BC);
  uint64_t result64 = crc;
  REQUIRE(result64 == 0xE37932611E9B4556);
}
