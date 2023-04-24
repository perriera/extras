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

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using namespace extras::file;

/**
 * @brief file::Interface NotFoundException
 *
 */
SCENARIO("mold file::Interface::path", "[dock file::Interface]")
{

   /**
    * @brief test case #1
    *
    */

   extras::Pathname pathname = "test/file/etc/";
   extras::Filename filename = "some_file.txt";
   extras::Filename fullpath = pathname + filename;
   {
      extras::file::File dock(fullpath);
      Interface& i = dock;

      REQUIRE(extras::str::starts_with(i.tempname(), "/tmp/mytemp."));
      REQUIRE(i.pathname() == pathname);
      REQUIRE(i.filename() == filename);
      REQUIRE(i.fullpath() == fullpath);
      REQUIRE_FALSE(i.exists());
      REQUIRE_FALSE(i.is_dir());
      REQUIRE_FALSE(i.is_file());
   }

   /**
    * @brief test case #2
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/rebrand/librandom.sol build/testarea/librandom.so");
   pathname = "build/testarea/";
   filename = "librandom.so";
   fullpath = pathname + filename;
   {
      extras::file::File dock(fullpath);
      Interface& i = dock;

      REQUIRE(i.pathname() == pathname);
      REQUIRE(i.filename() == filename);
      REQUIRE(i.fullpath() == fullpath);
      REQUIRE(i.exists());
      REQUIRE_FALSE(i.is_dir());
      REQUIRE(i.is_file());
   }
}
