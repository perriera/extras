
#include <extras/dotenv.hpp>
#include <extras/strings.hpp>
#include <iostream>

namespace extras {

  std::ostream &operator<<(std::ostream &out, const DotENVLine &obj) {
    out << obj._key << '=' << obj._value;
    return out;
  }

  std::istream &operator>>(std::istream &in, DotENVLine &obj) {
    std::stringstream key;
    std::stringstream value;
    char c = ' ';
    while (in.good() && c != '=') {
      in >> c;
      if (c == ' ') continue;
      if (c == '#') break;
      if (c == '\n') break;
      if (isalnum(c) || c == '_') key << c;
    }
    while (in.good()) {
      in >> c;
      if (!in.good()) break;
      value << c;
    }
    DotENVLineKeyException::assertion(key.str(), __INFO__);
    obj._key = key.str();
    obj._value = value.str();
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const DotENV &obj) {
    for (auto entry : obj._map) {
      out << entry.first << "=" << entry.second << std::endl;
    }
    return out;
  }

  std::istream &operator>>(std::istream &in, DotENV &obj) {
    std::string line;
    while (in.good()) {
      std::getline(in, line);
      if (line[0] == '#' || line[0] == ' ' || line[0] == '\n') {
        continue;
      }
      if (line.empty()) break;
      std::stringstream ss;
      ss << line;
      DotENVLine dotENVLine;
      ss >> dotENVLine;
      obj.put(dotENVLine);
    }
    return in;
  }

}  // namespace extras
