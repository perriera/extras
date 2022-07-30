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

#ifndef _EXTRAS_FILE_INTERFACE_HPP
#define _EXTRAS_FILE_INTERFACE_HPP

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
      /**
       * @brief copy a file
       *
       * @param destination
       */
      virtual void copy(const FileInterface& destination) const pure;
    };

    /**
     * @brief FileException
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
     * @brief FileNotCopiedException
     *
     */
    concrete class FileNotCopiedException extends FileException {
     public:
      FileNotCopiedException(const std::string& msg,
                             const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const system::FileInterface&,
                            const extras::WhereAmI&);
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

#endif  // _EXTRAS_FILE_INTERFACE_HPP
