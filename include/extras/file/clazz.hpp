/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
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

#ifndef _EXTRAS_FILE_CLASS_HPP
#define _EXTRAS_FILE_CLASS_HPP

#include <algorithm>
#include <extras/feature/interface.hpp>
#include <extras/file/interface.hpp>
#include <extras/strings.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct user_id;
struct ldap;

namespace extras {
   namespace file {

      /**
       * @brief File class
       *
       */
      concrete class File implements Interface
      {
         Filename _fn;

       public:

         /**
          * @brief Construct a new File object
          *
          * @param fn
          */
         File(const Filename& fn)
           : _fn(fn){};

         /**
          * @brief FileInterface
          *
          */
         virtual Pathname tempname(const Pathname& fn) const
         {
            int fd;
            extras::Pathname tn;
            if (fn.empty()) {
               char filename[] = "/tmp/mytemp.XXXXXX";
               fd = mkstemp(filename);
               tn = filename;
            } else {
               char* filename = const_cast<char*>(fn.c_str());
               fd = mkstemp(filename);
               tn = filename;
            }
            CouldNotCreateTempnameException::assertion(fd, tn, __INFO__);
            close(fd);
            unlink(tn.c_str());
            return tn;
         };

         virtual char seperator() const { return '/'; };

         virtual bool is_dir() const
         {
            if (!this->exists())
               return false;
            extras::Filename fp = this->fullpath();
            struct stat sb;
            if (stat(fp.c_str(), &sb) == 0 && (sb.st_mode & S_IFDIR))
               return true;
            return false;
         };

         virtual bool is_file() const
         {
            return this->exists() && !this->is_dir();
         };

         virtual Filename filename() const
         {
            if (this->fullpath().length() == 0)
               return this->fullpath();
            auto parts =
              extras::str::split(this->fullpath(), this->seperator());
            extras::Filename result = parts.back();
            return result;
         };

         virtual Pathname pathname() const
         {
            if (this->fullpath().length() == 0)
               return this->fullpath();
            auto parts =
              extras::str::split(this->fullpath(), this->seperator());
            parts.pop_back();
            extras::Filename result;
            for (auto part : parts) {
               result += part;
               result += this->seperator();
            }
            return result;
         };

         virtual Pathname fullpath() const { return _fn; };

         virtual bool exists() const
         {
            extras::Filename fp = this->fullpath();
            std::ifstream in(fp);
            return in.good();
         }

         virtual void copy(const Interface&) const
         {
            throw extras::feature::NotImplementedException("copy", __INFO__);
         };

         operator const Filename&() const { return _fn; }
      };

   } // namespace file
} // namespace extras

#endif // _EXTRAS_FILE_CLASS_HPP
