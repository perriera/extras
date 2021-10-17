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

  interface SocketClientInterface extends SocketInterface {
    virtual void connect() pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class SocketClient implements SocketClientInterface {
    const std::string _hostname;
    int _socket;
    struct sockaddr_in _serv_addr;

    SocketInterface *_proxy = nullptr;

   public:
    SocketClient(const std::string &hostname, int port);
    virtual ~SocketClient() {
      if (_proxy != nullptr) {
        delete _proxy;
        _proxy = nullptr;
      }
    }
    virtual void connect() override;
    virtual void send(const std::string &msg) override { _proxy->send(msg); }
    virtual void read(int expectedMaxSize = 1024) override {
      _proxy->read(expectedMaxSize);
    }

    operator std::string() {
      std::string msg = *((Socket *)_proxy);
      return msg;
    }
  };

}  // namespace extras

#endif  // _EXTRA_CLIENTSOCKET_HPP
