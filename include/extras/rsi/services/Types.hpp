#ifndef _EXTRA_RSITYPES_HPP
#define _EXTRA_RSITYPES_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/RequestType.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

namespace extras {
  namespace rsi {

    /**
     * @brief ServiceTypeInterface
     *
     * Turn the RequestType into an actual Linux shell command
     *
     */

    using RequestType = std::string;
    using RequestTypeList = std::vector<RequestType>;

    using ServiceType = std::string;
    using ServiceTypeList = std::vector<ServiceType>;
    using ServiceTypeMap = std::map<ServiceType, ServiceType>;

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSITYPES_HPP
