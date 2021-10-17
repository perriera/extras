#ifndef _EXTRA_SOCKET_HPP
#define _EXTRA_SOCKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketInterface {
    virtual void send(const std::string &msg) pure;
    virtual SocketInterface &read(int expectedMaxSize) pure;
    virtual ~SocketInterface() {}
    virtual operator std::string() const pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class Socket implements SocketInterface {
    int _socket;
    byte *_readMsg = nullptr;
    int _readMsgSize;

   public:
    Socket(int socket);
    virtual ~Socket() {
      if (_readMsg != nullptr) {
        delete _readMsg;
        _readMsg = nullptr;
      }
    }
    virtual void send(const std::string &msg) override;
    virtual SocketInterface &read(int expectedMaxSize = 1024) override;
    operator std::string() const override;
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
