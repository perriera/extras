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

// #include <cstdint>
// #include <extras/exceptions.hpp>
// #include <extras/filesystem/filesystem.hpp>
// #include <extras/strings.hpp>
// #include <fstream>

// #include "../../vendor/catch.hpp"

// using namespace extras;

// /**
//  * @brief extras:::FileSystem test cases
//  *
//  */

// SCENARIO("Test FileSystem case #1", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/";
//   Filename filename = "run-unittests-extras";
//   Extension extension = "exe";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #2", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/";
//   Filename filename = "run-unittests-extras";
//   Extension extension = "";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #3", "[FileSystemInterface]") {
//   Pathname pathname = "";
//   Filename filename = "";
//   Extension extension = "";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #4", "[FileSystemInterface]") {
//   Pathname pathname = " ";
//   Filename filename = "";
//   Extension extension = "";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #5", "[FileSystemInterface]") {
//   Pathname pathname = " ";
//   Filename filename = "run-unittests-extras";
//   Extension extension = "";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #6", "[FileSystemInterface]") {
//   Pathname pathname = "";
//   Filename filename = "";
//   Extension extension = "exe";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem case #7", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/";
//   Filename filename = "";
//   Extension extension = "";
//   Filename realFilename = filename + (extension != "" ? "." : "") +
//   extension; Path path = pathname + realFilename; FileSystem fs(path);
//   REQUIRE(fs.path() == path);
//   REQUIRE(fs.pathname() == pathname);
//   REQUIRE(fs.justthefilename() == filename);
//   REQUIRE(fs.justtheextension() == extension);
//   REQUIRE(fs.filename() == realFilename);
// }

// SCENARIO("Test FileSystem prepend/append: #1", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/";
//   Filename filename = "src";
//   FileSystem fs(pathname);
//   REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras/");
//   REQUIRE(fs.append(filename) == "build/run-unittests-extras/src");
// }

// SCENARIO("Test FileSystem prepend/append: #2", "[FileSystemInterface]") {
//   Pathname pathname = "/build/run-unittests-extras/";
//   Filename filename = "/src/";
//   FileSystem fs(pathname);
//   REQUIRE(fs.prepend(filename) == "/src/build/run-unittests-extras/");
//   REQUIRE(fs.append(filename) == "/build/run-unittests-extras/src/");
// }

// SCENARIO("Test FileSystem prepend/append: #3", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras";
//   Filename filename = "src";
//   FileSystem fs(pathname);
//   REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras");
//   REQUIRE(fs.append(filename) == "build/run-unittests-extras/src");
// }

// SCENARIO("Test FileSystem prepend/append: #4", "[FileSystemInterface]") {
//   Pathname pathname = "/build/run-unittests-extras";
//   Filename filename = "/src";
//   FileSystem fs(pathname);
//   REQUIRE(fs.prepend(filename) == "/src/build/run-unittests-extras");
//   REQUIRE(fs.append(filename) == "/build/run-unittests-extras/src");
// }

// SCENARIO("Test FileSystem prepend/append: #5", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/";
//   Filename filename = "src/";
//   FileSystem fs(pathname);
//   REQUIRE(fs.prepend(filename) == "src/build/run-unittests-extras/");
//   REQUIRE(fs.append(filename) == "build/run-unittests-extras/src/");
// }

// SCENARIO("Test FileSystem prepend/append: #6", "[FileSystemInterface]") {
//   Pathname pathname = "build/run-unittests-extras/runtasks.exe";
//   Filename filename = "src/";
//   FileSystem fs1(filename);
//   Path x = FileSystem(pathname).append(fs1.path());
//   REQUIRE(x == "build/run-unittests-extras/runtasks.exe/src/");
//   // REQUIRE(fs2.append(filename) == "build/run-unittests-extras/src/");
// }

// SCENARIO("Test FileSystem prepend/append: test this",
// "[FileSystemInterface]") {
//   // "vendor 137.184.218.130 9002 data/src.zip data/exparx.webflow.zip"
//   // "vendor 137.184.218.130 9002 /tmp/extras_rsi_PTduD4/src
//   // /tmp/extras_rsi_PTduD4/exparx.webflow.zip "

//   Pathname requestType =
//       "vendor 137.184.218.130 9002 data/src.zip data/exparx.webflow.zip";

//   Filename correct_answer =
//       "vendor 137.184.218.130 9002 /tmp/extras_rsi_PTduD4/src.zip "
//       "/tmp/extras_rsi_PTduD4/exparx.webflow.zip ";

//   auto parts = extras::str::split(requestType, ' ');
//   std::string sessionType;
//   std::string directory = "/tmp/extras_rsi_PTduD4/";
//   for (auto i = 0; i < 3; i++) sessionType += parts[i] + " ";
//   for (size_t i = 3; i < parts.size(); i++) {
//     auto fn1 = extras::FileSystem(parts[i]).filename();
//     auto fn2 = extras::FileSystem(directory).append(fn1);
//     sessionType += fn2 + " ";
//   }
//   REQUIRE(sessionType == correct_answer);
// }
