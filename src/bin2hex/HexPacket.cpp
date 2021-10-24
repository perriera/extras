#include <extras/bin2hex/HexPacket.hpp>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  std::ostream& operator<<(std::ostream& out, const HexPacket& obj) {
    out << obj.index() + 1 << ' ';
    out << obj.count() << ' ';
    out << obj.rle() << ' ';
    out << obj.line();
    return out;
  }

  std::istream& operator>>(std::istream& in, HexPacket& obj) {
    in >> skipws;
    in >> obj._index;
    obj._index--;
    in >> obj._count;
    string rle;
    in >> rle;
    in >> obj._line;
    return in;
  }

}  // namespace extras