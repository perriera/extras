#ifndef _EXTRA_OCTAL_SUPPORT_HPP
#define _EXTRA_OCTAL_SUPPORT_HPP

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

}  // namespace extras

#endif  // _EXTRA_OCTAL_SUPPORT_HPP
