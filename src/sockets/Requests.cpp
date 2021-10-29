#include "extras/sockets/Requests.hpp"

#include <extras/rsi/subsystems.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace extras {

  PortNumber Requests::request(const RequestedService& serviceName,
                               const PortServerNumber& serverSocket) {
    extras::rsi::send_line(serviceName, serverSocket);
    int port_to_use = stoi(extras::rsi::read_line(serverSocket));
    return port_to_use;
  }

}  // namespace extras
