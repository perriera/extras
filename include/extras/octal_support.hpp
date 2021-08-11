#ifndef _EXTRA_OCTAL_SUPPORT_HPP
#define _EXTRA_OCTAL_SUPPORT_HPP

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
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
