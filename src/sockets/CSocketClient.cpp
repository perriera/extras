#include "extras/sockets/CSocketClient.hpp"

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <extras/sockets/CSocket.hpp>
#include <iostream>
#include <sstream>

#include "extras/sockets/Domains.hpp"

using namespace std;

namespace extras {

  CSocketClient::CSocketClient(const std::string &hostname, int port)
      : _hostname(ip_address(hostname)), _port(port) {
    const char *ip = _hostname.c_str();

    _socket = socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertLTZ(_socket, "[-]Error in socket", __INFO__);
    printf("[+]Server socket created successfully.\n");

    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = port;
    _server_addr.sin_addr.s_addr = inet_addr(ip);

    _proxy = new CSocket(this->_socket);
  }

  void CSocketClient::connect() {
    _e = ::connect(_socket, (struct sockaddr *)&_server_addr,
                   sizeof(_server_addr));
    SocketException::assertEQMINUS1(_e, "[-]Error in socket", __INFO__);
    printf("[+]Connected to Server.\n");
  }

  void CSocketClient::close() {
    if (_e != -1) ::close(_socket);
  };

  std::string CSocketClient::ip_address(const std::string &domainname) {
    string result = "127.0.0.1";
    if (domainname == "localhost") return result;
    if (domainname.length() > 1 && isdigit(domainname[0])) return domainname;
    return ~Domain(domainname);
  }

}  // namespace extras