#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/rsi/RSIInterface.hpp"

using namespace std;

namespace extras {

  // 'build/uploader_client send.txt 159.223.103.27 9010 &'
  std::ostream& operator<<(std::ostream& out, const RSIInterface& obj) {
    stringstream ss;
    ss << obj.service() << ' ' << obj.filename() << ' ' << obj.ip() << ' ';
    ss << obj.port() << ' ' << (obj.async() ? ' ' : '&');
    string test = ss.str();
    out << test;
    return out;
  }
  std::istream& operator>>(std::istream& in, RSIInterface& obj) { return in; }

}  // namespace extras
