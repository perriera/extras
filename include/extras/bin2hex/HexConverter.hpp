#ifndef _EXTRA_HEXCONVERTER_HPP
#define _EXTRA_HEXCONVERTER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/ConvertBin2Hex.hpp>
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

  concrete class HexConverter implements Bin2HexInterface {
   public:
    virtual HexArray bin2hex(const BinInterface &bin) const override;
  };

}  // namespace extras

#endif  // _EXTRA_HEXCONVERTER_HPP