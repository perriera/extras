// /**
//  * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
//  *
//  * Copyright (C) November 22, 2021 EXPARX INCORPORATED
//  *
//  * Permission is hereby  granted,  free of charge,  to  any  person
//  * obtaining a copy of this software and  associated  documentation
//  * files   (the  "Software"),  to deal  in   the  Software  without
//  * restriction, including  without  limitation the rights  to  use,
//  * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
//  * sell copies of the  Software, and to permit persons  to whom the
//  * Software  is  furnished to  do  so,  subject  to  the  following
//  * conditions:
//  *
//  * (See LICENSE.md for complete details)
//  *
//  */

// #include "extras/filesystem/files.hpp"

// #include <fstream>
// #include <iostream>

// #include "extras/strings/string_support.hpp"

// using namespace std;

// namespace extras {

//   //
//   // simplest crc64 c++ implementation
//   // https://gist.github.com/timepp
//   //

//   Directory::Directory(const Path &path) : _path(path) {
//     auto _filename = filename();
//     auto _pathname = pathname();
//     string listing_file = "/tmp/listing.txt";
//     string cmd = "ls " + _pathname + ">" + listing_file;
//     // system("ls docopt/include -la >/tmp/listing.txt");
//     auto result = system(cmd.c_str());
//     if (result < 0) cout << "Directory listing unsuccessful" << endl;
//     ifstream listing_stream(listing_file);
//     Listing listing;
//     while (listing_stream.good()) {
//       string listing_line;
//       listing_stream >> listing_line;
//       if (listing_line.size() > 0) {
//         listing_line = _pathname + listing_line;
//         listing.push_back(listing_line);
//       }
//     }
//     this->_listing = listing;
//     if (!this->fileExists()) this->_listing = Listing();
//   }

//   std::string Directory::filename() const {
//     if (ends_with(_path, "/")) return "";
//     auto parts = split(_path, '/');
//     if (parts.size() > 0)
//       return parts[parts.size() - 1];
//     else
//       return _path;
//   }

//   std::string Directory::pathname() const {
//     if (ends_with(_path, "/")) return _path;
//     auto parts = split(_path, '/');
//     if (parts.size() > 0) {
//       auto filename = parts[parts.size() - 1];
//       auto pathname = replace_all(_path, filename, "");
//       return pathname;
//     } else
//       return "./";
//   }

//   bool Directory::fileExists() const {
//     for (auto entry : this->_listing) {
//       if (entry == _path) return true;
//     }
//     if (filename() == "") return true;
//     return false;
//   }

//   void Directory::copyTo(const Directory &to) const {
//     FileNotFoundException::assertion(path(), __INFO__);
//     ifstream src;
//     ofstream dst;
//     src.open(path(), ios::in | ios::binary);
//     dst.open(to.path(), ios::out | ios::binary);
//     dst << src.rdbuf();
//     src.close();
//     dst.close();
//   }

//   void Directory::remove() const {
//     string cmd = "rm -rf " + path();
//     auto result = system(cmd.c_str());
//     if (result < 0) cout << "Directory remove() unsuccessful" << endl;
//   }

// }  // namespace extras
