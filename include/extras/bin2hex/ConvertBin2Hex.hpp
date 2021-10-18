#ifndef _EXTRA_BIN2HEX_HPP
#define _EXTRA_BIN2HEX_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/BinInterface.hpp>
#include <extras/bin2hex/HexInterface.hpp>
#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief Bin2HexInterface
   *
   * Converts a bin array to a hex array
   *
   */

  interface Bin2HexInterface {
    virtual HexArray bin2hex(const BinInterface &bin) const pure;
    virtual ~Bin2HexInterface() {}
  };

  /**
   * @brief Hex2BinInterface
   *
   * Converts a hex array to a bin array
   *
   */

  interface Hex2BinInterface {
    virtual BinArray hex2bin(const HexInterface &hex) const pure;
    virtual ~Hex2BinInterface() {}
  };

}  // namespace extras

#endif  // _EXTRA_BIN2HEX_HPP
