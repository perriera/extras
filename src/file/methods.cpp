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

#include <extras/file/clazz.hpp>
#include <extras/filesystem/files.hpp>
#include <extras/strings/string_support.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using namespace extras;

/**
 * @brief exists()
 *
 * @return true
 * @return false
 */
bool file::File::exists() const {
  ifstream f(filename().c_str());
  return f.good();
}