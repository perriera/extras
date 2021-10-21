#include <extras/bin2hex/HexPacket.hpp>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  std::ostream& operator<<(std::ostream& out, const HexPacket& obj) {
    // for (auto line : obj.array()) out << line << endl;
    return out;
  }

  std::istream& operator>>(std::istream& in, HexPacket& obj) {
    // HexArray hexArray;
    // while (in.good()) {
    //   string line;
    //   getline(in, line);
    //   if (in.good()) hexArray.push_back(line);
    // }
    // obj._array = hexArray;
    return in;
  }

}  // namespace extras