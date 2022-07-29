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
#include "extras/filesystem/fileinterface.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Dock FileInterface
 *
 */
SCENARIO("Dock FileInterface", "[PE-40]") {
  auto correct_answer = "../etc/some_file.txt";

  Dock<system::FileInterface> dock;
  When(Method(dock, filename)).Return(correct_answer);
  When(Method(dock, exists)).AlwaysDo([]() { return true; });

  system::FileInterface& i = dock.get();
  REQUIRE(i.filename() == correct_answer);
  REQUIRE(i.exists() == true);

  Verify(Method(dock, filename));
  Verify(Method(dock, exists));
}
