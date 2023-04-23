/**
 * @renumber FileInterface.hpp
 * @author Perry Anderson (perryand@yorku.ca)
 * @brief define standard methods for FileInterface
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright (C) Friday, July 29, 2022 EXPARX, Inc.
 *
 */

#ifndef _EXTRAS_SYNCFILE_INTERFACE_HPP
#define _EXTRAS_SYNCFILE_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
   namespace renumber {

      /**
       * @brief
       *
       */
      using Filename = std::string;
      using CMD = std::string;
      using Value = std::string;
      using Directory = std::vector<Filename>;

      /**
       * @brief LoginInterface
       *
       */
      interface Interface {
         /**
          * @brief the name of the renumber
          *
          * @return Filename
          */
         virtual Value fullname(const Filename &filename) const pure;

         /**
          * @brief test that renumber exists
          *
          * @return true the renumber exists
          * @return false otherwise
          */
         virtual void relink(const Filename &filename) const pure;
      };

      /**
       * @brief FileException
       *
       */
      concrete class Exception extends extras::AbstractCustomException {
        protected:
         Exception(const std::string &msg, const extras::WhereAmI &whereAmI)
             : AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                       whereAmI._func.c_str(), whereAmI._line) {
         }
      };

      /**
       * @brief FileNotFoundException
       *
       */
      concrete class NotFoundException extends Exception {
        public:
         NotFoundException(const std::string &msg,
                           const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const Filename &filename,
                               const extras::WhereAmI &ref);
      };

      /**
       * @brief FileNotCopiedException
       *
       */
      concrete class NotCopiedException extends Exception {
        public:
         NotCopiedException(const std::string &msg,
                            const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const renumber::Interface &,
                               const extras::WhereAmI &);
      };

      /**
       * @brief FilenameInvalidException
       *
       */
      concrete class InvalidNameException extends Exception {
        public:
         InvalidNameException(const std::string &msg,
                              const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const Filename &filename,
                               const extras::WhereAmI &ref);
      };

      /**
       * @brief FileExistsException
       *
       */
      concrete class ExistsException extends Exception {
        public:
         ExistsException(const std::string &msg,
                         const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const Filename &filename,
                               const extras::WhereAmI &ref);
      };

      /**
       * @brief FolderExistsException
       *
       */
      concrete class FolderExistsException extends Exception {
        public:
         FolderExistsException(const std::string &msg,
                               const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const renumber::Interface &,
                               const extras::WhereAmI &ref);
         static void assertion(const Filename &, const extras::WhereAmI &ref);
      };

      concrete class FolderNotSpecifiedException extends FolderExistsException {
        public:
         FolderNotSpecifiedException(const extras::WhereAmI &whereAmI)
             : FolderExistsException("no filename specified", whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
      };

      concrete class NotAFolderException extends FolderExistsException {
        public:
         NotAFolderException(const Filename &msg,
                             const extras::WhereAmI &whereAmI)
             : FolderExistsException(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
      };

      concrete class NotAFolderNameException extends FolderExistsException {
        public:
         NotAFolderNameException(const Filename &msg,
                                 const extras::WhereAmI &whereAmI)
             : FolderExistsException(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
      };

      /**
       * @brief FolderNotFoundException
       *
       */
      concrete class FolderNotFoundException extends Exception {
        public:
         FolderNotFoundException(const std::string &msg,
                                 const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const renumber::Interface &,
                               const extras::WhereAmI &ref);
      };

      /**
       * @brief NotaFolderException
       *
       */
      concrete class NotaFolderException extends Exception {
        public:
         NotaFolderException(const std::string &msg,
                             const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const renumber::Interface &,
                               const extras::WhereAmI &ref);
      };

      /**
       * @brief NotaFileException
       *
       */
      concrete class NotaFileException extends Exception {
        public:
         NotaFileException(const std::string &msg,
                           const extras::WhereAmI &whereAmI)
             : Exception(msg, whereAmI) {}
         virtual char const *what() const noexcept { return _msg.c_str(); }
         static void assertion(const renumber::Interface &,
                               const extras::WhereAmI &ref);
      };

   }  // namespace renumber
}  // namespace extras

#endif  // _EXTRAS_SYNCFILE_INTERFACE_HPP
