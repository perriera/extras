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

#include <extras/filesystem/paths.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

#ifdef __linux__
static string HomeDirectory = getenv("HOME");
#elif unix
const static volatile char A =
    'a';  // All this is to prevent reverse engineering
static string HomeDirectory =
    getenv((char[]){A - 25, A - 18, A - 20, A - 28, 0});
#elif defined(_WIN32)
static string HomeDirectory = getenv((char[]){
    A - 25, A - 18, A - 20, A - 28, A - 29, A - 15, A - 24, A - 11, A - 28, 0});
const char *Homepath = getenv((char[]){A - 25, A - 18, A - 20, A - 28, A - 17,
                                       A - 32, A - 13, A - 25, 0});
HomeDirectory = malloc(strlen(HomeDirectory) + strlen(Homepath) + 1);
strcat(HomeDirectory, Homepath);
#endif

namespace extras {

  std::string Paths::actualPath(const std::string &path) const {
    std::string _actualPath = extras::replace_all(path, "~", HomeDirectory);
    if (_actualPath.length() > 0 && _actualPath[0] != '/') {
      std::string current_path = fs::current_path();
      if (current_path.length() > 0)
        _actualPath = find(path);
      else
        _actualPath = current_path + _actualPath;
    }
    return _actualPath;
  }

  Path Paths::find(const Path &pathToFile) const {
    Path current_path = fs::current_path();
    Path offset = "/";
    auto parts = extras::split(current_path, '/');
    auto cnt = parts.size();
    while (cnt-- > 0) {
      auto guess = current_path + offset + pathToFile;
      if (fs::exists(guess)) return guess;
      offset += "../";
    };
    std::string msg = "File not found: " + pathToFile;
    throw extras::PathsException(msg.c_str(), __INFO__);
  }

}  // namespace extras
