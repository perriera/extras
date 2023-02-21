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

  namespace fs {
    namespace path {

      /**
       * @brief namespace base
       *
       */

      using Path = std::string;

      interface Interface {

		/**
		 * @brief 
		 * 
		 * @return Path 
		 */
		virtual Path current_path_filename() const pure;

		/**
		 * @brief 
		 * 
		 * @param before 
		 * @return Filename 
		 */
		virtual Path path(const Filename& before) const pure;

		/**
		 * @brief 
		 * 
		 * @param before 
		 * @return Filename 
		 */
		virtual Filename path_filename(const Filename& before) const pure;

        /**
         * @brief actualPath
         * @return replace the '~' with the value gained from getenv('home')
         * @exception invalid path supplied
         */
        virtual Path actualPath(const Path& path) const pure;

		/**
		 * @brief 
		 * 
		 * @param src 
		 * @return Filename 
		 */
		virtual Filename directory_iterator(const Directory& src) const pure;

        /**
         * @brief find
         * @param path to be found
         * @return the full path to the actual file being requested
         * @exception invalid path supplied
         *
         * In the case of running the test scripts the build/ directory is
         * not always the place where run-unittests is executed from. In order
         * to make sure that the test scripts run properly, we need to make
         * an educated guess as to where the actual path, (of the file) is.
         *
         */
        virtual Path find(const Path& path) const pure;
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
  }    // namespace fs
}  // namespace extras

#endif  // _EXTRA_PATH_INTERFACE_HPP_
