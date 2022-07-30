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

#include <fstream>
#include <iostream>

#include "extras/file/class.hpp"
#include "extras/filesystem/files.hpp"
#include "extras/strings/string_support.hpp"

using namespace std;
using namespace extras;

namespace extras {
  namespace system {

    void FileNotFoundException::assertion(const Filename& filename,
                                          const WhereAmI& ref) {
      ifstream f(filename.c_str());
      if (!f.good()) throw FileNotFoundException(filename, ref);
    }

    void FileNotCopiedException::assertion(const FileInterface& fi,
                                           const WhereAmI& ref) {
      ifstream f(fi.filename().c_str());
      if (!f.good()) throw FileNotCopiedException(fi.filename(), ref);
    }

    void FilenameInvalidException::assertion(const Filename& filename,
                                             const WhereAmI& ref) {
      if (filename.empty())
        throw FilenameInvalidException("no filename specified", ref);
    }

  }  // namespace system
}  // namespace extras
