#include "extras/sockets/SocketClient.hpp"

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cctype>
#include <extras/sockets/Socket.hpp>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  SocketClient::SocketClient(const std::string &hostname, int port)
      : _hostname(hostname), _port(port) {}

  // void SocketClient::connect() {
  //   this->_socket = socket(AF_INET, SOCK_STREAM, 0);
  //   SocketException::assertLTZ(_socket, "SocketClient creation error",
  //                              __INFO__);
  //   this->_serv_addr.sin_family = AF_INET;
  //   this->_serv_addr.sin_port = htons(_port);
  //   // Convert IPv4 and IPv6 addresses from text to binary form
  //   auto test1 =
  //       inet_pton(AF_INET, ip_address(_hostname).c_str(),
  //       &_serv_addr.sin_addr);
  //   SocketException::assertLTZ(test1, "IPv6 addresses not supported",
  //   __INFO__); _proxy = new Socket(this->_socket); auto test2 =
  //   ::connect(this->_socket, (struct sockaddr *)&_serv_addr,
  //                          sizeof(_serv_addr));
  //   SocketException::assertLTZ(test2, "Connection Failed", __INFO__);
  // }

  void SocketClient::connect() {
    if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      printf("\n Socket creation error \n");
      throw -1;
    }

    this->_serv_addr.sin_family = AF_INET;
    this->_serv_addr.sin_port = htons(_port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    auto _hn = ip_address(_hostname).c_str();
    if (inet_pton(AF_INET, "159.223.103.27", &this->_serv_addr.sin_addr) <= 0) {
      printf("\nInvalid address/ Address not supported \n");
      throw -1;
    }

    if (::connect(_socket, (struct sockaddr *)&this->_serv_addr,
                  sizeof(this->_serv_addr)) < 0) {
      printf("\nConnection Failed \n");
      throw -1;
    }

    _proxy = new Socket(this->_socket);
  }

  std::string SocketClient::ip_address(const std::string &domainname) {
    string result = "127.0.0.1";
    if (domainname == "localhost") return result;
    struct hostent *ghbn =
        gethostbyname("localhost");  // change the domain name
    if (domainname.length() > 1 && isdigit(domainname[0])) return domainname;
    if (ghbn) {
      printf("Host Name->%s\n", ghbn->h_name);
      result = inet_ntoa(*(struct in_addr *)ghbn->h_name);
      printf("IP ADDRESS->%s\n", result.c_str());
    } else {
      string msg = "Unknown IP address: " + domainname;
      throw SocketException(msg.c_str(), __INFO__);
    }
    return result;
  }

}  // namespace extras