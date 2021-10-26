#include "extras/sockets/CSocketServer.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

#include "extras/sockets/CSocket.hpp"

using namespace std;
#define SIZE 1024 * 256

namespace extras {

  CSocketServer::CSocketServer(const std::string &hostname, int port)
      : _hostname(hostname), _port(port) {
    const char *ip = _hostname.c_str();

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    SocketException::assertLTZ(_socket, "[-]Error in socket", __INFO__);
    printf("[+]Server socket created successfully.\n");

    _server_addr.sin_family = AF_INET;
    _server_addr.sin_port = port;
    _server_addr.sin_addr.s_addr = inet_addr(ip);

    _e = bind(_socket, (struct sockaddr *)&_server_addr, sizeof(_server_addr));
    SocketException::assertLTZ(_e, "[-]Error in bind", __INFO__);
    printf("[+]Binding successfull.\n");

    auto test = listen(_socket, 10);
    SocketException::assertZERO(test, "[-]Error in listening", __INFO__);
    printf("[+]Listening....\n");
  }

  void CSocketServer::close() {
    if (_e != -1) ::close(_socket);
  }

  void CSocketServer::accept() {
    _addr_size = sizeof(_new_addr);
    _new_socket = ::accept(_socket, (struct sockaddr *)&_new_addr, &_addr_size);
    SocketException::assertLTZ(_new_socket, "accept", __INFO__);
    if (_proxy != nullptr) {
      delete _proxy;
      _proxy = nullptr;
    }
    _proxy = new CSocket(this->_new_socket);
  }

}  // namespace extras