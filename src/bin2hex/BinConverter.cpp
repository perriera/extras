#include <extras/bin2hex/BinConverter.hpp>
#include <extras/bin2hex/BinFile.hpp>
#include <extras/bin2hex/HexFile.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

namespace extras {

  BinArray BinConverter::hex2bin(const HexInterface &hex) const {
    BinArray binArray;
    for (auto line : hex.array()) {
      stringstream ss;
      ss << line;
      while (ss.good()) {
        char hi, lo;
        ss >> hi >> lo;
        if (!ss.good()) break;
        stringstream ss2;
        ss2 << hi << lo;
        string hex_string;
        ss2 >> hex_string;
        int value = stoi(hex_string, 0, 16);
        byte byte_value = value;
        binArray.push_back(byte_value);
      }
    }
    return binArray;
  }

}  // namespace extras
