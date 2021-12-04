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

#include <extras/devices/ansi_colors.hpp>
#include <extras/exceptions.hpp>
#include <extras/strings.hpp>
#include <iostream>
#include <sstream>

namespace extras {

  std::string AbstractCustomException::_lastThrownException;

  static std::string removeEscape(const std::string &before) {
    if (before.size() == 0) return before;
    std::string after;
    bool escapeOn = false;
    for (auto c : before) {
      if (c == '\u001b' && !escapeOn) escapeOn = true;
      if (c == 'm' && escapeOn)
        escapeOn = false;
      else if (!escapeOn)
        after += c;
    }
    return after;
  }

  static int longestLine(const std::string &before) {
    long unsigned int longestLine = 0;
    auto parts = extras::split(before, '\n');
    for (auto part : parts) {
      part = removeEscape(part);
      if (part.size() > longestLine) longestLine = part.size();
    }
    return (int)longestLine;
  }

  static std::string reformatted(const std::string &before) {
    int size = longestLine(before);
    std::stringstream ss;
    std::string div1, div2;
    for (int i = 0; i < size; i++) {
      div1 += "=";
      div2 += "-";
    }
    std::string after = before;
    after = extras::replace_all(after, "YoDa", div1);
    after = extras::replace_all(after, "yOgA", div2);
    return after;
  }

  std::ostream &operator<<(std::ostream &os,
                           const ExtrasExceptionInterface &dt) {
    std::stringstream ss;
    std::string div1 = "YoDa", div2 = "yOgA";
    ss << extras::green;
    ss << div1 << std::endl;
    ss << extras::yellow;
    ss << dt.demangle(dt.getwhat().c_str());
    ss << extras::cyan << ": ";
    ss << extras::white;
    ss << dt.msg() << std::endl;
    ss << extras::green << "";
    ss << div2 << std::endl;
    ss << extras::blue << dt.getfile() << std::endl;
    ss << dt.getfunc();
    ss << extras::cyan << ": line ";
    ss << dt.getline() << std::endl;
    ss << extras::green;
    ss << div1 << std::endl;
    os << reformatted(ss.str());
    return os;
  }

}  // namespace extras
