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
   * @brief BinInterface
   *
   * Maintains a binrary array in memory
   */

  using BinArray = std::vector<byte>;

  interface BinInterface {
    virtual const byte *array() const pure;
    virtual int size() const pure;
    virtual ~BinInterface(){};
    bool operator==(const BinInterface &rhs) const {
      if (size() != rhs.size()) return false;
      auto p1 = this->array();
      auto p2 = rhs.array();
      for (auto i = 0; i < size(); i++)
        if (*p1++ != *p2++) return false;
      return true;
    }
  };

  /**
   * @brief HexInterface
   *
   * Maintains a hdex array in memory
   */

  using HexLine = std::string;
  using HexArray = std::vector<std::string>;

  interface HexInterface {
    virtual HexArray array() const pure;
    virtual int lines() const pure;
    virtual int size() const pure;
    virtual ~HexInterface(){};
    bool operator==(const HexInterface &rhs) const {
      return array() == rhs.array();
    }
  };

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
