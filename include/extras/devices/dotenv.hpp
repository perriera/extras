#ifndef _EXTRAS_DOT_ENV_HPP
#define _EXTRAS_DOT_ENV_HPP

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

/**
 * @file dotenv.hpp
 * @author Perry Anderson (perry.anderson@gmail.com)
 * @brief Matt recommended we make DotENVInterface as part of extras.
 * @version 0.1
 * @date 2021-08-14
 *
 * GIVEN traditional Linux applications (usually) depend heavily on environment
 * variables WHEN we wrap the STL map<> construct inside an interface, (complete
 * with mocks and unit tests) THEN we can utilize DotENVInterface inside
 * applications that depend on environment variables
 *
 * @copyright Copyright (c) 2021, Perry Anderson (perry.anderson@gmail.com)
 * @license MIT, (see LICENSE)
 *
 */

#include <extras/language/exceptions.hpp>
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

  interface DotENVLineInterface {
    virtual const EnvironmentVariableKey &key() const pure;
    virtual const EnvironmentVariableValue &value() const pure;
  };

  /**
   * @brief DotENVLineKeyException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class DotENVLineKeyException extends AbstractCustomException {
   public:
    DotENVLineKeyException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &key, const WhereAmI &ref);
  };

  concrete class DotENVNoKeyException extends DotENVLineKeyException {
   public:
    DotENVNoKeyException(const char *msg, const WhereAmI &whereAmI)
        : DotENVLineKeyException(msg, whereAmI) {}
    static void assertion(const std::string &key, const WhereAmI &ref);
  };

  concrete class DotENVBadFormatException extends DotENVLineKeyException {
   public:
    DotENVBadFormatException(const char *msg, const WhereAmI &whereAmI)
        : DotENVLineKeyException(msg, whereAmI) {}
    static void assertion(const std::string &key, const WhereAmI &ref);
  };

  /**
   * @brief interface DotENVLineInterface
   *
   */

  concrete class DotENVLine implements DotENVLineInterface {
    friend std::ostream &operator<<(std::ostream &out, const DotENVLine &obj);
    friend std::istream &operator>>(std::istream &in, DotENVLine &obj);
    friend inline bool operator==(const DotENVLine &a, const DotENVLine &b) {
      return a.key() == b.key() && a.value() == b.value();
    }
    friend inline bool operator!=(const DotENVLine &a, const DotENVLine &b) {
      return !(a == b);
    }
    EnvironmentVariableKey _key;
    EnvironmentVariableValue _value;

   public:
    DotENVLine(){};
    DotENVLine(const EnvironmentVariableKey &key,
               const EnvironmentVariableValue &value)
        : _key(key), _value(value){};
    const EnvironmentVariableKey &key() const override { return _key; }
    const EnvironmentVariableValue &value() const override { return _value; }
    operator std::string() const {
      std::stringstream ss;
      ss << *this;
      return ss.str();
    }
  };

  /**
   * @brief interface DotENVInterface
   *
   */

  interface DotENVInterface {
    /**
     * @brief map()
     *
     * Return a map of EnvironmentVariableMap
     *
     * @return const EnvironmentVariableMap&
     */
    virtual const EnvironmentVariableMap &map() const pure;

    /**
     * @brief put()
     *
     * Put a key/value pair using the DotENVLineInterface
     *
     * @param key
     * @param value
     */
    virtual void put(const DotENVLineInterface &entry) pure;

    /**
     * @brief contains()
     *
     * Test for key
     *
     * @param key
     * @return bool
     */
    virtual bool contains(const EnvironmentVariableKey &key) const pure;

    /**
     * @brief value()
     *
     * Retrieve value, (as a duplicate)
     *
     * @param key
     * @return EnvironmentVariableValue
     */
    virtual EnvironmentVariableValue value(
        const EnvironmentVariableKey &key) const pure;
  };

  /**
   * @brief class DotENV
   *
   */

  concrete class DotENV implements DotENVInterface {
    friend std::ostream &operator<<(std::ostream &out, const DotENV &obj);
    friend std::istream &operator>>(std::istream &in, DotENV &obj);
    friend inline bool operator==(const DotENV &a, const DotENV &b) {
      return a._map == b._map;
    }
    friend inline bool operator!=(const DotENV &a, const DotENV &b) {
      return !(a == b);
    }

    EnvironmentVariableMap _map;

   public:
    static auto instance() -> DotENVInterface & {
      static DotENV dotENV;
      return dotENV;
    }
    const EnvironmentVariableMap &map() const override { return _map; };
    void put(const DotENVLineInterface &entry) override {
      _map[entry.key()] = entry.value();
    };
    bool contains(const EnvironmentVariableKey &key) const override {
      return _map.find(key) != _map.end();
    };
    EnvironmentVariableValue value(
        const EnvironmentVariableKey &key) const override {
      auto dup = _map;
      return dup[key];
    };
  };
}  // namespace extras

#endif  // _EXTRAS_DOT_ENV_HPP