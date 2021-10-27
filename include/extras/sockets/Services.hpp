#ifndef _EXTRA_SERVICES_HPP
#define _EXTRA_SERVICES_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief ServicesInterface, (PE-18)
   *
   * GIVEN we need different types of services to run on the server port WHEN we
   * indicate what kind of service to run on the server port THEN the client
   * code can know what to expect on the server port
   *
   */

  using ServiceName = std::string;

  interface ServicesInterface {
    virtual PortNumber request(const ServiceName &serviceName,
                               const PortNumber &serverSocket) pure;
  };

  /**
   * @brief Services class
   *
   */

  concrete class Services implements ServicesInterface {
    PortDomainName _domainName;
    PortAuthority _portAuthority;

   public:
    Services(PortDomainName domainName, PortNumber port = 8080)
        : _domainName(domainName), _portAuthority(port) {}
    virtual PortNumber request(const ServiceName &serviceName,
                               const PortNumber &serverSocket) override;
  };

}  // namespace extras

#endif  // _EXTRA_SERVICES_HPP
