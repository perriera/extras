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

  Socket::Socket(const std::string &hostname, int port)
      : _hostname(hostname), _port(port) {
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertLTZ(_socket, "Socket creation error", __INFO__);
    this->_serv_addr.sin_family = AF_INET;
    this->_serv_addr.sin_port = htons(_port);
    // Convert IPv4 and IPv6 addresses from text to binary form
    auto test = inet_pton(AF_INET, _hostname.c_str(), &_serv_addr.sin_addr);
    SocketException::assertLTZ(test, "IPv6 addresses not supported", __INFO__);
  }

  void Socket::connect() {
    auto test = ::connect(this->_socket, (struct sockaddr *)&_serv_addr,
                          sizeof(_serv_addr));
    SocketException::assertLTZ(test, "Connection Failed", __INFO__);
  }

  void Socket::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_socket, _msg, strlen(_msg), 0);
  }

  void Socket::read(int expectedMaxSize) {
    byte buffer[expectedMaxSize];
    this->_readMsgSize = ::read(this->_socket, buffer, expectedMaxSize);
    SocketException::assertLTZ(_socket, "read", __INFO__);
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = buffer[i];
    }
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