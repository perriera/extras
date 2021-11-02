#ifndef _EXTRA_RSISOCKETPOOL_HPP
#define _EXTRA_RSISOCKETPOOL_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {
    /**
     * @brief SocketPoolInterface
     *
     * The idea is that we assign a port to be the authority on deligating
     * available port numbers, (from a range of port numbers). At the basic
     * level a series of predefined tokens are given to this interface. If all
     * tokens are reconized then a port number is returned for each token.
     *
     */

    using Socket = int;
    using PortNumberPool = std::vector<PortNumber>;
    using SocketRequestType = std::string;
    using SocketRequestTypeList = std::vector<SocketRequestType>;

    interface SocketPoolInterface {
      virtual SocketRequestTypeList types() const pure;
      virtual PortNumberPool request(
          const PortNumber& portNumber,
          const SocketRequestTypeList& requests) pure;
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISOCKETPOOL_HPP
