#ifndef _EXTRA_RSISERVICETYPE_HPP
#define _EXTRA_RSISERVICETYPE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/RequestType.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {

    /**
     * @brief ServiceTypeInterface
     *
     * Turn the RequestType into an actual Linux shell command
     *
     */

    using ServiceType = std::string;
    using ServiceTypeList = std::vector<ServiceType>;
    using ServiceTypeMap = std::map<ServiceType,ServiceType>;

    interface ServiceTypeCompilerInterface {
      virtual ServiceTypeList clients(
          const RequestTypeList& requests) const pure;
      virtual ServiceTypeList servers(
          const RequestTypeList& requests) const pure;
    };

    // concrete class ServiceTypeCompiler implements
    // RequestTypeCompilerInterface {
    //  public:
    //   virtual RequestTypeCompilation compile(
    //       const SocketPoolParametersInterface &client,
    //       PortAuthorityInterface &portAuthority) const override;
    //   virtual RequestTypeCompilation compile(
    //       const SocketPoolParametersInterface &client) const {
    //     return compile(client, PortAuthority::instance());
    //   }
    // };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISERVICETYPE_HPP
