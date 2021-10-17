#include "extras/sockets/Socket.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  Socket::Socket(int socket) : _socket(socket) {
    SocketException::assertLTZ(_socket, "socket", __INFO__);
  }

  void Socket::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_socket, _msg, strlen(_msg), 0);
  }

  SocketInterface &Socket::read(int expectedMaxSize) {
    byte *buffer = new byte[expectedMaxSize];
    this->_readMsgSize = ::read(this->_socket, buffer, expectedMaxSize);
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = buffer[i];
    }
    delete[] buffer;
    return *this;
  }

  Socket::operator std::string() const {
    std::stringstream ss;
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      ss << *ptr++;
    }
    return ss.str();
  }

}  // namespace extras