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

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <extras/file/clazz.hpp>
#include <extras/filesystem/files.hpp>
#include <extras/strings/string_support.hpp>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
using namespace extras;
using namespace extras::file;

/**
 * @brief FileNotFoundException::assertion
 *
 * @param filename
 * @param ref
 */
void file::NotFoundException::assertion(const Filename& filename,
                                        const WhereAmI& ref) {
  ifstream f(filename.c_str());
  if (!f.good()) throw file::NotFoundException(filename, ref);
}

/**
 * @brief FilenameInvalidException::assertion
 *
 * @param filename
 * @param ref
 */
void file::InvalidNameException::assertion(const Filename& filename,
                                           const WhereAmI& ref) {
  if (filename.length() == 0)
    throw file::InvalidNameException("no filename specified", ref);
  string valid_filename = "^[^<>:;,?\"*|/]+$";
  auto parts = extras::str::split(filename, '/');
  regex valid_filename_expr(valid_filename);
  for (auto part : parts) {
    if (part.length() == 0)
      throw file::InvalidNameException("no folder name specified", ref);
    if (!regex_match(part, valid_filename_expr) || part == "\\")
      throw file::InvalidNameException(filename, ref);
  }
}

/**
 * @brief FileNotCopiedException::assertion
 *
 * @param fi
 * @param ref
 */
void NotCopiedException::assertion(const Interface& fi, const WhereAmI& ref) {
  ifstream f(fi.filename().c_str());
  if (!f.good()) {
    throw NotCopiedException(fi.filename(), ref);
  }
}

/**
 * @brief FileExistsException::assertion
 *
 * @param filename
 * @param ref
 */
void ExistsException::assertion(const Filename& filename, const WhereAmI& ref) {
  ifstream f(filename);
  if (f.good()) throw ExistsException(filename, ref);
}

/**
 * @brief FolderExistsException::assertion
 *
 * @param filename
 * @param ref
 */
void FolderExistsException::assertion(const Interface&, const WhereAmI&) {
  // struct stat statbuf;
  // string name = fi.filename();
  // if (stat(name.c_str(), &statbuf) != 0) {
  //   throw FileNotFoundException(name, ref);
  // }
  // if (S_ISDIR(statbuf.st_mode)) throw FolderExistsException(fi.filename(),
  // ref);
  throw extras::feature::NotImplementedException(
      "FolderExistsException::assertion()", __INFO__);
}

/**
 * @brief FolderNotFoundException::assertion
 *
 * @param filename
 * @param ref
 */
void FolderNotFoundException::assertion(const Interface&, const WhereAmI&) {
  // ifstream f(fi.filename().c_str());
  // if (!f.good()) throw FolderNotFoundException(fi.filename(), ref);
  throw extras::feature::NotImplementedException(
      "FolderNotFoundException::assertion()", __INFO__);
}

/**
 * @brief NotaFolderException::assertion
 *
 * @param filename
 * @param ref
 */
void NotaFolderException::assertion(const Interface&, const WhereAmI&) {
  // struct stat statbuf;
  // if (stat(fi.filename().c_str(), &statbuf) != 0)
  //   throw NotaFolderException(fi.filename(), ref);
  // if (!S_ISDIR(statbuf.st_mode)) throw NotaFolderException(fi.filename(),
  // ref);
  throw extras::feature::NotImplementedException(
      "NotaFolderException::assertion()", __INFO__);
}

/**
 * @brief NotaFileException::assertion
 *
 * @param filename
 * @param ref
 */
void NotaFileException::assertion(const Interface&, const WhereAmI&) {
  // ifstream f(fi.filename().c_str());
  // if (!f.good()) throw NotaFileException(fi.filename(), ref);
  throw extras::feature::NotImplementedException(
      "NotaFileException::assertion()", __INFO__);
}
