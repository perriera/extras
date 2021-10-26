#include "extras/sockets/CSocketServer.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  CSocketServer::CSocketServer(int port) : _port(port) {
    this->_opt = 1;
    this->_addrlen = sizeof(_address);

    // Creating socket file descriptor
    _server_fd = socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertLTEQZ(_server_fd, "Socket creation error", __INFO__);

    // Forcefully attaching socket to the port 8080
    auto test = setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                           &this->_opt, sizeof(this->_opt));
    SocketException::assertZERO(test, "setsockopt", __INFO__);

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(_port);

    // Forcefully attaching socket to the port 8080
    test = bind(_server_fd, (struct sockaddr *)&_address, sizeof(_address));
    SocketException::assertLTZ(test, "bind failed", __INFO__);

    test = listen(_server_fd, 3);
    SocketException::assertLTZ(test, "listen", __INFO__);
  }

  void CSocketServer::accept() {
    _new_socket = ::accept(_server_fd, (struct sockaddr *)&_address,
                           (socklen_t *)&_addrlen);
    if (_proxy != nullptr) {
      delete _proxy;
      _proxy = nullptr;
    }
    _proxy = new Socket(this->_new_socket);
    SocketException::assertLTZ(_new_socket, "accept", __INFO__);
  }

}  // namespace extras