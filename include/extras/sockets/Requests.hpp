#ifndef _REQUESTS_SOCKET_HPP
#define _REQUESTS_SOCKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/language/types.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief RequestInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  using TypeOfRequest = std::string;

  interface RequestInterface extends PortAuthorityInterface {
    virtual void command(const TypeOfRequest &msg) pure;
  };

}  // namespace extras

#endif  // _REQUESTS_SOCKET_HPP
