
#include <extras/dotenv.hpp>
#include <extras/strings.hpp>
#include <iostream>

namespace extras {

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
      if (line.empty()) break;
      auto parts = split(line, '=');
      obj.put(parts[0], (parts.size() > 1 ? parts[1] : ""));
    }
    return in;
  }

}  // namespace extras
