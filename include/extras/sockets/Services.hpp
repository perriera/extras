#ifndef _EXTRA_SERVICES_HPP
#define _EXTRA_SERVICES_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief RequestInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  using ServiceName = std::string;

  interface ServicesInterface {
    virtual PortNumber request(const ServiceName &msg) pure;
  };

}  // namespace extras

#endif  // _EXTRA_SERVICES_HPP
