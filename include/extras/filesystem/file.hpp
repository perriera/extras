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

#ifndef _FILE_HPP
#define _FILE_HPP

#include <algorithm>
#include <extras/filesystem/fileinterface.hpp>
#include <iostream>
#include <list>

struct user_id;
struct ldap;

namespace extras {
  namespace system {

    /**
     * @brief File class
     *
     */
    concrete class File implements FileInterface {
      Filename _fn;

     public:
      File(const Filename& fn) : _fn(fn) {}
      /**
       * @brief the name of the file
       *
       * @return Filename
       */
      virtual Filename filename() const { return _fn; };
      /**
       * @brief test that file exists
       *
       * @return true the file exists
       * @return false otherwise
       */
      virtual bool exists() const;
    };

  }  // namespace system
}  // namespace extras

#endif  // _FILE_HPP
