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

#ifndef _FILEINTERFACE_HPP
#define _FILEINTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
  namespace system {

    /**
     * @brief
     *
     */
    using Filename = std::string;
    using Directory = std::vector<Filename>;

    /**
     * @brief LoginInterface
     *
     */
    interface FileInterface {
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
    };

    /**
     * @brief LoginException
     *
     */

    concrete class FileException extends extras::AbstractCustomException {
     public:
      FileException(const std::string& msg, const extras::WhereAmI& whereAmI)
          : AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                    whereAmI._func.c_str(), whereAmI._line) {}
    };

    /**
     * @brief FileNotFoundException
     *
     */
    concrete class FileNotFoundException extends FileException {
     public:
      FileNotFoundException(const std::string& msg,
                            const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const Filename& filename,
                            const extras::WhereAmI& ref);
    };

    /**
     * @brief FilenameInvalidException
     *
     */
    concrete class FilenameInvalidException extends FileException {
     public:
      FilenameInvalidException(const std::string& msg,
                               const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const Filename& filename,
                            const extras::WhereAmI& ref);
    };

  }  // namespace system
}  // namespace extras

#endif  // _FILEINTERFACE_HPP
