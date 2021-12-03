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
#include <iostream>

namespace extras {

  std::string AbstractCustomException::_lastThrownException;

  std::ostream &operator<<(std::ostream &os,
                           const ExtrasExceptionInterface &dt) {
    std::string file = dt.getfile();
    long unsigned int cnt = file.size();
    std::string div1, div2;
    for (int i = 0; i < file.size(); i++) {
      div1 += "=";
      div2 += "-";
    }

    os << extras::green;
    os << div1 << std::endl;
    os << extras::yellow;
    os << dt.demangle(dt.getwhat().c_str());
    os << extras::cyan << ": ";
    os << extras::white;
    os << dt.msg() << std::endl;
    os << extras::green;
    os << div2 << std::endl;
    os << extras::blue << dt.getfile() << std::endl;
    os << dt.getfunc();
    os << extras::cyan << ": line ";
    os << dt.getline() << std::endl;
    os << extras::green;
    os << div1 << std::endl;
    return os;
  }

}  // namespace extras
