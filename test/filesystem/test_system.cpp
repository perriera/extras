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

#include <cstdint>
#include <extras/filesystem/filesystem.hpp>
#include <extras/filesystem/system.hpp>
#include <extras/strings.hpp>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

#include "../vendor/catch.hpp"

using namespace extras;

// SCENARIO("Test SystemException", "[SystemException]") {
//   std::string good_cmd = "ls -la";
//   std::string bad_cmd = "lsxyz@ -la";
//   SystemException::assertion(good_cmd, __INFO__);
//   REQUIRE_THROWS_AS(SystemException::assertion(bad_cmd, __INFO__),
//                     SystemException);
// }

// SCENARIO("Test ScriptException", "[SystemException]") {
//   std::string good_script = "./good_script.sh";
//   {
//     std::ofstream out(good_script);
//     out << "ls -la" << std::endl;
//   }
//   std::string bad_script = "./bad_script.sh";
//   {
//     std::ofstream out(bad_script);
//     out << "lsxyz@ -la" << std::endl;
//   }
//   ScriptException::assertion(good_script, __INFO__);
//   REQUIRE_THROWS_AS(ScriptException::assertion(bad_script, __INFO__),
//                     ScriptException);
// }