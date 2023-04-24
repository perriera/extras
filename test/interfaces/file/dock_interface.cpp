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
using namespace extras;

/**
 * @brief file::Interface NotFoundException
 *
 */
SCENARIO("mold file::Interface::path", "[dock file::Interface]")
{
   Filename f1 = "build/libextras.so";
   file::File file(f1);
   // Pathname p1 = file.path();
   REQUIRE_THROWS_AS(file::NotFoundException::assertion("/usr/abc", __INFO__),
                     file::NotFoundException);
}
