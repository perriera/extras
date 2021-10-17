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

  void Socket::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_socket, _msg, strlen(_msg), 0);
  }

  void Socket::read(int expectedMaxSize) {
    byte *buffer = new byte[expectedMaxSize];
    this->_readMsgSize = ::read(this->_socket, buffer, expectedMaxSize);
    SocketException::assertLTZ(_socket, "read", __INFO__);
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = buffer[i];
    }
    delete[] buffer;
  }

  Socket::operator std::string() {
    std::stringstream ss;
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      ss << *ptr++;
    }
    return ss.str();
  }

  void SocketException::assertLTZ(int socket, const std::string &msg,
                                  const WhereAmI &ref) {
    if (socket < 0) throw SocketException(msg.c_str(), ref);
  }
  void SocketException::assertLTEQZ(int socket, const std::string &msg,
                                    const WhereAmI &ref) {
    if (socket <= 0) throw SocketException(msg.c_str(), ref);
  }
  void SocketException::assertZERO(int socket, const std::string &msg,
                                   const WhereAmI &ref) {
    if (socket != 0) throw SocketException(msg.c_str(), ref);
  }
  void SocketException::assertNEQZ(int socket, const std::string &msg,
                                   const WhereAmI &ref) {
    if (socket == 0) throw SocketException(msg.c_str(), ref);
  }

}  // namespace extras