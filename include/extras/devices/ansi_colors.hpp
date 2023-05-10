/**
 * @file ansi_colors.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief ANSI colors implementation
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRA_COLORS_HPP
#define _EXTRA_COLORS_HPP

/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include <iostream>

//
// simplest ansi color c++ implementation
// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
//
namespace extras {

   struct colors
   {
      const char* black();
      const char* red();
      const char* green();
      const char* yellow();
      const char* blue();
      const char* magenta();
      const char* cyan();
      const char* white();
      const char* set();
      const char* reset();
   };

#define declare_color(n, v) std::ostream& n(std::ostream& out)

   declare_color(black, 30);
   declare_color(red, 31);
   declare_color(green, 32);
   declare_color(yellow, 33);
   declare_color(blue, 34);
   declare_color(magenta, 35);
   declare_color(cyan, 36);
   declare_color(white, 37);
   declare_color(reset, 0);

#define define_color(n, v)                                                     \
   std::ostream& n(std::ostream& out)                                          \
   {                                                                           \
      out << "\u001b[" << std::dec << v << "m";                                \
      return out;                                                              \
   }

} // namespace extras

#endif // _EXTRA_COLORS_HPP
