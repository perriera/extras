#ifndef _EXTRA_STRING_SUPPORT_HPP
#define _EXTRA_STRING_SUPPORT_HPP

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

#include <algorithm>
#include <cctype>
#include <deque>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

namespace extras {
  // trim from start (in place)
  static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
              return !std::isspace(ch);
            }));
  }

  // trim from end (in place)
  static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](unsigned char ch) { return !std::isspace(ch); })
                .base(),
            s.end());
  }

  // trim from both ends (in place)
  static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
  }

  // trim from start (copying)
  static inline std::string ltrim_copy(const std::string &s) {
    auto dup = s;
    ltrim(dup);
    return dup;
  }

  // trim from end (copying)
  static inline std::string rtrim_copy(const std::string &s) {
    auto dup = s;
    rtrim(dup);
    return dup;
  }

  // trim from both ends (copying)
  static inline std::string trim_copy(const std::string &s) {
    auto dup = s;
    trim(dup);
    return dup;
  }

  std::deque<std::string> split(const std::string &s, char delim);
  std::string replace_all(const std::string &s, char a, char b);
  std::string remove_all(const std::string &s, char a);
  std::string replace_all(std::string str, const std::string &from,
                          const std::string &to);

  inline bool ends_with(std::string const &value, std::string const &ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
  }

  inline bool starts_with(std::string const &value,
                          std::string const &beginning) {
    return value.rfind(beginning, 0) == 0;
  }

  inline bool contains(std::string const &s1, std::string const &s2) {
    return s1.find(s2) != std::string::npos;
  }

  inline std::string to_lower(const std::string &data) {
    std::string dup = data;
    std::transform(dup.begin(), dup.end(), dup.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return dup;
  }

  // cout << plusone(42);
  template <typename T>
  std::string plusone(T const &t) {
    std::ostringstream oss;
    oss << (t + 1);
    return oss.str();
  }
}  // namespace extras

#endif  // _EXTRA_STRING_SUPPORT_HPP
