#ifndef _EXTRA_HEXFILE_HPP
#define _EXTRA_HEXFILE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexInterface.hpp>
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

  concrete class HexFile implements HexInterface {
    friend std::ostream& operator<<(std::ostream& out, const HexFile& obj);
    friend std::istream& operator>>(std::istream& in, HexFile& obj);

    HexName _name;
    HexArray _array;

   public:
    HexFile(){};
    HexFile(const HexName& name) : _name(name) {}
    HexFile(const HexArray& array) : _array(array) {}
    HexFile(const HexName& name, const HexArray& array)
        : _name(name), _array(array) {}

    virtual const HexName& name() const override { return _name; }
    virtual const HexArray& array() const override { return _array; }
    virtual int lines() const override { return _array.size(); }
    virtual int size() const override {
      int _size = 0;
      for (auto line : _array) {
        _size += line.length();
      }
      return _size;
    }
  };

}  // namespace extras

#endif  // _EXTRA_HEXFILE_HPP
