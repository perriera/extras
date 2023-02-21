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

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <fstream>
#include <iostream>

#include "../../vendor/catch.hpp"

using namespace std;
using namespace extras;

/**
 * @brief file::Interface
 *
 */
SCENARIO("dock/dock for file::Interface: found", "[PE-40]") {
  /**
   * @brief test valid path name
   *
   */
  string correct_answer = "test/etc/some_file.txt";
  file::File file(correct_answer);
  file::Interface& i = file;

  REQUIRE(i.filename() == correct_answer);
  REQUIRE(i.exists() == true);
}
