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
  virtual int toOctal() const = 0;
  virtual void fromOctal(int octal) = 0;
};

}


#endif // _EXTRA_OCTAL_SUPPORT_HPP
