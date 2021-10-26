#ifndef _EXTRA_SOCKETSERVER_HPP
#define _EXTRA_SOCKETSERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/sockets/Socket.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketServerInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketServerInterface extends SocketInterface {
    virtual void accept() pure;
    virtual void close() pure;
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class SocketServer implements SocketServerInterface {
    int _port;
    int _server_fd;
    int _opt;
    struct sockaddr_in _address;
    int _addrlen;
    int _new_socket;

    SocketInterface *_proxy = nullptr;

   public:
    SocketServer(int port);
    virtual ~SocketServer() {
      if (_proxy != nullptr) {
        delete _proxy;
        _proxy = nullptr;
      }
    }
    virtual void accept() override;
    virtual void close() override;
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
