/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

#include <extras/devices/dotenv.hpp>
#include <extras/strings.hpp>
#include <iomanip>
#include <iostream>

namespace extras {

  /**
   * @brief DotENVLine ostream&
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */
  std::ostream &operator<<(std::ostream &out, const DotENVLine &obj) {
    out << obj._key << '=' << obj._value;
    return out;
  }

  /**
   * @brief  DotENVLine istream&
   *
   * @param in
   * @param obj
   * @return std::istream&
   */
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

  /**
   * @brief DotENV ostream&
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */
  std::ostream &operator<<(std::ostream &out, const DotENV &obj) {
    for (auto entry : obj._map) {
      out << entry.first << "=" << entry.second << std::endl;
    }
    return out;
  }

  /**
   * @brief DotENV istream&
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */
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

  /**
   * @brief DotENVLineKeyException::assertion()
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */

  void DotENVLineKeyException::assertion(const std::string &key,
                                         const WhereAmI &ref) {
    DotENVNoKeyException::assertion(key, ref);
    DotENVBadFormatException::assertion(key, ref);
  }

  /**
   * @brief DotENVNoKeyException::assertion()
   *
   * Thrown if no KEY is specified
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */

  void DotENVNoKeyException::assertion(const std::string &key,
                                       const WhereAmI &ref) {
    if (key.length() == 0) {
      throw DotENVNoKeyException("No key specified", ref);
    }
  }

  /**
   * @brief DotENVBadFormatException::assertion()
   *
   * Thrown if the KEY starts with anything but a letter
   *
   * @param out
   * @param obj
   * @return std::ostream&
   */

  void DotENVBadFormatException::assertion(const std::string &key,
                                           const WhereAmI &ref) {
    if (key.length() > 0 && !isalpha(key[0])) {
      std::string msg = "Bad format for key: ";
      msg += key;
      throw DotENVBadFormatException(msg.c_str(), ref);
    }
  }

}  // namespace extras
