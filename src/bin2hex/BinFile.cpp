#include <extras/bin2hex/BinFile.hpp>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  std::ostream& operator<<(std::ostream& out, const BinFile& obj) {
    const byte* p = obj.array();
    for (int i = 0; i < obj.size(); i++) out << *p++;
    return out;
  }

  std::istream& operator>>(std::istream& in, BinFile& obj) {
    vector<byte> buffer;
    in >> noskipws;
    while (in.good()) {
      byte value;
      in >> value;
      if (in.good()) buffer.push_back(value);
    }
    delete[] obj._array;
    obj._size = buffer.size();
    obj._array = new byte[obj._size];
    byte* p = obj._array;
    for (auto value : buffer) *p++ = value;
    return in;
  }

  BinFile::BinFile(const BinArray& binArray) {
    _size = binArray.size();
    _array = new byte[_size];
    auto* p = _array;
    for (auto value : binArray) {
      *p++ = value;
    }
  }

}  // namespace extras