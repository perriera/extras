/**
 * @file dotenv.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief DOTENV implementation
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRAS_DOT_ENV_HPP
#define _EXTRAS_DOT_ENV_HPP

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

#include <extras/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

namespace extras {

   /**
    * @brief interface DotENVInterface
    *
    */

   using EnvironmentVariableKey = std::string;
   using EnvironmentVariableValue = std::string;
   using EnvironmentVariableMap =
     std::map<EnvironmentVariableKey, EnvironmentVariableValue>;

   /**
    * @brief interface DotENVLineInterface
    *
    */

   interface DotENVLineInterface
   {
      virtual const EnvironmentVariableKey& key() const pure;
      virtual const EnvironmentVariableValue& value() const pure;
   };

   /**
    * @brief DotENVLineKeyException
    *
    * To be thrown if either string or value supplied is out of range.
    *
    */
   concrete class DotENVLineKeyException extends AbstractCustomException
   {
    public:

      DotENVLineKeyException(const char* msg, const WhereAmI& whereAmI)
        : AbstractCustomException(msg,
                                  whereAmI._file.c_str(),
                                  whereAmI._func.c_str(),
                                  whereAmI._line)
      {
      }

      static void assertion(const std::string& key, const WhereAmI& ref);
   };

   concrete class DotENVNoKeyException extends DotENVLineKeyException
   {
    public:

      DotENVNoKeyException(const char* msg, const WhereAmI& whereAmI)
        : DotENVLineKeyException(msg, whereAmI)
      {
      }

      static void assertion(const std::string& key, const WhereAmI& ref)
      {
         if (key.length() == 0) {
            throw DotENVNoKeyException("No key specified", ref);
         }
      }
   };

   concrete class DotENVBadFormatException extends DotENVLineKeyException
   {
    public:

      DotENVBadFormatException(const char* msg, const WhereAmI& whereAmI)
        : DotENVLineKeyException(msg, whereAmI)
      {
      }

      static void assertion(const std::string& key, const WhereAmI& ref)
      {
         if (key.length() > 0 && !isalpha(key[0])) {
            std::string msg = "Bad format for key: ";
            msg += key;
            throw DotENVBadFormatException(msg.c_str(), ref);
         }
      }
   };

   /**
    * @brief interface DotENVLineInterface
    *
    */

   concrete class DotENVLine implements DotENVLineInterface
   {
      friend std::ostream& operator<<(std::ostream& out, const DotENVLine& obj)
      {
         out << obj._key << '=' << obj._value;
         return out;
      }

      friend std::istream& operator>>(std::istream& in, DotENVLine& obj)
      {
         std::stringstream key;
         std::string value;
         char c = ' ';
         in >> std::skipws;
         while (in.good() && c != '=') {
            in >> c;
            if (c == '#')
               break;
            if (isalnum(c) || c == '_')
               key << c;
         }
         DotENVLineKeyException::assertion(key.str(), __INFO__);
         obj._key = key.str();
         getline(in, value);
         obj._value = value;
         return in;
      }

      friend inline bool operator==(const DotENVLine& a, const DotENVLine& b)
      {
         return a.key() == b.key() && a.value() == b.value();
      }

      friend inline bool operator!=(const DotENVLine& a, const DotENVLine& b)
      {
         return !(a == b);
      }

      EnvironmentVariableKey _key;
      EnvironmentVariableValue _value;

    public:

      DotENVLine(){};
      DotENVLine(const EnvironmentVariableKey& key,
                 const EnvironmentVariableValue& value)
        : _key(key)
        , _value(value){};

      const EnvironmentVariableKey& key() const override { return _key; }

      const EnvironmentVariableValue& value() const override { return _value; }

      operator std::string() const
      {
         std::stringstream ss;
         ss << *this;
         return ss.str();
      }
   };

   /**
    * @brief interface DotENVInterface
    *
    */

   interface DotENVInterface
   {
      /**
       * @brief map()
       *
       * Return a map of EnvironmentVariableMap
       *
       * @return const EnvironmentVariableMap&
       */
      virtual const EnvironmentVariableMap& map() const pure;

      /**
       * @brief put()
       *
       * Put a key/value pair using the DotENVLineInterface
       *
       * @param key
       * @param value
       */
      virtual void put(const DotENVLineInterface& entry) pure;

      /**
       * @brief contains()
       *
       * Test for key
       *
       * @param key
       * @return bool
       */
      virtual bool contains(const EnvironmentVariableKey& key) const pure;

      /**
       * @brief value()
       *
       * Retrieve value, (as a duplicate)
       *
       * @param key
       * @return EnvironmentVariableValue
       */
      virtual EnvironmentVariableValue value(
        const EnvironmentVariableKey& key) const pure;
   };

   /**
    * @brief class DotENV
    *
    */

   concrete class DotENV implements DotENVInterface
   {
      friend std::ostream& operator<<(std::ostream& out, const DotENV& obj)
      {
         for (auto entry : obj._map) {
            out << entry.first << "=" << entry.second << std::endl;
         }
         return out;
      }

      friend std::istream& operator>>(std::istream& in, DotENV& obj)
      {
         std::string line;
         while (in.good()) {
            std::getline(in, line);
            if (line[0] == '#' || line[0] == ' ' || line[0] == '\n') {
               continue;
            }
            if (line.empty())
               break;
            std::stringstream ss;
            ss << line;
            DotENVLine dotENVLine;
            ss >> dotENVLine;
            obj.put(dotENVLine);
         }
         return in;
      }

      friend inline bool operator==(const DotENV& a, const DotENV& b)
      {
         return a._map == b._map;
      }

      friend inline bool operator!=(const DotENV& a, const DotENV& b)
      {
         return !(a == b);
      }

      EnvironmentVariableMap _map;

    public:

      static auto instance() -> DotENVInterface&
      {
         static DotENV dotENV;
         return dotENV;
      }

      const EnvironmentVariableMap& map() const override { return _map; };

      void put(const DotENVLineInterface& entry) override
      {
         _map[entry.key()] = entry.value();
      };

      bool contains(const EnvironmentVariableKey& key) const override
      {
         return _map.find(key) != _map.end();
      };

      EnvironmentVariableValue value(
        const EnvironmentVariableKey& key) const override
      {
         auto dup = _map;
         return dup[key];
      };
   };
} // namespace extras

#endif // _EXTRAS_DOT_ENV_HPP
