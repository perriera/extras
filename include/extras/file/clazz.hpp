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
#include <iostream>
#include <list>

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

         File(const Filename& fn)
           : _fn(fn){};

         /**
          * @brief FileInterface
          *
          */
         virtual Pathname tempname() const
         {
            throw extras::feature::NotImplementedException("tempname",
                                                           __INFO__);
         };

         virtual char seperator() const
         {
            throw extras::feature::NotImplementedException("seperator",
                                                           __INFO__);
         };

         virtual bool is_dir() const
         {
            throw extras::feature::NotImplementedException("is_dir", __INFO__);
         };

         virtual bool is_file() const
         {
            throw extras::feature::NotImplementedException("is_file", __INFO__);
         };

         virtual Filename filename() const { return _fn; };

         virtual Pathname pathname() const
         {
            throw extras::feature::NotImplementedException("pathname",
                                                           __INFO__);
         };

         virtual Pathname fullpath() const
         {
            throw extras::feature::NotImplementedException("fullpath",
                                                           __INFO__);
         };

         virtual bool exists() const;

         virtual void copy(const Interface&) const
         {
            throw extras::feature::NotImplementedException("copy", __INFO__);
         };

         operator const Filename&() const { return _fn; }
      };

   } // namespace file
} // namespace extras

#endif // _EXTRAS_FILE_CLASS_HPP
