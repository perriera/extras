#ifndef _EXTRA_DOMAINS_HPP
#define _EXTRA_DOMAINS_HPP

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief PathsInterface
   *
   */

  interface DomainInterface {
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual bool isIPAddress(const std::string &ipAddress) const pure;
  };

  /**
   * @brief PathsInterface
   *
   */

  concrete class Domain implements DomainInterface {
    std::string _domainname;
    std::string _ipaddress;

   public:
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual bool isIPAddress(const std::string &ipAddress) const override;

    static auto instance() -> DomainInterface & {
      static Domain domain;
      return domain;
    }

    Domain(){};
    Domain(const std::string &candidate) : _domainname(candidate){};

    /**
     * @brief overloaded ~() operator to remove the ~ from the path
     * @return the full path, (where the '~' is replaced with home path)
     */
    Paths &operator~() noexcept { return *this; }
    operator std::string() { return actualPath(_path); }
  };

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class PathsException extends AbstractCustomException {
   public:
    PathsException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &row_col, const WhereAmI &ref) {
      if (row_col.length() != 2 || row_col[0] < 'a' || row_col[0] > 'h' ||
          row_col[1] < '0' || row_col[0] > '7') {
        throw PathsException(row_col.c_str(), ref);
      }
    }
    static void assertion(int octalValue, const WhereAmI &ref) {
      if (octalValue < 0 || octalValue > 7) {
        throw SpecificCustomException(std::to_string(octalValue).c_str(), ref);
      }
    }
  };

}  // namespace extras

#endif  // _EXTRA_DOMAINS_HPP
