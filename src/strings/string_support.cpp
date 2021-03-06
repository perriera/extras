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

#include <string.h>

#include <extras/exceptions.hpp>
#include <extras/strings/string_support.hpp>

namespace extras {

  std::deque<std::string> split(const std::string &s, char delim) {
    std::deque<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
      result.push_back(item);
    }

    return result;
  }

  std::string replace_all(const std::string &s, char a, char b) {
    std::string dup = s;
    replace(dup.begin(), dup.end(), a, b);
    return dup;
  }

  std::string remove_all(const std::string &s, char a) {
    std::string dup = s;
    dup.erase(std::remove(dup.begin(), dup.end(), a), dup.end());
    return dup;
  }

  std::string replace_all(std::string str, const std::string &from,
                          const std::string &to) {
    std::size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
      str.replace(start_pos, from.length(), to);
      start_pos +=
          to.length();  // Handles case where 'to' is a substring of 'from'
    }
    return str;
  }

  std::string replace_last(const std::string &str, const std::string &from,
                           const std::string &to, char delim) {
    StringContainsDelimException::assertion(str, delim, __INFO__);
    if (!contains(str, from)) return str;
    if (from.size() == 0) return str;
    std::string dup_str = str;
    std::string dup_from = from;
    std::string dup_to = to;
    reverse(dup_str.begin(), dup_str.end());
    reverse(dup_from.begin(), dup_from.end());
    reverse(dup_to.begin(), dup_to.end());
    auto it = dup_str.find(dup_from);
    if (it != std::string::npos) {
      auto parta = dup_str.substr(0, it);
      auto partb = dup_str.substr(it + dup_from.size());
      auto newStr = parta + dup_to + partb;
      reverse(newStr.begin(), newStr.end());
      return newStr;
    }
    return str;
  }

  void StringContainsDelimException::assertion(const std::string &str,
                                               char delim,
                                               const extras::WhereAmI &ref) {
    std::string test;
    test += delim;
    if (contains(str, test))
      throw StringContainsDelimException(str, delim, ref);
  }

}  // namespace extras
