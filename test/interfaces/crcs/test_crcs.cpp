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
#include "extras/crcs.hpp"

#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string.h> // std::string
#include <string>   // std::string

using namespace std;
using namespace extras;

SCENARIO("Verify CRC instance", "[crcs]")
{
   std::string data = "data_piece2;";
   auto& crc = CRC::instance().calculate(data);
   uint16_t result16 = crc;
   REQUIRE(result16 == 0x48C);
   uint32_t result32 = crc;
   REQUIRE(result32 == 0xAB5406BC);
   uint64_t result64 = crc;
   REQUIRE(result64 == 0xE37932611E9B4556);
}
