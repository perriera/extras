#include "extras/sockets/Services.hpp"

#include <extras/uploader/UploaderInterface.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  RequestedService Services::request(const PortNumber &serverSocket) {
    RequestedService serviceName = read_line(serverSocket);
    _lastPortRequested = _portAuthority.request();
    send_line(to_string(_lastPortRequested), serverSocket);
    return serviceName;
  }

}  // namespace extras
