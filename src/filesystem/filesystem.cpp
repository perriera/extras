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

#include <extras/filesystem/filesystem.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

namespace extras {

  FileSystem::FileSystem(const Path& path) {
    std::string a = path;
    fs::path p = path;
    std::string b = p.filename();
    auto parts = split(b, '.');
    std::string c;
    std::string d;
    std::string e;
    if (parts.size() == 2) {
      c = parts[0];
      e = parts[1];
    } else
      c = b;
    d = extras::replace_last(a, b, "");
    d = extras::replace_all(d, "//", "/");
    /////
    _path = path;
    _pathname = d;
    _filename = c;
    _extension = e;
  }

}  // namespace extras
