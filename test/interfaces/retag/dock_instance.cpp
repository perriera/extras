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
#include <extras/retag/clazz.hpp>
#include <extras/strings.hpp>
#include <extras/version.hpp>
#include <iostream>
#include <sstream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras::retag;
using namespace extras;

/**
 * @brief dock retag::Interface
 *
 */
SCENARIO("Dock retag::Interface", "[dock retag::Interface]")
{
   /**
    * @brief determine fullpath
    *
    */
   Number major_no = std::to_string(EXTRAS_VER_MAJOR);
   Number minor_no = std::to_string(EXTRAS_VER_MINOR);
   Number patch_no = std::to_string(EXTRAS_VER_PATCH);
   Filename testarea = "build/testarea/";
   Filename filename = "libsisutil.so";
   Filename fullpath = testarea + filename;
   Filename symlink1 = fullpath + "." + major_no;
   Filename symlink2 = symlink1 + "." + minor_no;
   Filename symlink3 = symlink2 + "." + patch_no;
   Filename before = testarea + filename;
   Filename after = symlink3;

   /**
    * @brief construct dock for interface
    *
    */
   retag::Instance dock(fullpath, major_no, minor_no, patch_no);
   retag::Interface& i = dock;
   retag::test(i);
}
