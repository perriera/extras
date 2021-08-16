
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
      if (isalnum(c) || c == '_') key << c;
    }
    while (in.good()) {
      in >> c;
      if (!in.good()) break;
      value << c;
    }
    obj._key = obj.validate_key(key.str());
    obj._value = obj.validate_value(value.str());
    return in;
  }

  EnvironmentVariableKey DotENVLine::validate_key(
      const std::string &key) const {
    return key;
  }

  EnvironmentVariableValue DotENVLine::validate_value(
      const std::string &value) const {
    return value;
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
