#ifndef _EXTRA_STATUSLINE_HPP
#define _EXTRA_STATUSLINE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief StatusLineInterface
   *
   * Maintains a binary array in memory
   */

  interface StatusLineInterface {
    virtual const std::string line() const pure;
    virtual int size() const pure;
    virtual ~StatusLineInterface(){};
    bool operator==(const StatusLineInterface &rhs) const {
      return line() == rhs.line();
    }
  };

}  // namespace extras

#endif  // _EXTRA_STATUSLINE_HPP
