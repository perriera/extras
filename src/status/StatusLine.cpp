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
 * The above copyright notice and  this permission  notice shall be
 * included in all copies or  substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESSED  OR   IMPLIED,  INCLUDING   BUT  NOT  LIMITED  TO  THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE
 * AND NON-INFRINGEMENT.  IN  NO  EVENT  SHALL EXPARX  INCORPORATED
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM, OUT  OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Except  as  contained  in this  notice, the  name of  the EXPARX
 * INCORPORATED shall not  be used in  advertising or  otherwise to
 * promote the sale, use or other dealings in this Software without
 * prior written authorization from EXPARX INCORPORATED.
 *
 * exparx.com and www.exparx.com  are domain names  registered with
 * EXPARX INCORPORATED, (other GPL-themed licenses are included).
 *
 */

#include <extras/devices/ansi_colors.hpp>
#include <extras/status/StatusLine.hpp>
#include <extras/strings.hpp>
#include <iostream>

using namespace std;

namespace extras {

  std::string right() {
    stringstream ss;
    ss << extras::green << '[';
    return ss.str();
  }

  std::string left() {
    stringstream ss;
    ss << extras::green << ']';
    return ss.str();
  }

  std::string status(char c) {
    stringstream ss;
    ss << right() << extras::yellow << c << left();
    return ss.str();
  }

  StatusLineMsg StatusLine::start(const StatusLineMsg& msg) const {
    auto parts = extras::split(msg, '/');
    std::stringstream ss;
    ss << status('+') << extras::cyan << " " << parts[parts.size() - 1]
       << " started " << extras::blue;
    return ss.str();
  }

  StatusLineMsg StatusLine::end(const StatusLineMsg& msg) const {
    auto parts = extras::split(msg, '/');
    std::stringstream ss;
    ss << status('+') << extras::cyan << " " << parts[parts.size() - 1]
       << " ended " << extras::blue;
    return ss.str();
  }

  StatusLineMsg StatusLine::pass(const StatusLineMsg& msg) const {
    std::stringstream ss;
    ss << status('+') << extras::magenta << " " << msg << "." << extras::reset;
    return ss.str();
  }

  StatusLineMsg StatusLine::fail(const StatusLineMsg& msg) const {
    std::stringstream ss;
    ss << status('-') << extras::red << " " << msg << "." << extras::reset;
    return ss.str();
  }

}  // namespace extras
