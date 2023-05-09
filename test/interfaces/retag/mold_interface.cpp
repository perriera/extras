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
#include <extras/retag/interface.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>
#include <sstream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras::retag;
using namespace extras;
using namespace fakeit;

/**
 * @brief dock retag::Interface
 *
 */
SCENARIO("Mold retag::Interface", "[mold retag::Interface]")
{
   /**
    * @brief determine fullpath
    *
    */
   auto major_no = EXTRAS_VER_MAJOR;
   auto minor_no = EXTRAS_VER_MINOR;
   auto patch_no = EXTRAS_VER_PATCH;
   Filename testarea = "build/testarea/";
   Filename filename = "libsisutil.so";
   Filename fullpath = testarea + filename;
   Filename symlink1 = fullpath + "." + std::to_string(major_no);
   Filename symlink2 = symlink1 + "." + std::to_string(minor_no);
   Filename symlink3 = symlink2 + "." + std::to_string(patch_no);
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
      Pathname symlink1 = original + "." + i.major_no();
      Pathname symlink2 = symlink1 + "." + i.minor_no();
      Pathname symlink3 = symlink2 + "." + i.patch_no();
      Pathname script_name = file.tempname("retag.XXXXXX");
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
   When(Method(mold, major_no)).AlwaysDo([&major_no]() {
      {
         return std::to_string(major_no);
      }
   });
   When(Method(mold, minor_no)).AlwaysDo([&minor_no]() {
      {
         return std::to_string(minor_no);
      }
   });
   When(Method(mold, patch_no)).AlwaysDo([&patch_no]() {
      {
         return std::to_string(patch_no);
      }
   });
   When(Method(mold, newTag)).AlwaysDo([&i, &fullpath]() {
      extras::file::File file(fullpath);
      auto filename = file.filename();
      filename += "." + i.major_no();
      filename += "." + i.minor_no();
      filename += "." + i.patch_no();
      filename = file.pathname() + filename;
      return filename;
   });

   /**
    * @brief prepare test area
    *
    */

   system("rm -rf build/testarea");
   system("mkdir build/testarea");
   system("cp test/etc/retag/librandom.sol build/testarea/libsisutil.so");
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
   Verify(Method(mold, major_no));
   Verify(Method(mold, minor_no));
   Verify(Method(mold, patch_no));
}
