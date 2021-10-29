#include "extras/sockets/Services.hpp"

#include <extras/rsi/subsystems.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  RequestedService Services::request(const PortNumber &serverSocket) {
    RequestedService serviceName = extras::rsi::read_line(serverSocket);
    _lastPortRequested = _portAuthority.request();
    extras::rsi::send_line(to_string(_lastPortRequested), serverSocket);
    return serviceName;
  }

}  // namespace extras
