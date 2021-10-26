#ifndef _EXTRA_BININTERFACE_HPP
#define _EXTRA_BININTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief BinInterface
   *
   * Maintains a binary array in memory
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

}  // namespace extras

#endif  // _EXTRA_BININTERFACE_HPP
