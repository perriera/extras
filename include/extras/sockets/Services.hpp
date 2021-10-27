#ifndef _EXTRA_SERVICES_HPP
#define _EXTRA_SERVICES_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <extras/sockets/Requests.hpp>
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

  interface ServicesInterface {
    virtual RequestedService request(const PortNumber &serverSocket) pure;
    virtual PortNumber lastPortRequested() const pure;
  };

  /**
   * @brief Services class
   *
   */

  concrete class Services implements ServicesInterface {
    extras::PortAuthority _portAuthority;
    extras::PortNumber _lastPortRequested;

   public:
    virtual RequestedService request(const PortNumber &serverSocket) override;
    virtual PortNumber lastPortRequested() const override {
      return _lastPortRequested;
    };
  };

}  // namespace extras

#endif  // _EXTRA_SERVICES_HPP
