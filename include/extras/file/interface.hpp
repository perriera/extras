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
       * @brief file::Interface
       *
       */
      interface Interface
      {

         /**
          * @briefseperator
          *
          * @return Pathname
          */
         virtual char seperator() const pure;

         /**
          * @brief the name of the renumber
          *
          * @return Filename
          */
         virtual Pathname pathname() const pure;

         /**
          * @brief the name of the file
          *
          * @return Filename
          */
         virtual Filename filename() const pure;

         /**
          * @brief the name of the file
          *
          * @return Filename
          */
         virtual Pathname fullpath() const pure;

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
      concrete class Exception extends extras::AbstractCustomException
      {
       protected:

         Exception(const std::string& msg, const extras::WhereAmI& whereAmI)
           : AbstractCustomException(msg.c_str(),
                                     whereAmI._file.c_str(),
                                     whereAmI._func.c_str(),
                                     whereAmI._line)
         {
         }
      };

      /**
       * @brief FileNotFoundException
       *
       */
      concrete class NotFoundException extends Exception
      {
       public:

         NotFoundException(const std::string& msg,
                           const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref);
      };

      /**
       * @brief FileNotCopiedException
       *
       */
      concrete class NotCopiedException extends Exception
      {
       public:

         NotCopiedException(const std::string& msg,
                            const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const file::Interface&, const extras::WhereAmI&);
      };

      /**
       * @brief FilenameInvalidException
       *
       */
      concrete class InvalidNameException extends Exception
      {
       public:

         InvalidNameException(const std::string& msg,
                              const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref);
      };

      /**
       * @brief FileExistsException
       *
       */
      concrete class ExistsException extends Exception
      {
       public:

         ExistsException(const std::string& msg,
                         const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref);
      };

      /**
       * @brief FolderExistsException
       *
       */
      concrete class FolderExistsException extends Exception
      {
       public:

         FolderExistsException(const std::string& msg,
                               const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const file::Interface&,
                               const extras::WhereAmI& ref);
         static void assertion(const Filename&, const extras::WhereAmI& ref);
      };

      concrete class FolderNotSpecifiedException extends FolderExistsException
      {
       public:

         FolderNotSpecifiedException(const extras::WhereAmI& whereAmI)
           : FolderExistsException("no filename specified", whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }
      };

      concrete class NotAFolderException extends FolderExistsException
      {
       public:

         NotAFolderException(const Filename& msg,
                             const extras::WhereAmI& whereAmI)
           : FolderExistsException(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }
      };

      concrete class NotAFolderNameException extends FolderExistsException
      {
       public:

         NotAFolderNameException(const Filename& msg,
                                 const extras::WhereAmI& whereAmI)
           : FolderExistsException(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }
      };

      /**
       * @brief FolderNotFoundException
       *
       */
      concrete class FolderNotFoundException extends Exception
      {
       public:

         FolderNotFoundException(const std::string& msg,
                                 const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const file::Interface&,
                               const extras::WhereAmI& ref);
      };

      /**
       * @brief NotaFolderException
       *
       */
      concrete class NotaFolderException extends Exception
      {
       public:

         NotaFolderException(const std::string& msg,
                             const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const file::Interface&,
                               const extras::WhereAmI& ref);
      };

      /**
       * @brief NotaFileException
       *
       */
      concrete class NotaFileException extends Exception
      {
       public:

         NotaFileException(const std::string& msg,
                           const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const file::Interface&,
                               const extras::WhereAmI& ref);
      };

   } // namespace file
} // namespace extras

#endif // _EXTRAS_FILE_INTERFACE_HPP
