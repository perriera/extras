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
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace std;
using namespace extras;
using namespace extras::file;
using namespace fakeit;

/**
 * @brief dock file::Interface
 *
 */
SCENARIO("Dock file::Interface::filename", "[mold file::Interface]")
{
   /**
    * @brief determine correct_answer
    *
    */

   Pathname pathname = "test/file/etc/";
   Filename filename = "some_file.txt";
   auto fullpath = pathname + filename;

   /**
    * @brief construct dock for interface
    *
    */

   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, pathname)).AlwaysDo([&pathname]() { return pathname; });
   When(Method(mold, filename)).AlwaysDo([&filename]() { return filename; });
   When(Method(mold, fullpath)).AlwaysDo([&fullpath]() { return fullpath; });

   /**
    * @brief test the interface
    *
    */

   REQUIRE(i.pathname() == pathname);
   REQUIRE(i.filename() == filename);
   REQUIRE(i.fullpath() == fullpath);

   /**
    * @brief verify the desired methods were tested
    *
    */

   Verify(Method(mold, filename));
   Verify(Method(mold, pathname));
   Verify(Method(mold, fullpath));
}
