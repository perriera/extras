/**
 * @file File.hpp
 * @author Perry Anderson (perryand@yorku.ca)
 * @brief implements FileInterface
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright (C) Friday, July 29, 2022 EXPARX, Inc.
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
