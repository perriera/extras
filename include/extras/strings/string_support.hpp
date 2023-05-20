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

   std::deque<std::string> split(const std::string& s, char delim);
   std::string replace_all(const std::string& s, char a, char b);
   std::string remove_all(const std::string& s, char a);
   std::string replace_all(std::string str,
                           const std::string& from,
                           const std::string& to);

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
      std::string ltrim(const std::string& s);
      std::string rtrim(const std::string& s);
      std::string trim(const std::string& s);

      /**
       * @brief split string
       *
       * @param s
       * @param delim
       * @return std::deque<std::string>
       */
      std::deque<std::string> split(const std::string& s, char delim);

      /**
       * @brief split
       *
       * @param s
       * @param delimiter
       * @return std::vector<std::string>
       */
      std::vector<std::string> split(std::string s,
                                     const std::string& delimiter);

      /**
       * @brief replace_all, remove_all
       *
       * @param s
       * @param a
       * @param b
       * @return std::string
       */
      std::string replace_all(const std::string& s, char a, char b);
      std::string replace_all(std::string str,
                              const std::string& from,
                              const std::string& to);
      std::string remove_all(const std::string& s, char a);

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
      std::string replace_last(const std::string& str,
                               const std::string& from,
                               const std::string& to,
                               char delim = '\r');
      std::string replace_first(const std::string& str,
                                const std::string& from,
                                const std::string& to,
                                char delim = '\r');

      /**
       * @brief ends_with, starts_with, contains
       *
       * @param value
       * @param ending
       * @return true
       * @return false
       */
      bool ends_with(std::string const& value, std::string const& ending);
      bool starts_with(std::string const& value, std::string const& beginning);
      bool contains(std::string const& s1, std::string const& s2);

      /**
       * @brief to_lower
       *
       * @param data
       * @return std::string
       */
      std::string to_lower(const std::string& data);
      std::string to_upper(const std::string& data);

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
