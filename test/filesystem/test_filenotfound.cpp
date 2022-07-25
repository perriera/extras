// /**
//  * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
//  *
//  * Copyright (C) November 22, 2021 EXPARX INCORPORATED
//  *
//  * Permission is hereby  granted,  free of charge,  to  any  person
//  * obtaining a copy of this software and  associated  documentation
//  * files   (the  "Software"),  to deal  in   the  Software  without
//  * restriction, including  without  limitation the rights  to  use,
//  * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
//  * sell copies of the  Software, and to permit persons  to whom the
//  * Software  is  furnished to  do  so,  subject  to  the  following
//  * conditions:
//  *
//  * (See LICENSE.md for complete details)
//  *
//  */

// #include <cstdint>
// #include <extras/exceptions.hpp>
// #include <fstream>

// #include "../vendor/catch.hpp"

// using namespace extras;

// SCENARIO("Verify FileNotFoundException: true", "[FileNotFoundException]") {
//   FileNotFoundException::assertion("build/run-unittests-extras", __INFO__);
// }

// SCENARIO("Verify FileNotFoundException: false", "[FileNotFoundException]") {
//   REQUIRE_THROWS_AS(FileNotFoundException::assertion("build/abc.exe",
//   __INFO__),
//                     FileNotFoundException);
// }

// SCENARIO("Verify PathNotFoundException: true", "[FileNotFoundException]") {
//   PathNotFoundException::assertion("build/", __INFO__);
// }

// // SCENARIO("Verify PathNotFoundException: false", "[FileNotFoundException]")
// {
// //   REQUIRE_THROWS_AS(PathNotFoundException::assertion("build/abc.exe",
// //   __INFO__),
// //                     PathNotFoundException);
// //   REQUIRE_THROWS_AS(
// //       PathNotFoundException::assertion("build/run-unittests-extras",
// //       __INFO__), NotADirectoryException);
// //   REQUIRE_THROWS_AS(PathNotFoundException::assertion("buildx/", __INFO__),
// //                     PathNotFoundException);
// // }
