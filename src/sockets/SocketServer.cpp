#include "extras/sockets/SocketServer.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  SocketServer::SocketServer(int port) : _port(port) {
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

  void SocketServer::accept() {
    _new_socket = ::accept(_server_fd, (struct sockaddr *)&_address,
                           (socklen_t *)&_addrlen);
    SocketException::assertLTZ(_new_socket, "accept", __INFO__);
  }

  void SocketServer::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_new_socket, _msg, strlen(_msg), 0);
  }

  void SocketServer::read(int expectedMaxSize) {
    byte buffer[expectedMaxSize];
    this->_readMsgSize = ::read(this->_new_socket, buffer, expectedMaxSize);
    SocketException::assertLTZ(_new_socket, "read", __INFO__);
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = buffer[i];
    }
  }

  SocketServer::operator std::string() {
    std::stringstream ss;
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      ss << *ptr++;
    }
    return ss.str();
  }

}  // namespace extras