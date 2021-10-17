#ifndef _EXTRA_SOCKETSERVER_HPP
#define _EXTRA_SOCKETSERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

#include "Socket.hpp"

namespace extras {

  /**
   * @brief SocketServerInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketServerInterface {
    virtual void accept() pure;
    virtual void send(const std::string &msg) pure;
    virtual void read(int expectedMaxSize) pure;
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
    byte *_readMsg = nullptr;
    int _readMsgSize;

   public:
    SocketServer(int port);
    virtual void accept();
    virtual void send(const std::string &msg);
    virtual void read(int expectedMaxSize = 1024);
    operator std::string();
  };

}  // namespace extras

#endif  // _EXTRA_SOCKETSERVER_HPP
