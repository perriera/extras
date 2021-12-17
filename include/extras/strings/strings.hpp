/**
 * @file string_support.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief namespace extras::str, (for better string support)
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRA_STRINGS_HPP
#define _EXTRA_STRINGS_HPP

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

#include <extras/interfaces.hpp>
#include <extras/string_support/string_support.hpp>

namespace extras {

  namespace str {

    /**
     * @brief left trim, right trim & trim
     *
     * @param s
     * @return std::string
     */
    std::string ltrim(const std::string &s);
    std::string rtrim(const std::string &s);
    std::string trim(const std::string &s);

    /**
     * @brief split string
     *
     * @param s
     * @param delim
     * @return std::deque<std::string>
     */
    std::deque<std::string> split(const std::string &s, char delim);

    /**
     * @brief replace_all, remove_all
     *
     * @param s
     * @param a
     * @param b
     * @return std::string
     */
    std::string replace_all(const std::string &s, char a, char b);
    std::string replace_all(std::string str, const std::string &from,
                            const std::string &to);
    std::string remove_all(const std::string &s, char a);

    /**
     * @brief replace_last()
     *
     * This method replaces the last occurance of the 'from' string with the
     * 'to' string. This method will need a character that is not in use by
     * the original string, (in order to work).
     *
     * @param str
     * @param from
     * @param to
     * @param delim
     * @return std::string
     */
    std::string replace_last(const std::string &str, const std::string &from,
                             const std::string &to, char delim);

    /**
     * @brief ends_with, starts_with, contains
     *
     * @param value
     * @param ending
     * @return true
     * @return false
     */
    bool ends_with(std::string const &value, std::string const &ending);
    bool starts_with(std::string const &value, std::string const &beginning);
    bool contains(std::string const &s1, std::string const &s2);

    /**
     * @brief to_lower
     *
     * @param data
     * @return std::string
     */
    std::string to_lower(const std::string &data);
    std::string to_upper(const std::string &data);

    /**
     * @brief sample template
     *
     * @tparam T
     * @param t
     * @return std::string
     */
    template <typename T>
    std::string plusone(T const &t) {
      std::ostringstream oss;
      oss << (t + 1);
      return oss.str();
    }
  }  // namespace str
}  // namespace extras

#endif  // _EXTRA_STRINGS_HPP
