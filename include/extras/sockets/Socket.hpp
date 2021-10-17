#ifndef _EXTRA_SOCKET_HPP
#define _EXTRA_SOCKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

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
    virtual void connect() pure;
    virtual void send(const std::string &msg) pure;
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
    int _socket;
    struct sockaddr_in _serv_addr;

   public:
    Socket(const std::string &hostname, int port);
    virtual void connect();
    virtual void send(const std::string &msg);
    virtual const InputStreamInterface &getInputStream() const {
      return InputStream();
    };
  };

  /**
   * @brief SocketException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class SocketException extends AbstractCustomException {
   public:
    SocketException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertLTZ(int socket, const std::string &msg,
                          const WhereAmI &ref);
    static void assertLTEQZ(int socket, const std::string &msg,
                            const WhereAmI &ref);
    static void assertZERO(int socket, const std::string &msg,
                           const WhereAmI &ref);
    static void assertNEQZ(int socket, const std::string &msg,
                           const WhereAmI &ref);
  };

}  // namespace extras

#endif  // _EXTRA_SOCKET_HPP
