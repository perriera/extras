#include <extras/string_support.hpp>

namespace extras {

std::deque<std::string> split(const std::string &s, char delim) {
  std::deque<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (std::getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

std::string replace_all(const std::string &s, char a, char b) {
  std::string dup = s;
  replace(dup.begin(), dup.end(), a, b);
  return dup;
}

std::string remove_all(const std::string &s, char a) {
  std::string dup = s;
  dup.erase(std::remove(dup.begin(), dup.end(), a), dup.end());
  return dup;
}

std::string replace_all(std::string str, const std::string &from,
                        const std::string &to) {
  std::size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos +=
        to.length();  // Handles case where 'to' is a substring of 'from'
  }
  return str;
}

}  // namespace extras
