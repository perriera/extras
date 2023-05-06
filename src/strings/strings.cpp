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

#include <extras/exceptions.hpp>
#include <extras/strings/string_support.hpp>
#include <string.h>

namespace extras {

   namespace str {

      /**
       * @brief left trim, right trim & trim
       *
       * @param s
       * @return std::string
       */
      std::string ltrim(const std::string& s)
      {
         return extras::ltrim_copy(s);
      }

      std::string rtrim(const std::string& s)
      {
         return extras::rtrim_copy(s);
      }

      std::string trim(const std::string& s)
      {
         return extras::trim_copy(s);
      }

      /**
       * @brief split string
       *
       * @param s
       * @param delim
       * @return std::deque<std::string>
       */
      std::deque<std::string> split(const std::string& s, char delim)
      {
         return extras::split(s, delim);
      }

      /**
       * @brief split
       *
       * @param s
       * @param delimiter
       * @return vector<string>
       */
      std::vector<std::string> split(std::string s,
                                     const std::string& delimiter)
      {
         size_t pos_start = 0, pos_end, delim_len = delimiter.length();
         std::string token;
         std::vector<std::string> res;

         while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
         }

         res.push_back(s.substr(pos_start));
         return res;
      }

      /**
       * @brief replace_all, remove_all
       *
       * @param s
       * @param a
       * @param b
       * @return std::string
       */
      std::string replace_all(const std::string& s, char a, char b)
      {
         return extras::replace_all(s, a, b);
      }

      std::string replace_all(std::string str,
                              const std::string& from,
                              const std::string& to)
      {
         return extras::replace_all(str, from, to);
      }

      std::string remove_all(const std::string& s, char a)
      {
         return extras::remove_all(s, a);
      }

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
      std::string replace_last(const std::string& str,
                               const std::string& from,
                               const std::string& to,
                               char delim)
      {
         return extras::replace_last(str, from, to, delim);
      }

      std::string replace_first(const std::string& str,
                                const std::string& from,
                                const std::string& to,
                                char delim)
      {
         auto dupa = str;
         auto dupb = from;
         auto dupc = to;
         reverse(dupa.begin(), dupa.end());
         reverse(dupb.begin(), dupb.end());
         reverse(dupc.begin(), dupc.end());
         auto answer = replace_last(dupa, dupb, dupc, delim);
         reverse(answer.begin(), answer.end());
         return answer;
      }

      /**
       * @brief ends_with, starts_with, contains
       *
       * @param value
       * @param ending
       * @return true
       * @return false
       */
      bool ends_with(std::string const& value, std::string const& ending)
      {
         return extras::ends_with(value, ending);
      }

      bool starts_with(std::string const& value, std::string const& beginning)
      {
         return extras::starts_with(value, beginning);
      }

      bool contains(std::string const& s1, std::string const& s2)
      {
         return extras::contains(s1, s2);
      }

      /**
       * @brief to_lower
       *
       * @param data
       * @return std::string
       */
      std::string to_lower(const std::string& data)
      {
         return extras::to_lower(data);
      }

      std::string to_upper(const std::string& data)
      {
         std::string dup = data;
         std::transform(dup.begin(),
                        dup.end(),
                        dup.begin(),
                        [](unsigned char c) { return std::toupper(c); });
         return dup;
      }

   } // namespace str
} // namespace extras
