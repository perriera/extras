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
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE  EXPARX  INCORPORATED
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

#ifndef _EXTRA_TYPES_HPP
#define _EXTRA_TYPES_HPP

/**
 * @file keywords.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Adds extra keywords for C++ applications
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

namespace extras {

  /**
   * @brief bytes
   *
   * " Of the same size as char, but guaranteed to be unsigned.
   *   Contains at least the [0, 255] range.[5] ""
   *    -- https://en.wikipedia.org/wiki/C_data_types
   *    -- Wikipedia, August 6, 2021
   *
   * [5]  ISO/IEC 9899:1999 specification, TC3 (PDF). p. 37,
   * § 6.2.6.1 Representations of types – General.
   *
   */

  using byte = unsigned char;
  using bytes = byte *;

}  // namespace extras

#endif  // _EXTRA_TYPES_HPP