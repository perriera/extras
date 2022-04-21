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

#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/docking/DockIt.hpp"
#include "extras/filesystem/paths.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 *
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock PathsInterface: toOctal", "[paths_support]") {
  auto correct_answer = "/home/perry/Downloads";
  Dock<PathsInterface> dock;
  When(Method(dock, actualPath)).Return(correct_answer);

  PathsInterface &i = dock.get();
  REQUIRE(i.actualPath("~/Downloads") == correct_answer);
  Verify(Method(dock, actualPath));
}