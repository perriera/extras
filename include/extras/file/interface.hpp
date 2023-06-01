/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#ifndef _EXTRAS_FILE_INTERFACE_HPP
#define _EXTRAS_FILE_INTERFACE_HPP

#include <algorithm>
#include <extras/interfaces.hpp>
#include <fstream>
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
          * @brief tempname
          *
          * @return Pathname
          */
         virtual Pathname tempname(const Pathname&) const pure;

         /**
          * @brief seperator
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
          * @brief is_dir
          *
          * @return true
          * @return false
          */
         virtual bool is_dir() const pure;

         /**
          * @brief is_file
          *
          * @return true
          * @return false
          */
         virtual bool is_file() const pure;

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
       * @brief file::Exception
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
                               const extras::WhereAmI& ref)
         {
            std::ifstream f(filename.c_str());
            if (!f.good())
               throw file::NotFoundException(filename, ref);
         }
      };

      /**
       * @brief FoundException
       *
       */
      concrete class FoundException extends Exception
      {
       public:

         FoundException(const std::string& msg,
                        const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref)
         {
            std::ifstream in(filename);
            if (in.good())
               throw FoundException(filename, ref);
         }
      };

      /**
       * @brief NewFoundException
       * @note file exists (but not suppose to)
       * @note (aka. great for test case setups)
       */
      concrete class NewFoundException extends Exception
      {
       public:

         NewFoundException(const std::string& msg,
                           const extras::WhereAmI& whereAmI)
           : Exception(msg, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(const Filename& filename,
                               const extras::WhereAmI& ref)
         {
            std::ifstream in(filename);
            if (in.good())
               throw NewFoundException(filename, ref);
         }
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

      /**
       * @brief CouldNotCreateTempnameException
       *
       */
      concrete class CouldNotCreateTempnameException extends Exception
      {
       public:

         CouldNotCreateTempnameException(const Pathname& filename,
                                         const extras::WhereAmI& whereAmI)
           : Exception(filename, whereAmI)
         {
         }

         virtual char const* what() const noexcept { return _msg.c_str(); }

         static void assertion(int fd,
                               const Pathname& filename,
                               const extras::WhereAmI& ref)
         {
            if (fd == -1)
               throw CouldNotCreateTempnameException(filename, ref);
         }
      };

   } // namespace file
} // namespace extras

#endif // _EXTRAS_FILE_INTERFACE_HPP
