#include "extras/sockets/Socket.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

using namespace std;

namespace extras {

  Socket::Socket(const std::string& hostname, int port)
      : _hostname(hostname), _port(port) {
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertion(_socket, __INFO__);
    this->_serv_addr.sin_family = AF_INET;
    this->_serv_addr.sin_port = htons(_port);
    // Convert IPv4 and IPv6 addresses from text to binary form
    auto test = inet_pton(AF_INET, _hostname.c_str(), &_serv_addr.sin_addr);
    SocketException::assertion1(test, __INFO__);
  }

  void Socket::connect() {
    auto test = ::connect(this->_socket, (struct sockaddr*)&_serv_addr,
                          sizeof(_serv_addr));
    SocketException::assertion2(test, __INFO__);
  }

  void SocketException::assertion(int socket, const WhereAmI& ref) {
    if (socket < 0) throw SocketException("Socket creation error", ref);
  }
  void SocketException::assertion1(int errnumber, const WhereAmI& ref) {
    if (errnumber <= 0)
      throw SocketException("IPv6 addresses not supported", ref);
  }
  void SocketException::assertion2(int errnumber, const WhereAmI& ref) {
    if (errnumber <= 0) throw SocketException("Connection Failed", ref);
  }

}  // namespace extras