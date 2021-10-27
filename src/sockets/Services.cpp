#include "extras/sockets/Services.hpp"

#include <extras/uploader/UploaderInterface.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  PortNumber Services::request(const ServiceName& serviceName,
                               const PortNumber& serverSocket) {
    int port_to_use = read_int(serverSocket);
    int servce_port = _portAuthority.request();
    std::string cmd = serviceName + " &";
    system(serviceName.c_str());
    return servce_port;
  }

}  // namespace extras
