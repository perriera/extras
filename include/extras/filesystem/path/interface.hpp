/**
 * @file interface.hpp
 * @author Owen Jones (ojones@yorku.ca), Perry Anderson (perryand@yorku.ca)
 * @brief declation of sis::dbo::base::Interface
 * @version 0.2
 * @date 2022-10-31
 *
 * @copyright (C) Copyright 2022, York University
 *
 */

#ifndef _EXTRA_PATH_INTERFACE_HPP_
#define _EXTRA_PATH_INTERFACE_HPP_

#include <extras/interfaces.hpp>
#include <iostream>
#include <set>

namespace extras {

  namespace fs1 {
    namespace path {

      /**
       * @brief namespace base
       *
       */

      interface Interface {
        // status value 0 is always "success"

        /**
         * @brief isSuccess()
         * @note value 0 is always "success"
         * @return int
         */
        virtual void isSuccess() const pure;
      };

      /**
       * @brief base::Exception
       *
       */

      concrete class Exception extends extras::AbstractCustomException {
       public:
        Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
            : AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                      whereAmI._func.c_str(), whereAmI._line) {}
      };

    }  // namespace path
  }    // namespace fs1
}  // namespace extras

#endif  // _EXTRA_PATH_INTERFACE_HPP_
