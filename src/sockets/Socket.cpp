#include "extras/sockets/Socket.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

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
    SocketException::assertLTZ(_socket, "IPv6 addresses not supported",
                               __INFO__);
  }

  void Socket::connect() {
    auto test = ::connect(this->_socket, (struct sockaddr *)&_serv_addr,
                          sizeof(_serv_addr));
    SocketException::assertLTZ(_socket, "Connection Failed", __INFO__);
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