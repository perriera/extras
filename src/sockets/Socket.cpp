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