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

#include <extras/status/StatusLine.hpp>
#include <extras/strings.hpp>
#include <iostream>
#include <sstream>

using namespace extras;

//
// printf("[+]File data downloaded successfully.\n");
//

SCENARIO("Test StatusLineInterface", "[StatusLineInterface]")
{
   extras::StatusLineMsg good = "File data downloaded successfully";
   extras::StatusLineMsg bad = "Error in socket";
   extras::StatusLine testcase;

   extras::StatusLineInterface& i = testcase;
   REQUIRE(extras::contains(i.pass(good), good));
   REQUIRE(extras::contains(i.fail(bad), bad));
}
