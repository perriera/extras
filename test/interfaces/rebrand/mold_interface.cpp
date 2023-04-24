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
#include <sstream>

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
   Filename filename = "libsisutil.so";
   Filename fullpath = testarea + filename;
   Filename symlink1 = fullpath + "." + std::to_string(major);
   Filename symlink2 = symlink1 + "." + std::to_string(minor);
   Filename symlink3 = symlink2 + "." + std::to_string(patch);
   Filename before = testarea + filename;
   Filename after = symlink3;

   /**
    * @brief construct dock for interface
    *
    */
   Dock<Interface> mold;
   Interface& i = mold.get();
   When(Method(mold, execute)).AlwaysDo([&i, &fullpath]() {
      extras::file::File file(fullpath);
      Pathname original = file.filename();
      Pathname symlink1 = original + "." + i.major();
      Pathname symlink2 = symlink1 + "." + i.minor();
      Pathname symlink3 = symlink2 + "." + i.patch();
      Pathname script_name = file.tempname("rebrand.XXXXXX");
      {
         std::ofstream script(script_name);
         script << "cd " << file.pathname() << std::endl;
         script << "rm " << symlink3 << " 2>/dev/null" << std::endl;
         script << "rm " << symlink2 << " 2>/dev/null" << std::endl;
         script << "rm " << symlink1 << " 2>/dev/null" << std::endl;
         script << "mv " << original << ' ' << symlink3 << std::endl;
         script << "ln -s " << symlink3 << ' ' << symlink2 << std::endl;
         script << "ln -s " << symlink2 << ' ' << symlink1 << std::endl;
         script << "ln -s " << symlink1 << ' ' << original << std::endl;
      }
      Cmd cat = "cat " + script_name;
      system(cat.c_str());
      Cmd bash = "bash " + script_name;
      system(bash.c_str());
      Cmd rm = "rm " + script_name;
      system(rm.c_str());
      std::cout << std::endl;
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
   When(Method(mold, rebranded)).AlwaysDo([&i, &fullpath]() {
      extras::file::File file(fullpath);
      auto filename = file.filename();
      filename += "." + i.major();
      filename += "." + i.minor();
      filename += "." + i.patch();
      filename = file.pathname() + filename;
      return filename;
   });

   /**
    * @brief prepare test area
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/rebrand/librandom.sol build/testarea/libsisutil.so");
   file::NotFoundException::assertion(before, __INFO__);

   /**
    * @brief test the interface
    *
    */

   file::NotFoundException::assertion(before, __INFO__);
   file::NewFoundException::assertion(after, __INFO__);
   file::NewFoundException::assertion(symlink1, __INFO__);
   file::NewFoundException::assertion(symlink2, __INFO__);
   file::NewFoundException::assertion(symlink3, __INFO__);
   i.execute();
   file::NotFoundException::assertion(before, __INFO__);
   file::NotFoundException::assertion(after, __INFO__);
   file::NotFoundException::assertion(symlink1, __INFO__);
   file::NotFoundException::assertion(symlink2, __INFO__);
   file::NotFoundException::assertion(symlink3, __INFO__);

   /**
    * @brief verify the desired methods were tested
    *
    */
   Verify(Method(mold, execute));
   Verify(Method(mold, major));
   Verify(Method(mold, minor));
   Verify(Method(mold, patch));
}