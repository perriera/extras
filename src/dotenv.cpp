
#include <extras/dotenv.hpp>
#include <extras/strings.hpp>
#include <iomanip>
#include <iostream>

namespace extras {

  std::ostream &operator<<(std::ostream &out, const DotENVLine &obj) {
    out << obj._key << '=' << obj._value;
    return out;
  }

  std::istream &operator>>(std::istream &in, DotENVLine &obj) {
    std::stringstream key;
    std::string value;
    char c = ' ';
    in >> std::skipws;
    while (in.good() && c != '=') {
      in >> c;
      if (c == '#') break;
      if (isalnum(c) || c == '_') key << c;
    }
    DotENVLineKeyException::assertion(key.str(), __INFO__);
    obj._key = key.str();
    getline(in, value);
    obj._value = value;
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

  void DotENVLineKeyException::assertion(const std::string &key,
                                         const WhereAmI &ref) {
    DotENVNoKeyException::assertion(key, ref);
    DotENVBadFormatException::assertion(key, ref);
  }

  void DotENVNoKeyException::assertion(const std::string &key,
                                       const WhereAmI &ref) {
    if (key.length() == 0) {
      throw DotENVNoKeyException("No key specified", ref);
    }
  }

  void DotENVBadFormatException::assertion(const std::string &key,
                                           const WhereAmI &ref) {
    if (!isalpha(key[0])) {
      std::string msg = "Bad format for key: ";
      msg += key;
      throw DotENVBadFormatException(msg.c_str(), ref);
    }
  }

}  // namespace extras
