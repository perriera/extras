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

#include <fstream>
#include <iostream>

#include "../vendor/catch.hpp"
#include "extras/docking/DockIt.hpp"
#include "extras/file/class.hpp"

using namespace std;
using namespace extras;

/**
 * @brief Dock FileInterface
 *
 */
SCENARIO("Test FileInterface: found", "[PE-40]") {
  string correct_answer = "test/etc/some_file.txt";

  system::File file(correct_answer);
  system::FileInterface& i = file;

  REQUIRE(i.filename() == correct_answer);
  REQUIRE(i.exists() == true);
}

SCENARIO("Test FileInterface: not found", "[PE-40]") {
  string correct_answer = "test/etc/some_fileX.txt";

  system::File file(correct_answer);
  system::FileInterface& i = file;

  REQUIRE(i.filename() == correct_answer);
  REQUIRE(i.exists() == false);
}
