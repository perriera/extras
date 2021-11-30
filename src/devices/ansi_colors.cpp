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

#include "extras/devices/ansi_colors.hpp"

#include <iostream>

using namespace std;

namespace extras {
  define_color(black, 30) define_color(red, 31) define_color(green, 32)
      define_color(yellow, 33) define_color(blue, 34) define_color(magenta, 35)
          define_color(cyan, 36) define_color(white, 37) define_color(reset, 0)
}  // namespace extras
