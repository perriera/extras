#ifndef _EXTRA_DIRECTORY_HPP
#define _EXTRA_DIRECTORY_HPP

#include "extra/interfaces.hpp"
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

class FileNotFoundException extends std::exception {
  std::string _msg;

public:
  FileNotFoundException(const std::string &filename) {
    _msg = "File not found: " + filename;
  }
  virtual char const *what() const noexcept { return _msg.c_str(); }
  static void assertion(const std::string &filename) {
    if (Directory(filename).filename().size() > 0)
      if (!Directory(filename).fileExists())
        throw FileNotFoundException(filename);
  }
};

class PathNotFoundException extends std::exception {
  std::string _msg;

public:
  PathNotFoundException(const std::string &pathname) {
    _msg = "Path not found: " + pathname;
  }
  virtual char const *what() const noexcept { return _msg.c_str(); }
  static void assertion(const std::string &pathname) {
    if (Directory(pathname).pathname().size() > 0)
      if (!Directory(pathname).fileExists())
        throw PathNotFoundException(pathname);
  }
};
} // namespace extras

#endif // _EXTRA_DIRECTORY_HPP
