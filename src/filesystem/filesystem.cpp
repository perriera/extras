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
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

namespace extras {

  FileSystem::FileSystem(const Path &path) {
    std::string a = trim_copy(path);
    fs::path p = a;
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
    d = extras::replace_last(path, b, "");
    d = extras::replace_all(d, "//", "/");
    /////
    _path = path;
    _pathname = d;
    _justthefilename = c;
    _justtheextension = e;
    _filename = b;
  }

  /**
   * @brief prepend/append a path to a directory name
   *
   * @param dir
   * @return const Path&
   */
  Path FileSystem::strip_first(const Directory &dir) const {
    auto dup = dir;
    if (dup.size() > 0) {
      if (dup[0] == '/') dup = dup.substr(1);
    }
    return dup;
  }

  Path FileSystem::strip_last(const Directory &dir) const {
    auto dup = dir;
    if (dup.size() > 0) {
      if (dup[dup.size() - 1] == '/') dup = dup.substr(0, dup.size() - 1);
    }
    return dup;
  }

  Path FileSystem::prepend(const Directory &dir) const {
    auto dup = strip_last(dir);
    auto dup2 = strip_first(_path);
    auto result = dup + "/" + dup2;
    return result;
  }

  Path FileSystem::append(const Directory &dir) const {
    auto dup = strip_first(dir);
    auto dup2 = strip_last(_path);
    auto result = dup2 + "/" + dup;
    return result;
  }

}  // namespace extras
