#include "extras/sockets/CSocket.hpp"

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  CSocket::CSocket(int socket) : _socket(socket) {
    SocketException::assertLTZ(_socket, "socket", __INFO__);
  }

  void CSocket::send(const std::string &msg) {
    const char *_msg = msg.c_str();
    ::send(this->_socket, _msg, strlen(_msg), 0);
  }

  SocketInterface &CSocket::read(int expectedMaxSize) {
    expectedMaxSize = 1024 * 128;
    byte buffer[1024 * 128];
    this->_readMsgSize = 0;
    bool done = false;
    int index = 0;
    while (!done) {
      byte localBuffer[1024];
      int readSoFar = 0;
      while (readSoFar == 0) {
        readSoFar = ::read(this->_socket, localBuffer, 1024);
        if (readSoFar < 0) {
          cout << "Let me know" << endl;
        }
      }
      this->_readMsgSize += readSoFar;
      for (int i = 0; i < 1024; i++) {
        buffer[index++] = localBuffer[i];
        char c = (char)localBuffer[i];
        if (c == '\n') done = true;
      }
    }
    cout << this->_readMsgSize << endl;
    if (this->_readMsg != nullptr) delete this->_readMsg;
    this->_readMsg = new byte[this->_readMsgSize];
    byte *ptr = this->_readMsg;
    for (int i = 0; i < this->_readMsgSize; i++) {
      *ptr++ = buffer[i];
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