/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * The above copyright notice and  this permission  notice shall be
 * included in all copies or  substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESSED  OR   IMPLIED,  INCLUDING   BUT  NOT  LIMITED  TO  THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE
 * AND NON-INFRINGEMENT.  IN  NO  EVENT  SHALL EXPARX  INCORPORATED
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM, OUT  OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Except  as  contained  in this  notice, the  name of  the EXPARX
 * INCORPORATED shall not  be used in  advertising or  otherwise to
 * promote the sale, use or other dealings in this Software without
 * prior written authorization from EXPARX INCORPORATED.
 *
 * exparx.com and www.exparx.com  are domain names  registered with
 * EXPARX INCORPORATED, (other GPL-themed licenses are included).
 *
 */

#ifndef _EXTRA_DIRECTORY_HPP
#define _EXTRA_DIRECTORY_HPP

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <iostream>
#include <vector>

namespace extras {
  //
  // simplest crc16 c++ implementation
  // https://github.com/jpralves/crc16
  //

  typedef std::string Path;
  typedef std::vector<std::string> Listing;

  interface DirectoryInterface {
    virtual const Path &path() const pure;
    virtual const Listing &listing() const pure;
    virtual std::string filename() const pure;
    virtual std::string pathname() const pure;
    virtual bool fileExists() const pure;
  };

  class Directory implements DirectoryInterface {
   public:
    Directory(const Path &path);

    virtual const Path &path() const { return _path; }
    virtual const Listing &listing() const { return _listing; }
    virtual std::string filename() const;
    virtual std::string pathname() const;
    virtual bool fileExists() const;
    virtual void copyTo(const Directory &pathname) const;
    virtual void remove() const;

   private:
    Path _path;
    Listing _listing;
  };

  class FileNotFoundException extends AbstractCustomException {
    std::string _msg;

   public:
    FileNotFoundException(const std::string &filename,
                          const extras::WhereAmI &whereAmI)
        : AbstractCustomException(filename.c_str(), whereAmI) {
      _msg = "File not found: " + filename;
    }
    virtual char const *what() const noexcept { return _msg.c_str(); }
    static void assertion(const std::string &filename,
                          const extras::WhereAmI &ref) {
      if (Directory(filename).filename().size() > 0)
        if (!Directory(filename).fileExists())
          throw FileNotFoundException(filename, ref);
    }
  };

  class PathNotFoundException extends AbstractCustomException {
    std::string _msg;

   public:
    PathNotFoundException(const std::string &filename,
                          const extras::WhereAmI &whereAmI)
        : AbstractCustomException(filename.c_str(), whereAmI) {
      _msg = "Path not found: " + filename;
    }
    virtual char const *what() const noexcept { return _msg.c_str(); }
    static void assertion(const std::string &filename,
                          const extras::WhereAmI &ref) {
      if (Directory(filename).filename().size() > 0)
        if (!Directory(filename).fileExists())
          throw PathNotFoundException(filename, ref);
    }
  };

}  // namespace extras

#endif  // _EXTRA_DIRECTORY_HPP
