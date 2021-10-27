#ifndef _EXTRA_PORTAUTHORITY_HPP
#define _EXTRA_PORTAUTHORITY_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/language/types.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <extras/sockets/SocketPackets.hpp>
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
    /**
     * @brief serversocketport
     * @return of the primary port providing the ports
     *
     */
    virtual const PortNumber& serversocketport() const pure;

    /**
     * @brief request of the website providing the ports
     * @return a port number that can be used by connect()/accept()
     *
     * The general idea is that the port # being returned will not
     * be needed again for a while. The idea is that whatever process
     * needs that unique port # will dispense with it quickly.
     *
     * The server portion would create a seversocket with accept()
     * expecting a connect to appear, (within 7 seconds, perhaps)
     * to carry out whatever is required.
     *
     * @note It would be good to ensure that the server can timeout.
     * (aka. otherwise you can expect a port collision)
     *
     */
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
    PortServerNumber _port;
    PortServerNumber _start;
    PortServerNumber _size;
    PortServerNumber _next;

   public:
    PortAuthority(PortNumber port = 8080, PortRangeStart start = 9000,
                  PortRangeSize size = 1000)
        : _port(port), _start(start), _size(size), _next(0){};

    virtual const PortNumber& serversocketport() const override {
      return _port;
    };

    virtual PortNumber request() override;
  };

}  // namespace extras

#endif  // _EXTRA_PORTAUTHORITY_HPP
