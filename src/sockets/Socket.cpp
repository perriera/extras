#include "extras/sockets/Socket.hpp"

#include <iostream>

using namespace std;

namespace extras {

  Socket::Socket(const std::string &hostname, int port)
      : _hostname(hostname), _port(port) {}

}  // namespace extras