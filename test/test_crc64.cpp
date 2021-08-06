#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string.h> // std::string
#include <string>   // std::string

#include "catch.hpp"
#include "extra/crc64_support.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify crc64 default", "[crc64]")
{
  {
    string data_piece4 = "\x80";
    crc64 crc;
    uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xC96C5795D7870F42);
  }
  {
    crc64 crc;
    string data_piece4 = "\xDE\xAD\xBE\xEF";
    uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xFC232C18806871AF);
  }
  {
    crc64 crc;
    string data_piece4 =
        "\x99\xEB\x96\xDD\x94\xC8\x8E\x97\x5B\x58\x5D\x2F\x28\x78\x5E\x36";
    uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xDB7AC38F63413C4E);
  }
  {
    crc64 crc;
    string data_piece4 = "\xDE\xAD";
    uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0x44277F18417C45A5);
  }
  {
    crc64 crc;
    string data_piece4 = "rnbqkbnr/pppp1ppp/4p3/8/3PP3/8/PPP2PPP/RNBQKBNR";
    uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0x846ad61fd660e53c);
  }
}
