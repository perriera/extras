/**
 * @file filesystem.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief extra's std::filesystem methods, (for use with std::filesystem)
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXTRAS_FILESYSTEM_HPP
#define _EXTRAS_FILESYSTEM_HPP

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
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief FileSystemInterface
   *
   */

  interface FileSystemInterface {
    virtual const Path& path() const pure;
    virtual const Pathname& pathname() const pure;
    virtual const Filename& filename() const pure;
    virtual const Extension& extension() const pure;
    virtual Path prepend(const Directoryname& dir) const pure;
    virtual Path append(const Directoryname& dir) const pure;
  };

  /**
   * @brief FileSystem
   *
   */

  class FileSystem implements FileSystemInterface {
    Path strip_first(const Directoryname& dir) const;
    Path strip_last(const Directoryname& dir) const;

   public:
    FileSystem(const Path& path);
    virtual const Path& path() const override { return _path; };
    virtual const Pathname& pathname() const override { return _pathname; };
    virtual const Filename& filename() const override { return _filename; };
    virtual const Extension& extension() const override { return _extension; };
    virtual Path prepend(const Directoryname& dir) const override;
    virtual Path append(const Directoryname& dir) const override;

   private:
    Path _path;
    Pathname _pathname;
    Filename _filename;
    Extension _extension;
  };

}  // namespace extras

#endif  // _EXTRAS_FILESYSTEM_HPP