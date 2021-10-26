#ifndef _EXTRA_PORTAUTHORITY_HPP
#define _EXTRA_PORTAUTHORITY_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <extras/sockets/SocketPackets.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief PortAuthorityInterface
   *
   * Determine what ports are available.
   *
   */

  using PortDomainName = std::string;
  using PortNumber = int;
  using PortServerNumber = int;
  using PortRangeStart = int;
  using PortRangeSize = int;

  interface PortAuthorityInterface {
    virtual PortDomainName domainName() const pure;
    virtual PortNumber request() pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class PortAuthority implements PortAuthorityInterface {
    PortDomainName _name;
    PortServerNumber _port;
    PortServerNumber _start;
    PortServerNumber _size;

   public:
    PortAuthority(const PortDomainName& name, PortNumber port = 8080,
                  PortRangeStart start = 9000, PortRangeSize size = 1000)
        : _name(name), _port(port), _start(start), _size(size){};
    virtual PortDomainName domainName() const override { return _name; };
    virtual PortNumber request() override;
  };

}  // namespace extras

#endif  // _EXTRA_PORTAUTHORITY_HPP
