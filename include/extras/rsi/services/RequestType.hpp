#ifndef _EXTRA_RSIREQUESTTYPE_HPP
#define _EXTRA_RSIREQUESTTYPE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {

    /**
     * @brief RequestTypeInterface
     *
     * All the types of services that can be run on a remote server.
     *
     */

    using RequestType = std::string;
    using RequestTypeList = std::vector<RequestType>;

    interface RequestTypeCompilerInterface {
      virtual RequestTypeList compile(
          const SocketPoolClientInterface& client,
          PortAuthorityInterface& portAuthority) const pure;
    };

    concrete class RequestTypeCompiler implements RequestTypeCompilerInterface {
     public:
      virtual RequestTypeList compile(
          const SocketPoolClientInterface& client,
          PortAuthorityInterface& portAuthority) const override;
      virtual RequestTypeList compile(
          const SocketPoolClientInterface& client) const {
        return compile(client, PortAuthority::instance());
      }
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSIREQUESTTYPE_HPP
