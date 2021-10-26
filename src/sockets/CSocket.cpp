#include "extras/sockets/CSocket.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

using namespace std;
#define SIZE 1024 * 256

string write_file(int sockfd) {
  int n;
  FILE *fp;
  stringstream ss;
  char buffer[SIZE];

  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0) {
      break;
      return ss.str();
    }
    ss << buffer;
    string test = ss.str();
    if (test.length() > 0 && test[test.length() - 1] == '\n') break;
    bzero(buffer, SIZE);
  }
  printf("[+]Data written in the file successfully.\n");

  return ss.str();
}

namespace extras {

  CSocket::CSocket(int socket) : _socket(socket) {
    SocketException::assertLTZ(_socket, "socket", __INFO__);
  }

  void CSocket::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_socket, _msg, strlen(_msg), 0);
  }

  SocketInterface &CSocket::read(int expectedMaxSize) {
    string msg = write_file(_socket);
    this->_readMsgSize = msg.size();
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = msg[i];
    }
    return *this;
  }

  CSocket::operator std::string() const {
    std::stringstream ss;
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      ss << *ptr++;
    }
    return ss.str();
  }

  CSocket::operator SocketPacket() const {
    return SocketPacket(this->_readMsg, this->_readMsgSize);
  }

}  // namespace extras