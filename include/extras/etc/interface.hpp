/**
 * @file FileInterface.hpp
 * @author Perry Anderson (perryand@yorku.ca)
 * @brief define standard methods for FileInterface
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright (C) Friday, July 29, 2022 EXPARX, Inc.
 *
 */

#ifndef _EXTRAS_ETC_INTERFACE_HPP
#define _EXTRAS_ETC_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
  namespace etc {

    /**
     * @brief
     *
     */
    using Filename = std::string;
    using Directory = std::vector<Filename>;

    /**
     * @brief etc::Interface
     *
     *    Given we need to keep configuration entires in a file
     *    When we arrange configuration items in keypair format
     *    Then we can retrieve values quickly.
     *
     */
    interface Interface {
      /**
       * @brief the name of the file
       *
       * @return Filename
       */
      virtual Filename filename() const pure;
      /**
       * @brief test that file exists
       *
       * @return true the file exists
       * @return false otherwise
       */
      virtual bool exists() const pure;
      /**
       * @brief copy a file
       *
       * @param destination
       */
      virtual void copy(const Interface& destination) const pure;
    };

    /**
     * @brief FileException
     *
     */
    concrete class Exception extends extras::AbstractCustomException {
     protected:
      Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
          : AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                    whereAmI._func.c_str(), whereAmI._line) {}
    };

    /**
     * @brief FileNotFoundException
     *
     */
    concrete class NotFoundException extends Exception {
     public:
      NotFoundException(const std::string& msg,
                        const extras::WhereAmI& whereAmI)
          : Exception(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const Filename& filename,
                            const extras::WhereAmI& ref);
    };
  }  // namespace etc
}  // namespace extras

#endif  // _EXTRAS_ETC_INTERFACE_HPP
