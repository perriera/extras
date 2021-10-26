#ifndef _EXTRA_SOCKETCSERVER_HPP
#define _EXTRA_SOCKETCSERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/sockets/Socket.hpp>
#include <extras/sockets/SocketServer.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class CSocketServer implements SocketServerInterface {
    int _port;
    int _server_fd;
    int _opt;
    struct sockaddr_in _address;
    int _addrlen;
    int _new_socket;

    SocketInterface *_proxy = nullptr;

   public:
    CSocketServer(int port);
    virtual ~CSocketServer() {
      if (_proxy != nullptr) {
        delete _proxy;
        _proxy = nullptr;
      }
    }
    virtual void accept() override;
    virtual void send(const std::string &msg) override { _proxy->send(msg); }
    virtual SocketInterface &read(int expectedMaxSize = 1024) override {
      return _proxy->read(expectedMaxSize);
    }

    operator std::string() const override {
      std::string msg = *((Socket *)_proxy);
      return msg;
    }

    operator SocketPacket() const override {
      SocketPacket msg = *((Socket *)_proxy);
      return msg;
    }
  };

}  // namespace extras

#endif  // _EXTRA_SOCKETSERVER_HPP
