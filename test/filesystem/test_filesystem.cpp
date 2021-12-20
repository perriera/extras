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

#include <cstdint>
#include <extras/exceptions.hpp>
#include <extras/filesystem/filesystem.hpp>
#include <extras/strings.hpp>
#include <fstream>

#include "../vendor/catch.hpp"

using namespace extras;

/**
 * @brief extras:::FileSystem test cases
 *
 */

SCENARIO("Test FileSystem case #1", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras/";
  Filename filename = "run-unittests-extras";
  Extension extension = "exe";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #2", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras/";
  Filename filename = "run-unittests-extras";
  Extension extension = "";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #3", "[FileSystemInterface]") {
  Pathname pathname = "";
  Filename filename = "";
  Extension extension = "";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #4", "[FileSystemInterface]") {
  Pathname pathname = " ";
  Filename filename = "";
  Extension extension = "";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #5", "[FileSystemInterface]") {
  Pathname pathname = " ";
  Filename filename = "run-unittests-extras";
  Extension extension = "";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #6", "[FileSystemInterface]") {
  Pathname pathname = "";
  Filename filename = "";
  Extension extension = "exe";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem case #7", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras/";
  Filename filename = "";
  Extension extension = "";
  Path path = pathname + filename + (extension != "" ? "." : "") + extension;
  FileSystem fs(path);
  REQUIRE(fs.path() == path);
  REQUIRE(fs.pathname() == pathname);
  REQUIRE(fs.filename() == filename);
  REQUIRE(fs.extension() == extension);
}

SCENARIO("Test FileSystem prepend/append: #1", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras/";
  Filename filename = "src";
  FileSystem fs(pathname);
  REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras/");
  REQUIRE(fs.append(filename) == "build/run-unittests-extras/src");
}

SCENARIO("Test FileSystem prepend/append: #2", "[FileSystemInterface]") {
  Pathname pathname = "/build/run-unittests-extras/";
  Filename filename = "/src/";
  FileSystem fs(pathname);
  REQUIRE(fs.prepend(filename) == "/src/build/run-unittests-extras/");
  REQUIRE(fs.append(filename) == "/build/run-unittests-extras/src/");
}

SCENARIO("Test FileSystem prepend/append: #3", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras";
  Filename filename = "src";
  FileSystem fs(pathname);
  REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras");
  REQUIRE(fs.append(filename) == "build/run-unittests-extras/src");
}

SCENARIO("Test FileSystem prepend/append: #4", "[FileSystemInterface]") {
  Pathname pathname = "/build/run-unittests-extras";
  Filename filename = "/src";
  FileSystem fs(pathname);
  REQUIRE(fs.prepend(filename) == "/src/build/run-unittests-extras");
  REQUIRE(fs.append(filename) == "/build/run-unittests-extras/src");
}

SCENARIO("Test FileSystem prepend/append: #5", "[FileSystemInterface]") {
  Pathname pathname = "build/run-unittests-extras/";
  Filename filename = "src/";
  FileSystem fs(pathname);
  REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras/");
  REQUIRE(fs.append(filename) == "build/run-unittests-extras/src/");
}
