#ifndef _EXTRA_BIN2HEX_HPP
#define _EXTRA_BIN2HEX_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface BinInterface {
    virtual const byte *array() const pure;
    virtual int size() const pure;
    virtual ~BinInterface(){};
  };

  using HexLine = std::string;
  using HexArray = std::vector<std::string>;

  interface HexInterface {
    virtual HexArray array() const pure;
    virtual ~HexInterface(){};
  };

  interface Bin2HexInterface {
    virtual const HexInterface &bin2hex(const BinInterface &bin) const pure;
    virtual ~Bin2HexInterface() {}
  };

  interface Hex2BinInterface {
    virtual const BinInterface &hex2bin(const HexInterface &hex) const pure;
    virtual ~Hex2BinInterface() {}
  };

}  // namespace extras

#endif  // _EXTRA_BIN2HEX_HPP
