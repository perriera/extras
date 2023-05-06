/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

#include "../../vendor/catch.hpp"

#include <cstdint>
#include <extras/crcs/crc64_support.hpp>

using namespace extras;

SCENARIO("Verify crc64 default", "[crc64]")
{
   {
      const char* data_piece4 = "\x80";
      crc64 crc;
      std::uint64_t crc4 = crc.update(data_piece4);
      REQUIRE(crc4 == 0xC96C5795D7870F42);
   }
   {
      crc64 crc;
      const char* data_piece4 = "\xDE\xAD\xBE\xEF";
      std::uint64_t crc4 = crc.update(data_piece4);
      REQUIRE(crc4 == 0xFC232C18806871AF);
   }
   {
      crc64 crc;
      const char* data_piece4 =
        "\x99\xEB\x96\xDD\x94\xC8\x8E\x97\x5B\x58\x5D\x2F\x28\x78\x5E\x36";
      std::uint64_t crc4 = crc.update(data_piece4);
      REQUIRE(crc4 == 0xDB7AC38F63413C4E);
   }
   {
      crc64 crc;
      const char* data_piece4 = "\xDE\xAD";
      std::uint64_t crc4 = crc.update(data_piece4);
      REQUIRE(crc4 == 0x44277F18417C45A5);
   }
   {
      crc64 crc;
      const char* data_piece4 =
        "rnbqkbnr/pppp1ppp/4p3/8/3PP3/8/PPP2PPP/RNBQKBNR";
      std::uint64_t crc4 = crc.update(data_piece4);
      REQUIRE(crc4 == 0x846ad61fd660e53c);
   }
}
