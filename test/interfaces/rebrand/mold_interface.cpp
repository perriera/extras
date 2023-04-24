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
#include <extras/file/clazz.hpp>
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
    * @brief determine fullpath
    *
    */
   auto major = EXTRAS_VER_MAJOR;
   auto minor = EXTRAS_VER_MINOR;
   auto patch = EXTRAS_VER_PATCH;
   Filename testarea = "build/testarea/";
   Filename filename = "librandom.so";
   Filename fullpath = filename;
   fullpath += "." + std::to_string(major);
   Filename sym1 = testarea + fullpath;
   fullpath += "." + std::to_string(minor);
   Filename sym2 = testarea + fullpath;
   fullpath += "." + std::to_string(patch);
   Filename sym3 = testarea + fullpath;
   Filename before = testarea + filename;
   Filename after = testarea + fullpath;

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, execute)).AlwaysDo([&i, &fullpath]() {
      extras::file::File file(fullpath);
      auto filename = file.filename();
      filename += "." + i.major();
      filename += "." + i.minor();
      filename += "." + i.patch();
   });
   When(Method(mold, major)).AlwaysDo([&major]() {
      {
         return std::to_string(major);
      }
   });
   When(Method(mold, minor)).AlwaysDo([&minor]() {
      {
         return std::to_string(minor);
      }
   });
   When(Method(mold, patch)).AlwaysDo([&patch]() {
      {
         return std::to_string(patch);
      }
   });

   /**
    * @brief prepare test area
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/rebrand/librandom.sol build/testarea/librandom.so");
   file::NotFoundException::assertion(before, __INFO__);

   /**
    * @brief test the interface
    *
    */

   i.execute();

   /**
    * @brief verify the desired methods were tested
    *
    */
   Verify(Method(mold, execute));
   Verify(Method(mold, major));
   Verify(Method(mold, minor));
   Verify(Method(mold, patch));
}
