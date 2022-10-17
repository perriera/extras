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
#include <extras/etc/interface.hpp>
#include <extras/file/interface.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace std;
using namespace extras;
using namespace extras::etc;
using namespace fakeit;

/**
 * @brief dock file::Interface
 *
 */
SCENARIO("Dock etc::Interface", "[PE-40]") {
  /**
   * @brief Given we need
   *
   */
  auto correct_answer = "test/file/etc/some_file.txt";

  // Dock<Interface> mold;
  // When(Method(mold, filename)).Return(correct_answer);
  // When(Method(mold, exists)).AlwaysDo([]() { return true; });

  // Interface& i = mold.get();
  // REQUIRE(i.filename() == correct_answer);
  // REQUIRE(i.exists() == true);

  // Verify(Method(mold, filename));
  // Verify(Method(mold, exists));
}
