#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string.h> // std::string
#include <string>   // std::string

#include "catch.hpp"
#include "extra/crc32_support.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify crc32 default", "[crc32]")
{
  {
    string data_piece4 = "data_piece2;";
    crc32 crc;
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
  {
    crc32 crc;
    string data_piece4 = "data_piece2;";
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
  {
    crc32 crc("generate_table(table);");
    string data_piece4 = "data_piece2;";
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 3312197600);
  }
  {
    crc32 crc("abcdefg");
    string data_piece4 = "data_piece2;";
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 341281716);
  }
  {
    crc32 crc;
    string data_piece4 = "data_piece2;";
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 2874410684);
  }
}

SCENARIO("Verify crc32 bit collision", "[crc32X]")
{
  {
    string data_piece4 =
        "r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K";
    crc32 crc;
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 4171189273);
  }
  {
    crc32 crc;
    string data_piece4 = "2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R";
    uint32_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 4171189273);
  }
}
