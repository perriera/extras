#include <cstdint>
#include <extras/crc64_support.hpp>

#include "catch.hpp"

using namespace extras;

//     // 4171189273 r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K
//     // 4171189273 2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R

//     CrossTable crossTable;
//     StatLines history;

//     crc32 _crc32;
//     cout <<
//     _crc32.update("r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K")
//     << endl; cout <<
//     _crc32.update("2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R") <<
//     endl;

//     crc64 _crc64;
//     cout << _crc64.update("6591750584249225774 8/8/p7/4Bp2/4b1k1/1P1pK3/8/8 b
//     - - c 0") << endl; cout << _crc64.update("6591750584249225774
//     8/8/p7/4Bp2/4b1k1/1P1pK3/8/8 w - - c 0") << endl;

//     // 6591750584249225774 8/8/p7/4Bp2/4b1k1/1P1pK3/8/8 b - - c 0
//     // 6591750584249225774 8/8/p7/4Bp2/4b1k1/1P1pK3/8/8 w - - c 0
//     // Beating the odds of 1 in just over 1.84+e19
//     // Crc64CollisionException
//     // gamed matched: 4

SCENARIO("Verify crc64 default", "[crc64]") {
  {
    const char *data_piece4 = "\x80";
    crc64 crc;
    std::uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xC96C5795D7870F42);
  }
  {
    crc64 crc;
    const char *data_piece4 = "\xDE\xAD\xBE\xEF";
    std::uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xFC232C18806871AF);
  }
  {
    crc64 crc;
    const char *data_piece4 =
        "\x99\xEB\x96\xDD\x94\xC8\x8E\x97\x5B\x58\x5D\x2F\x28\x78\x5E\x36";
    std::uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0xDB7AC38F63413C4E);
  }
  {
    crc64 crc;
    const char *data_piece4 = "\xDE\xAD";
    std::uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0x44277F18417C45A5);
  }
  {
    crc64 crc;
    const char *data_piece4 = "rnbqkbnr/pppp1ppp/4p3/8/3PP3/8/PPP2PPP/RNBQKBNR";
    std::uint64_t crc4 = crc.update(data_piece4);
    REQUIRE(crc4 == 0x846ad61fd660e53c);
  }
}
