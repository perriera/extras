#include <extras/bin2hex/BinFile.hpp>
#include <extras/bin2hex/HexConverter.hpp>
#include <extras/bin2hex/HexFile.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  HexArray HexConverter::bin2hex(const BinInterface &bin) const {
    const byte *p = bin.array();
    HexArray hexArray;
    int i = 0;
    while (i < bin.size()) {
      stringstream ss;
      for (int x = 0; x < 40; x++, i++) {
        byte value = *p++;
        ss << std::hex << std::setfill('0') << std::setw(2);
        ss << static_cast<int>(value);
      }
      HexLine hexLine = ss.str();
      hexArray.push_back(hexLine);
    }
    return hexArray;
  }
}  // namespace extras
