#include "extras/sockets/PortAuthority.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/strings/string_support.hpp"

using namespace std;

namespace extras {

  PortNumber PortAuthority::request() {
    auto result = _next++;
    _next = _next % _size;
    return _start + result;
  }

}  // namespace extras
