#ifndef _EXTRA_CLIENTSOCKET_HPP
#define _EXTRA_CLIENTSOCKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>

#include "Socket.hpp"

namespace extras {

  /**
   * @brief SocketClientInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketClientInterface {
    virtual void connect() pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class SocketClient implements SocketClientInterface with
      SocketInterface {
    const std::string _hostname;
    int _port;
    int _socket;
    struct sockaddr_in _serv_addr;
    byte *_readMsg = nullptr;
    int _readMsgSize;

   public:
    SocketClient(const std::string &hostname, int port);
    virtual ~SocketClient() {
      if (_readMsg != nullptr) {
        delete _readMsg;
        _readMsg = nullptr;
      }
    }
    virtual void connect();
    virtual void send(const std::string &msg);
    virtual void read(int expectedMaxSize = 1024);
    operator std::string();
  };

}  // namespace extras

#endif  // _EXTRA_CLIENTSOCKET_HPP
