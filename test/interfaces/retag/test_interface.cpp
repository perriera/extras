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
namespace extras {
   namespace retag {

      void test(Interface& i)
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
      }

   }
}
