#ifndef _EXTRA_BINCONVERTER_HPP
#define _EXTRA_BINCONVERTER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/ConvertBin2Hex.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief BinInterface
   *
   * Maintains a binrary array in memory
   */

  concrete class BinConverter implements Hex2BinInterface {
   public:
    virtual BinArray hex2bin(const HexInterface &hex) const override;
  };

}  // namespace extras

#endif  // _EXTRA_BINCONVERTER_HPP
