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

#include <extras/docking/DockIt.hpp>
#include <extras/file/clazz.hpp>
#include <fstream>
#include <iostream>

#include "../vendor/catch.hpp"

using namespace std;
using namespace extras;

/**
 * @brief file::Interface
 *
 */
SCENARIO("test assertions for file::Interface: found", "[PE-40]") {
  /**
   * @brief FileNotFoundException
   *
   */
  REQUIRE_THROWS_AS(
      file::FileNotFoundException::assertion("/usr/abc", __INFO__),
      file::FileNotFoundException);
  /**
   * @brief FileNotCopiedException
   *
   */
  REQUIRE_THROWS_AS(
      file::FileNotCopiedException::assertion(file::File("/usr/abc"), __INFO__),
      file::FileNotCopiedException);
  /**
   * @brief FilenameInvalidException
   *
   */
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("", __INFO__),
                    file::FilenameInvalidException);
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("?", __INFO__),
                    file::FilenameInvalidException);
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("*", __INFO__),
                    file::FilenameInvalidException);
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("\\", __INFO__),
                    file::FilenameInvalidException);
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("//", __INFO__),
                    file::FilenameInvalidException);
  REQUIRE_THROWS_AS(file::FilenameInvalidException::assertion("/", __INFO__),
                    file::FilenameInvalidException);
  /**
   * @brief FileExistsException
   *
   */
  REQUIRE_THROWS_AS(file::FileExistsException::assertion(".", __INFO__),
                    file::FileExistsException);
  REQUIRE_THROWS_AS(file::FileExistsException::assertion("..", __INFO__),
                    file::FileExistsException);
  file::FileExistsException::assertion("/>?/", __INFO__);
  // /**
  //  * @brief FolderExistsException
  //  *
  //  */
  // REQUIRE_THROWS_AS(
  //     file::FolderExistsException::assertion(file::File("/usr"), __INFO__),
  //     file::FolderExistsException);
  // file::FolderExistsException::assertion(file::File("/usrX"), __INFO__);
  // /**
  //  * @brief FolderExistsException
  //  *
  //  */
  // REQUIRE_THROWS_AS(
  //     file::FolderExistsException::assertion(file::File("/usr"), __INFO__),
  //     file::FolderExistsException);
}
