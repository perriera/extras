#ifndef _EXTRA_BINFILE_HPP
#define _EXTRA_BINFILE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/BinInterface.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/language/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief BinInterface
   *
   * Maintains a binrary array in memory
   */

  concrete class BinFile implements BinInterface {
    friend std::ostream& operator<<(std::ostream& out, const BinFile& obj);
    friend std::istream& operator>>(std::istream& in, BinFile& obj);

    byte* _array = nullptr;
    int _size = 0;

   public:
    BinFile(){};
    BinFile(const BinArray& binArray);

    virtual const byte* array() const override { return _array; }
    virtual int size() const override { return _size; }
  };

}  // namespace extras

#endif  // _EXTRA_BINFILE_HPP
