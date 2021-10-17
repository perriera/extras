#ifndef _EXTRA_SOCKET_HPP
#define _EXTRA_SOCKET_HPP

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

#include "InputStream.hpp"

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketInterface {
    virtual const InputStreamInterface &getInputStream() const pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class Socket implements SocketInterface {
    const std::string _hostname;
    int _port;

   public:
    Socket(const std::string &hostname, int port)
        : _hostname(hostname), _port(port) {}
  };

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class SocketException extends AbstractCustomException {
   public:
    SocketException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &hostname, int port,
                          const WhereAmI &ref);
  };

}  // namespace extras

#endif  // _EXTRA_SOCKET_HPP
