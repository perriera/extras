/**
 * @file paths.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief PathsInterface, (deperacated in lue of C++11/std::filesystem)
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRA_PATHS_HPP
#define _EXTRA_PATHS_HPP

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
 * (See LICENSE.md for complete details)
 *
 */

#include <extras/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <iostream>

namespace extras {

   /**
    * @brief PathsInterface
    *
    */

   using Path = std::string;

   interface PathsInterface
   {
      /**
       * @brief actualPath
       * @return replace the '~' with the value gained from getenv('home')
       * @exception invalid path supplied
       */
      virtual Path actualPath(const Path& path) const pure;

      /**
       * @brief find
       * @param path to be found
       * @return the full path to the actual file being requested
       * @exception invalid path supplied
       *
       * In the case of running the test scripts the build/ directory is
       * not always the place where run-unittests is executed from. In order
       * to make sure that the test scripts run properly, we need to make
       * an educated guess as to where the actual path, (of the file) is.
       *
       */
      virtual Path find(const Path& path) const pure;
   };

   /**
    * @brief PathsInterface
    *
    */

   concrete class Paths implements PathsInterface
   {
      std::string _path;

    public:

      /**
       * @brief actualPath
       * @return replace the '~' with the value gained from getenv('home')
       * @exception invalid path supplied
       */
      virtual std::string actualPath(const std::string& path) const override;

      virtual Path find(const Path& path) const override;

      static auto instance() -> PathsInterface&
      {
         static Paths paths;
         return paths;
      }

      Paths(){};

      Paths(const std::string& path)
        : _path(path)
      {
         _path = actualPath(_path);
      };

      /**
       * @brief overloaded ~() operator to remove the ~ from the path
       * @return the full path, (where the '~' is replaced with home path)
       */
      Paths& operator~() noexcept { return *this; }

      operator std::string() { return actualPath(_path); }

      operator const char*() { return _path.c_str(); }

      const char* c_str() { return _path.c_str(); }

      const std::string& str() { return _path; }
   };

   /**
    * @brief OctalException
    *
    * To be thrown if either string or value supplied is out of range.
    *
    */
   concrete class PathsException extends AbstractCustomException
   {
    public:

      PathsException(const char* msg, const WhereAmI& whereAmI)
        : AbstractCustomException(msg,
                                  whereAmI._file.c_str(),
                                  whereAmI._func.c_str(),
                                  whereAmI._line)
      {
      }

      static void assertion(const std::string& row_col, const WhereAmI& ref)
      {
         if (row_col.length() != 2 || row_col[0] < 'a' || row_col[0] > 'h' ||
             row_col[1] < '0' || row_col[0] > '7') {
            throw PathsException(row_col.c_str(), ref);
         }
      }

      static void assertion(int octalValue, const WhereAmI& ref)
      {
         if (octalValue < 0 || octalValue > 7) {
            throw SpecificCustomException(std::to_string(octalValue).c_str(),
                                          ref);
         }
      }
   };

} // namespace extras

#endif // _EXTRA_PATHS_HPP
