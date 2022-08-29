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
#include <extras/docking/DockIt.hpp>
#include "extras/file/interface.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace std;
using namespace extras;
using namespace fakeit;

/**
 * @brief Dock FileInterface
 *
 */
SCENARIO("Dock FileInterface", "[PE-40]") {
  auto correct_answer = "test/etc/some_file.txt";

  Dock<file::Interface> mold;
  When(Method(mold, filename)).Return(correct_answer);
  When(Method(mold, exists)).AlwaysDo([]() { return true; });

  file::Interface& i = mold.get();
  REQUIRE(i.filename() == correct_answer);
  REQUIRE(i.exists() == true);

  Verify(Method(mold, filename));
  Verify(Method(mold, exists));
}

/**
 * @brief Dock FileInterface
 *
 */

// mkcp() {
//     test -d "$2" || mkdir -p "$2"
//     cp -r "$1" "$2"
// }

// SCENARIO("Dock FileInterface: copy", "[PE-40]") {
//   auto src = "test/etc/some_file.txt";
//   auto des = "test/etc2/some_file.txt";

//   Dock<system::FileInterface> mold;
//   When(Method(mold, filename)).Return(src);
//   When(Method(mold, exists)).AlwaysDo([]() { return true; });
//   When(Method(mold, copy))
//       .AlwaysDo([&src](const system::FileInterface& destination) {
//         system::FileNotFoundException::assertion(src, __INFO__);
//         stringstream ss;
//         ss << "test -d " << destination.filename() << " || ";
//         ss << "mkdir -p " << destination.filename() << endl;
//         ss << "cp -r " << src << " " << destination.filename() << endl;
//         string cmd = ss.str();
//         ::system(cmd.c_str());
//         system::FileNotCopiedException::assertion(destination, __INFO__);
//       });

//   system::FileInterface& i = mold.get();
//   REQUIRE(i.filename() == src);
//   REQUIRE(i.exists() == true);

//   Verify(Method(mold, filename));
//   Verify(Method(mold, exists));
// }
