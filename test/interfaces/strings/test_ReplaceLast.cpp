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

#include <extras/exceptions.hpp>
#include <extras/strings.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <sstream>

#include "../../vendor/catch.hpp"

using namespace extras;

/**
 * @brief extras::replace_last() test cases
 *
 */

SCENARIO("Test ReplaceLast", "[string_support]") {
  extras::Path before = "/home/jack/projects/system/projects/projects.prj";
  Path after = "/home/jack/projects/system/projects/alpha.prj";

  auto test = extras::replace_last(before, "projects", "alpha");
  REQUIRE(test == after);
  REQUIRE(extras::replace_last(before, "nomatch", "alpha") == before);
  REQUIRE_THROWS_AS(extras::replace_last(before, "projects", "alpha", 'p'),
                    extras::StringContainsDelimException);
  auto test2 = extras::replace_last("abc", "b", "d");
  REQUIRE(test2 == "adc");
  auto test3 = extras::replace_last("a\rc", "\r", "d", '.');
  REQUIRE(test3 == "adc");
  auto test4 = extras::replace_last("", "b", "d");
  REQUIRE(test4 == "");
  auto test5 = extras::replace_last("abc", "", "d");
  REQUIRE(test5 == "abc");
  auto test6 = extras::replace_last("abc", "b", "");
  REQUIRE(test6 == "ac");
  auto e = "build/run-unittests-extras/run-unittests-extras.exe";
  auto e2 = "run-unittests-extras.exe";
  auto test7 = extras::replace_last(e, e2, "");
  REQUIRE(test7 == "build/run-unittests-extras/");
  auto f = "build/run-unittests-extras/run-unittests-extras";
  auto f2 = "run-unittests-extras";
  auto test8 = extras::replace_last(f, f2, "");
  REQUIRE(test8 == "build/run-unittests-extras/");
}
