#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/rsi/RSIInterface.hpp"

using namespace std;

namespace extras {

  std::ostream& operator<<(std::ostream& out, const RSIInterface& obj) {
    return out;
  }
  std::istream& operator>>(std::istream& in, RSIInterface& obj) { return in; }

}  // namespace extras
