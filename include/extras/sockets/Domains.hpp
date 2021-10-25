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

  using IPAddress = std::string;
  using DomainName = std::string;

  interface DomainInterface {
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual IPAddress resolve(const DomainName &domainName) const pure;
    virtual DomainName name() const pure;
    virtual IPAddress ip() const pure;
    virtual bool exists() const pure;
  };

  /**
   * @brief PathsInterface
   *
   */

  concrete class Domain implements DomainInterface {
    std::string _domainname;
    std::string _ipaddress;
    bool _exists = false;

   public:
    /**
     * @brief actualPath
     * @return replace the '~' with the value gained from getenv('home')
     * @exception invalid path supplied
     */
    virtual IPAddress resolve(const DomainName &domainName) const override;
    virtual DomainName name() const override { return _domainname; };
    virtual IPAddress ip() const override { return _ipaddress; };
    virtual bool exists() const override { return _exists; };

    static auto instance() -> DomainInterface & {
      static Domain domain;
      return domain;
    }

    Domain(){};
    Domain(const std::string &candidate) : _domainname(candidate) {
      _ipaddress = this->resolve(_domainname);
      _exists = true;
    };

    /**
     * @brief overloaded ~() operator to remove the ~ from the path
     * @return the full path, (where the '~' is replaced with home path)
     */
    Domain &operator~() noexcept { return *this; }
    operator std::string() { return _ipaddress; }
  };

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class DomainException extends AbstractCustomException {
   public:
    DomainException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &response, const DomainName &name);
  };

}  // namespace extras

#endif  // _EXTRA_DOMAINS_HPP
