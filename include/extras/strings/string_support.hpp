/**
 * @file string_support.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief convenient string methods
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRA_STRING_SUPPORT_HPP
#define _EXTRA_STRING_SUPPORT_HPP

/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include <algorithm>
#include <cctype>
#include <deque>
#include <extras/exceptions.hpp>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

namespace extras {

   // trim from start (in place)
   static inline void ltrim(std::string& s)
   {
      s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                 return !std::isspace(ch);
              }));
   }

   // trim from end (in place)
   static inline void rtrim(std::string& s)
   {
      s.erase(std::find_if(s.rbegin(),
                           s.rend(),
                           [](unsigned char ch) { return !std::isspace(ch); })
                .base(),
              s.end());
   }

   // trim from both ends (in place)
   static inline void trim(std::string& s)
   {
      ltrim(s);
      rtrim(s);
   }

   // trim from start (copying)
   static inline std::string ltrim_copy(const std::string& s)
   {
      auto dup = s;
      ltrim(dup);
      return dup;
   }

   // trim from end (copying)
   static inline std::string rtrim_copy(const std::string& s)
   {
      auto dup = s;
      rtrim(dup);
      return dup;
   }

   // trim from both ends (copying)
   static inline std::string trim_copy(const std::string& s)
   {
      auto dup = s;
      trim(dup);
      return dup;
   }

   static inline std::deque<std::string> split(const std::string& s, char delim)
   {
      std::deque<std::string> result;
      std::stringstream ss(s);
      std::string item;

      while (std::getline(ss, item, delim)) {
         result.push_back(item);
      }

      return result;
   }

   static inline std::string replace_all(const std::string& s, char a, char b)
   {
      std::string dup = s;
      replace(dup.begin(), dup.end(), a, b);
      return dup;
   }

   static inline std::string remove_all(const std::string& s, char a)
   {
      std::string dup = s;
      dup.erase(std::remove(dup.begin(), dup.end(), a), dup.end());
      return dup;
   }

   static inline std::string replace_all(std::string str,
                                         const std::string& from,
                                         const std::string& to)
   {
      std::size_t start_pos = 0;
      while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
         str.replace(start_pos, from.length(), to);
         start_pos +=
           to.length(); // Handles case where 'to' is a substring of 'from'
      }
      return str;
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
                            char delim = '\r');

   inline bool ends_with(std::string const& value, std::string const& ending)
   {
      if (ending.size() > value.size())
         return false;
      return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
   }

   inline bool starts_with(std::string const& value,
                           std::string const& beginning)
   {
      return value.rfind(beginning, 0) == 0;
   }

   inline bool contains(std::string const& s1, std::string const& s2)
   {
      return s1.find(s2) != std::string::npos;
   }

   inline std::string to_lower(const std::string& data)
   {
      std::string dup = data;
      std::transform(dup.begin(), dup.end(), dup.begin(), [](unsigned char c) {
         return std::tolower(c);
      });
      return dup;
   }

   // cout << plusone(42);
   template<typename T>
   std::string plusone(T const& t)
   {
      std::ostringstream oss;
      oss << (t + 1);
      return oss.str();
   }

   namespace str {

      /**
       * @brief left trim, right trim & trim
       *
       * @param s
       * @return std::string
       */
      inline std::string ltrim(const std::string& s)
      {
         return extras::ltrim_copy(s);
      }

      inline std::string rtrim(const std::string& s)
      {
         return extras::rtrim_copy(s);
      }

      inline std::string trim(const std::string& s)
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
      inline std::deque<std::string> split(const std::string& s, char delim)
      {
         return extras::split(s, delim);
      }

      /**
       * @brief split
       *
       * @param s
       * @param delimiter
       * @return std::vector<std::string>
       */
      inline std::vector<std::string> split(std::string s,
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
      inline std::string replace_all(const std::string& s, char a, char b)
      {
         return extras::replace_all(s, a, b);
      }

      inline std::string replace_all(std::string str,
                                     const std::string& from,
                                     const std::string& to)
      {
         return extras::replace_all(str, from, to);
      }

      inline std::string remove_all(const std::string& s, char a)
      {
         return extras::remove_all(s, a);
      }

      inline std::string strip(const std::string& s, char a)
      {
         return remove_all(s, a);
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
      inline std::string replace_last(const std::string& str,
                                      const std::string& from,
                                      const std::string& to,
                                      char delim = '\r')
      {
         return extras::replace_last(str, from, to, delim);
      }

      inline std::string replace_first(const std::string& str,
                                       const std::string& from,
                                       const std::string& to,
                                       char delim = '\r')
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
      inline bool ends_with(std::string const& value, std::string const& ending)
      {
         return extras::ends_with(value, ending);
      }

      inline bool starts_with(std::string const& value,
                              std::string const& beginning)
      {
         return extras::starts_with(value, beginning);
      }

      inline bool contains(std::string const& s1, std::string const& s2)
      {
         return extras::contains(s1, s2);
      }

      /**
       * @brief to_lower
       *
       * @param data
       * @return std::string
       */
      inline std::string to_lower(const std::string& data)
      {
         return extras::to_lower(data);
      }

      inline std::string to_upper(const std::string& data)
      {
         std::string dup = data;
         std::transform(dup.begin(),
                        dup.end(),
                        dup.begin(),
                        [](unsigned char c) { return std::toupper(c); });
         return dup;
      }

      /**
       * @brief sample template
       *
       * @tparam T
       * @param t
       * @return std::string
       */
      template<typename T>
      std::string plusone(T const& t)
      {
         std::ostringstream oss;
         oss << (t + 1);
         return oss.str();
      }
   } // namespace str

} // namespace extras

#endif // _EXTRA_STRING_SUPPORT_HPP
