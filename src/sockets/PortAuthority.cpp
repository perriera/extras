#include "extras/sockets/PortAuthority.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/strings/string_support.hpp"

using namespace std;

namespace extras {

  PortNumber PortAuthority::request() { return 9000; }

}  // namespace extras
