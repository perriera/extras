#ifndef _EXTRAS_DOT_ENV_HPP
#define _EXTRAS_DOT_ENV_HPP

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

#include <extras/interfaces.hpp>
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
    virtual EnvironmentVariableKey validate_key(const std::string &key)
        const pure;
    virtual EnvironmentVariableValue validate_value(const std::string &value)
        const pure;
  };

  /**
   * @brief interface DotENVLineInterface
   *
   */

  class DotENVLine implements DotENVLineInterface {
    friend std::ostream &operator<<(std::ostream &out, const DotENVLine &obj);
    friend std::istream &operator>>(std::istream &in, DotENVLine &obj);

    EnvironmentVariableKey _key;
    EnvironmentVariableValue _value;

   public:
    DotENVLine(){};
    DotENVLine(const EnvironmentVariableKey &key,
               const EnvironmentVariableValue &value)
        : _key(key), _value(value){};
    const EnvironmentVariableKey &key() const override { return _key; }
    const EnvironmentVariableValue &value() const override { return _value; }
    EnvironmentVariableKey validate_key(const std::string &key) const override;
    EnvironmentVariableValue validate_value(
        const std::string &value) const override;
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
    virtual EnvironmentVariableValue value(const EnvironmentVariableKey &key)
        const pure;
  };

  /**
   * @brief class DotENV
   *
   */

  concrete class DotENV implements DotENVInterface {
    friend std::ostream &operator<<(std::ostream &out, const DotENV &obj);
    friend std::istream &operator>>(std::istream &in, DotENV &obj);

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