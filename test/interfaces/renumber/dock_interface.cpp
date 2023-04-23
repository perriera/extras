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
#include <extras/renumber/interface.hpp>
#include <extras/version.hpp>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras::renumber;
using namespace fakeit;

/**
 * @brief dock renumber::Interface
 *
 */
SCENARIO("Dock renumber::Interface", "[renumber::Interface]") {
   /**
    * @brief determine correct_answer
    *
    */
   auto major = EXTRAS_VER_MAJOR;
   auto minor = EXTRAS_VER_MINOR;
   auto patch = EXTRAS_VER_PATCH;
   Filename filename = "librandom.so";
   Value correct_answer = filename;
   correct_answer += "." + std::to_string(major) + ".";
   correct_answer += std::to_string(minor) + ".";
   correct_answer += std::to_string(patch);

   /**
    * @brief prepare test area
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/renumber/librandom.sol build/testarea/librandom.so");

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface &i = mold.get();
   When(Method(mold, fullname))
       .AlwaysDo([&major, &minor, &patch](const Filename &filename) {
          {
             Value result = filename;
             result += "." + std::to_string(major) + ".";
             result += std::to_string(minor) + ".";
             result += std::to_string(patch);
             return result;
          }
       });
   When(Method(mold, relink)).AlwaysDo([&i](const Filename &filename) {
      {
         Filename result = i.fullname(filename);
         CMD cmd1 = "rm " + filename;
      }
   });

   /**
    * @brief test the interface
    *
    */
   REQUIRE(i.fullname(filename) == correct_answer);
   i.relink(filename);

   /**
    * @brief verify the desired methods were tested
    *
    */
   Verify(Method(mold, fullname));
   Verify(Method(mold, relink));
}
