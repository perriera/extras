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
#include <extras/strings.hpp>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace std;
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

   extras::Pathname pathname = "test/file/etc/";
   extras::Filename filename = "some_file.txt";
   extras::Filename fullpath = pathname + filename;

   /**
    * @brief construct dock for interface
    *
    */

   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, seperator)).AlwaysDo([]() { return '/'; });
   When(Method(mold, pathname)).AlwaysDo([&i, &fullpath]() {
      if (fullpath.length() == 0)
         return fullpath;
      auto parts = extras::str::split(fullpath, i.seperator());
      parts.pop_back();
      extras::Filename result;
      for (auto part : parts) {
         result += part;
         result += i.seperator();
      }
      return result;
   });
   When(Method(mold, filename)).AlwaysDo([&i, &fullpath]() {
      if (fullpath.length() == 0)
         return fullpath;
      auto parts = extras::str::split(fullpath, i.seperator());
      extras::Filename result = parts.back();
      return result;
   });
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

//  struct stat s;
//   if (stat(fullpath.c_str(), &s) == 0) {
//      if (s.st_mode & S_IFDIR) {
//         return fullpath;
//      } else if (s.st_mode & S_IFREG) {
//      } else {
//         throw "It's something else";
//      }
//   } else {
//      throw "It's an error";
//   }
