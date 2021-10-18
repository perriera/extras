#ifndef _EXTRA_BINFILE_HPP
#define _EXTRA_BINFILE_HPP

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

  concrete class BinFile implements BinInterface {
    byte *_array = nullptr;
    int _size;

   public:
    virtual const byte *array() const override { return _array; }
    virtual int size() const override { return _size; }
  };

}  // namespace extras

#endif  // _EXTRA_BINFILE_HPP
