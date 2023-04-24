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
#include "../../vendor/fakeit.hpp"

#include <extras/docking/DockIt.hpp>
#include <extras/file/interface.hpp>
#include <extras/rebrand/interface.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras::rebrand;
using namespace extras;
using namespace fakeit;

/**
 * @brief dock rebrand::Interface
 *
 */
SCENARIO("Mold rebrand::Interface", "[mold rebrand::Interface]")
{
   /**
    * @brief determine correct_answer
    *
    */
   auto major = EXTRAS_VER_MAJOR;
   auto minor = EXTRAS_VER_MINOR;
   auto patch = EXTRAS_VER_PATCH;
   Filename testarea = "build/testarea/";
   Filename filename = "librandom.so";
   Value correct_answer = filename;
   correct_answer += "." + std::to_string(major);
   Filename sym1 = testarea + correct_answer;
   correct_answer += "." + std::to_string(minor);
   Filename sym2 = testarea + correct_answer;
   correct_answer += "." + std::to_string(patch);
   Filename sym3 = testarea + correct_answer;
   Filename before = testarea + filename;
   Filename after = testarea + correct_answer;

   /**
    * @brief prepare test area
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/rebrand/librandom.sol build/testarea/librandom.so");

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, path))
     .AlwaysDo([&major, &minor, &patch](const Filename& filename) {
        {
           auto parts = extras::str::split(filename, '/');
           Value result = filename;
           result += "." + std::to_string(major);
           result += "." + std::to_string(minor);
           result += "." + std::to_string(patch);
           return result;
        }
     });
   When(Method(mold, fullname))
     .AlwaysDo([&major, &minor, &patch](const Filename& filename) {
        {
           Value result = filename;
           result += "." + std::to_string(major);
           result += "." + std::to_string(minor);
           result += "." + std::to_string(patch);
           return result;
        }
     });
   When(Method(mold, relink)).AlwaysDo([&i](const Filename& filename) {
      {
         Filename result = i.fullname(filename);
         CMD cmd1 = "rm " + filename;
      }
   });

   /**
    * @brief test the interface
    *
    */

   file::NotFoundException::assertion(before, __INFO__);
   //   REQUIRE(i.path(correct_answer) == testarea);
   REQUIRE(i.fullname(filename) == correct_answer);
   i.relink(filename);

   /**
    * @brief verify the desired methods were tested
    *
    */
   Verify(Method(mold, fullname));
   Verify(Method(mold, relink));
}
