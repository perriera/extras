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
#include <fstream>
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
   When(Method(mold, fullpath)).AlwaysDo([&i, &fullpath]() {
      return fullpath;
   });
   When(Method(mold, seperator)).AlwaysDo([]() { return '/'; });
   When(Method(mold, tempname)).AlwaysDo([]() {
      char filename[] = "/tmp/mytemp.XXXXXX";
      int fd = mkstemp(filename);
      extras::Pathname tn = filename;
      CouldNotCreateTempnameException::assertion(fd, tn, __INFO__);
      close(fd);
      unlink(filename);
      return tn;
   });
   When(Method(mold, pathname)).AlwaysDo([&i]() {
      if (i.fullpath().length() == 0)
         return i.fullpath();
      auto parts = extras::str::split(i.fullpath(), i.seperator());
      parts.pop_back();
      extras::Filename result;
      for (auto part : parts) {
         result += part;
         result += i.seperator();
      }
      return result;
   });
   When(Method(mold, filename)).AlwaysDo([&i]() {
      if (i.fullpath().length() == 0)
         return i.fullpath();
      auto parts = extras::str::split(i.fullpath(), i.seperator());
      extras::Filename result = parts.back();
      return result;
   });
   When(Method(mold, is_dir)).AlwaysDo([&i]() {
      if (!i.exists())
         return false;
      extras::Filename fp = i.fullpath();
      struct stat sb;
      if (stat(fp.c_str(), &sb) == 0 && (sb.st_mode & S_IFDIR))
         return true;
      return false;
   });
   When(Method(mold, is_file)).AlwaysDo([&i]() {
      return i.exists() && !i.is_dir();
   });
   When(Method(mold, exists)).AlwaysDo([&i]() {
      extras::Filename fp = i.fullpath();
      std::ifstream in(fp);
      return in.good();
   });

   /**
    * @brief test case
    *
    */

   REQUIRE(extras::str::starts_with(i.tempname(), "/tmp/mytemp."));
   REQUIRE(i.pathname() == pathname);
   REQUIRE(i.filename() == filename);
   REQUIRE(i.fullpath() == fullpath);
   REQUIRE_FALSE(i.exists());
   REQUIRE_FALSE(i.is_dir());
   REQUIRE_FALSE(i.is_file());

   /**
    * @brief test case #2
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/renumber/librandom.sol build/testarea/librandom.so");

   pathname = "build/testarea/";
   filename = "librandom.so";
   fullpath = pathname + filename;

   REQUIRE(i.pathname() == pathname);
   REQUIRE(i.filename() == filename);
   REQUIRE(i.fullpath() == fullpath);
   REQUIRE(i.exists());
   REQUIRE_FALSE(i.is_dir());
   REQUIRE(i.is_file());

   /**
    * @brief verify the desired methods were tested
    *
    */

   Verify(Method(mold, filename));
   Verify(Method(mold, pathname));
   Verify(Method(mold, fullpath));
   Verify(Method(mold, is_dir));
   Verify(Method(mold, is_file));
   Verify(Method(mold, exists));
}
