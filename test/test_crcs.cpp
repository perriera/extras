#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string.h> // std::string
#include <string>   // std::string

#include "catch.hpp"
#include "extra/crcs.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify CRC", "[crc32]")
{
    string data_piece4 = "data_piece2;";
    CRCCalculator crc;
    crc.calculate(data_piece4);
    uint16_t result16 = crc;
    REQUIRE(result16 == 1164);
    uint32_t result32 = crc;
    REQUIRE(result32 == 2874410684);
    uint64_t result64 = crc;
    REQUIRE(result64 == 16391187711498339670);
}
