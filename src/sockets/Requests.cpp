#include "extras/sockets/Requests.hpp"

#include <extras/uploader/UploaderInterface.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  PortNumber Requests::request(const ServiceName& serviceName,
                               const PortNumber& servce_port) {
    send_string(serviceName, servce_port);
    int port_to_use = read_int(servce_port);
    return port_to_use;
  }

}  // namespace extras
