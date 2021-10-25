#include "extras/sockets/SocketClient.hpp"

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <extras/sockets/Socket.hpp>
#include <iostream>
#include <sstream>

#include "extras/sockets/Domains.hpp"

using namespace std;

namespace extras {

  SocketClient::SocketClient(const std::string &hostname, int port)
      : _hostname(ip_address(hostname)), _port(port) {
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertLTZ(_socket, "SocketClient creation error",
                               __INFO__);
    this->_serv_addr.sin_family = AF_INET;
    this->_serv_addr.sin_port = htons(_port);
    // Convert IPv4 and IPv6 addresses from text to binary form
    auto test = inet_pton(AF_INET, _hostname.c_str(), &_serv_addr.sin_addr);
    SocketException::assertLTZ(test, "IPv6 addresses not supported", __INFO__);
    _proxy = new Socket(this->_socket);
  }

  void SocketClient::connect() {
    auto test = ::connect(this->_socket, (struct sockaddr *)&_serv_addr,
                          sizeof(_serv_addr));
    SocketException::assertLTZ(test, "Connection Failed", __INFO__);
  }

  std::string SocketClient::ip_address(const std::string &domainname) {
    string result = "127.0.0.1";
    if (domainname == "localhost") return result;
    if (domainname.length() > 1 && isdigit(domainname[0])) return domainname;
    return ~Domain(domainname);
  }

}  // namespace extras