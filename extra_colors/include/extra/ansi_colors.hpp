#ifndef _EXTRA_COLORS_HPP
#define _EXTRA_COLORS_HPP

#include "extra/Definitions.hpp"
#include <iostream>

//
// simplest ansi color c++ implementation
// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
//

interface colors {

  const char *black();
  const char *red();
  const char *green();
  const char *yellow();
  const char *blue();
  const char *magenta();
  const char *cyan();
  const char *white();
  const char *set();
  const char *reset();
};

#define declare_color(n, v) std::ostream &n(std::ostream &out);

#define define_color(n, v)                                                     \
  std::ostream &n(std::ostream &out) {                                         \
    out << "\u001b[" << std::dec << v << "m";                                  \
    return out;                                                                \
  }

declare_color(black, 30);
declare_color(red, 31);
declare_color(green, 32);
declare_color(yellow, 33);
declare_color(blue, 34);
declare_color(magenta, 35);
declare_color(cyan, 36);
declare_color(white, 37);
declare_color(reset, 0);

#endif // _EXTRA_COLORS_HPP
