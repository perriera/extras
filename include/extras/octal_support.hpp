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
 */

interface OctalInterface {
  virtual int toOctal() const pure;
  virtual void fromOctal(int octal) pure;
};

}  // namespace extras

#endif  // _EXTRA_OCTAL_SUPPORT_HPP
