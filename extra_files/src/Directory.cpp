#include "extra/Directory.hpp"
#include "extra/string_support.hpp"
#include <fstream>
#include <iostream>

using namespace std;

namespace extras {

//
// simplest crc64 c++ implementation
// https://gist.github.com/timepp
//

Directory::Directory(const Path &path) : _path(path) {
  auto _filename = filename();
  auto _pathname = pathname();
  string listing_file = "/tmp/listing.txt";
  string cmd = "ls -a " + _pathname + ">" + listing_file;
  // system("ls docopt/include -la >/tmp/listing.txt");
  system(cmd.c_str());
  ifstream listing_stream(listing_file);
  Listing listing;
  while (listing_stream.good()) {
    string listing_line;
    listing_stream >> listing_line;
    if (listing_line.size() > 0) {
      listing_line = _pathname + listing_line;
      listing.push_back(listing_line);
    }
  }
  this->_listing = listing;
  if (!this->fileExists())
    this->_listing = Listing();
};

std::string Directory::filename() const {
  if (ends_with(_path, "/"))
    return "";
  auto parts = split(_path, '/');
  if (parts.size() > 0)
    return parts[parts.size() - 1];
  else
    return _path;
}

std::string Directory::pathname() const {
  if (ends_with(_path, "/"))
    return _path;
  auto parts = split(_path, '/');
  if (parts.size() > 0) {
    auto filename = parts[parts.size() - 1];
    auto pathname = replace_all(_path, filename, "");
    return pathname;
  } else
    return "./";
}

bool Directory::fileExists() const {
  for (auto entry : this->_listing) {
    if (entry == _path)
      return true;
  }
  if (filename() == "")
    return true;
  return false;
}

void Directory::copyTo(const Directory &to) const {
  FileNotFoundException::assertion(path());
  ifstream src;
  ofstream dst;
  src.open(path(), ios::in | ios::binary);
  dst.open(to.path(), ios::out | ios::binary);
  dst << src.rdbuf();
  src.close();
  dst.close();
}

void Directory::remove() const {
  string cmd = "rm -rf " + path();
  system(cmd.c_str());
}

} // namespace extras
