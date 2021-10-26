#ifndef _EXTRA_HEXINTERFACE_HPP
#define _EXTRA_HEXINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief HexInterface
   *
   * Maintains a hex array in memory
   */

  using HexName = std::string;
  using HexLine = std::string;
  using HexArray = std::vector<std::string>;

  interface HexInterface {
    virtual const HexName& name() const pure;
    virtual const HexArray& array() const pure;
    virtual int lines() const pure;
    virtual int size() const pure;
    virtual ~HexInterface(){};
    bool operator==(const HexInterface& rhs) const {
      return array() == rhs.array();
    }
  };

}  // namespace extras

#endif  // _EXTRA_HEXINTERFACE_HPP
