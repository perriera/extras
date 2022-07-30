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

#ifndef _EXTRAS_FEATURE_INTERFACE_HPP
#define _EXTRAS_FEATURE_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
  namespace feature {

    /**
     * @brief LoginInterface
     *
     */
    interface FeatureInterface {};

    /**
     * @brief FileException
     *
     */
    concrete class FeatureException extends extras::AbstractCustomException {
     public:
      FeatureException(const std::string& msg, const extras::WhereAmI& whereAmI)
          : AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                    whereAmI._func.c_str(), whereAmI._line) {}
    };

    /**
     * @brief NotImplementedException
     *
     */
    concrete class NotImplementedException extends FeatureException {
     public:
      NotImplementedException(const std::string& msg,
                              const extras::WhereAmI& whereAmI)
          : FeatureException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
    };

  }  // namespace feature
}  // namespace extras

#endif  // _EXTRAS_FEATURE_INTERFACE_HPP
