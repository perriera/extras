#ifndef _EXTRA_REQUESTS_HPP
#define _EXTRA_REQUESTS_HPP

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

  using RequestedService = std::string;

  interface RequestsInterface {
    virtual PortNumber request(const RequestedService& serviceName,
                               const PortServerNumber& serverSocket) pure;
  };

  /**
   * @brief Services class
   *
   */

  concrete class Requests implements RequestsInterface {
   public:
    virtual PortNumber request(const RequestedService& serviceName,
                               const PortServerNumber& serverSocket) override;
  };

}  // namespace extras

#endif  // _EXTRA_REQUESTS_HPP
