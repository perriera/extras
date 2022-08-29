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
  namespace file {

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
    concrete class FileException extends extras::AbstractCustomException {
     protected:
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
      static void assertion(const file::Interface&, const extras::WhereAmI&);
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

    /**
     * @brief FileExistsException
     *
     */
    concrete class FileExistsException extends FileException {
     public:
      FileExistsException(const std::string& msg,
                          const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const Filename& filename,
                            const extras::WhereAmI& ref);
    };

    /**
     * @brief FolderExistsException
     *
     */
    concrete class FolderExistsException extends FileException {
     public:
      FolderExistsException(const std::string& msg,
                            const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const file::Interface&,
                            const extras::WhereAmI& ref);
    };

    /**
     * @brief FolderNotFoundException
     *
     */
    concrete class FolderNotFoundException extends FileException {
     public:
      FolderNotFoundException(const std::string& msg,
                              const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const file::Interface&,
                            const extras::WhereAmI& ref);
    };

    /**
     * @brief NotaFolderException
     *
     */
    concrete class NotaFolderException extends FileException {
     public:
      NotaFolderException(const std::string& msg,
                          const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const file::Interface&,
                            const extras::WhereAmI& ref);
    };

    /**
     * @brief NotaFileException
     *
     */
    concrete class NotaFileException extends FileException {
     public:
      NotaFileException(const std::string& msg,
                        const extras::WhereAmI& whereAmI)
          : FileException(msg, whereAmI) {}
      virtual char const* what() const noexcept { return _msg.c_str(); }
      static void assertion(const file::Interface&,
                            const extras::WhereAmI& ref);
    };

  }  // namespace file
}  // namespace extras

#endif  // _EXTRAS_FILE_INTERFACE_HPP
