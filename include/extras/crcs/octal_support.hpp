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

#ifndef _EXTRA_OCTAL_SUPPORT_HPP
#define _EXTRA_OCTAL_SUPPORT_HPP

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief OctalInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   * Part of my Post Graduate program from Purdue University
   * in Data Science, (Machine Learning and AI) was to train
   * models in how to predict the future. Several of these
   * models prefer to work only in numbers. So, converting the
   * chess position from 'a1' to '00' becomes useful.
   *
   */

  interface OctalInterface {
    /**
     * @brief toOctal
     * Convert two chars 'a1' thru to 'h8' to anywhere between 00 to 77.
     * @return int (00 to 77)
     * @exception an out of range exception should be expected
     */
    virtual int toOctal() const pure;

    /**
     * @brief fromOctal
     * Convert two digets anywhere between 00 to 77 to 'a1' thru to 'h8'.
     * @param octal (00 to 77)
     * @exception an out of range exception should be expected
     */
    virtual void fromOctal(int octal) pure;
  };

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class OctalException extends AbstractCustomException {
   public:
    OctalException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &row_col, const WhereAmI &ref) {
      if (row_col.length() != 2 || row_col[0] < 'a' || row_col[0] > 'h' ||
          row_col[1] < '0' || row_col[0] > '7') {
        throw OctalException(row_col.c_str(), ref);
      }
    }
    static void assertion(int octalValue, const WhereAmI &ref) {
      if (octalValue < 0 || octalValue > 7) {
        throw SpecificCustomException(std::to_string(octalValue).c_str(), ref);
      }
    }
  };

}  // namespace extras

#endif  // _EXTRA_OCTAL_SUPPORT_HPP
