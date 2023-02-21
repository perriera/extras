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

#include "../../vendor/catch.hpp"

using namespace std;
using namespace extras;

/**
 * @brief file::Interface NotFoundException
 *
 */
SCENARIO("mold file::Interface NotFoundException", "[PE-40]") {
  REQUIRE_THROWS_AS(file::NotFoundException::assertion("/usr/abc", __INFO__),
                    file::NotFoundException);
}

/**
 * @brief file::Interface NotCopiedException
 *
 */
SCENARIO("mold file::Interface NotCopiedException", "[PE-40]") {
  REQUIRE_THROWS_AS(
      file::NotCopiedException::assertion(file::File("/usr/abc"), __INFO__),
      file::NotCopiedException);
}

/**
 * @brief file::Interface InvalidNameException
 *
 */
SCENARIO("mold file::Interface InvalidNameException", "[PE-40]") {
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("", __INFO__),
                    file::InvalidNameException);
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("?", __INFO__),
                    file::InvalidNameException);
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("*", __INFO__),
                    file::InvalidNameException);
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("\\", __INFO__),
                    file::InvalidNameException);
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("//", __INFO__),
                    file::InvalidNameException);
  REQUIRE_THROWS_AS(file::InvalidNameException::assertion("/", __INFO__),
                    file::InvalidNameException);
}

/**
 * @brief file::Interface ExistsException
 *
 */
SCENARIO("mold file::Interface ExistsException", "[PE-40]") {
  REQUIRE_THROWS_AS(file::ExistsException::assertion(".", __INFO__),
                    file::ExistsException);
  REQUIRE_THROWS_AS(file::ExistsException::assertion("..", __INFO__),
                    file::ExistsException);
  file::ExistsException::assertion("/>?/", __INFO__);
}

/**
 * @brief file::Interface FolderExistsException
 *
 */
SCENARIO("mold file::Interface FolderExistsException", "[PE-40]") {
  /**
   * @brief throw an exception if no filename is specified
   *
   */
  REQUIRE_THROWS_AS(
      file::FolderExistsException::assertion(file::File(""), __INFO__),
      file::FolderNotSpecifiedException);

  /**
   * @brief throw an exception if a wildcard is specified
   *
   */
  REQUIRE_THROWS_AS(file::FolderExistsException::assertion(
                        file::File("/usr/abc/*"), __INFO__),
                    file::NotAFolderNameException);

  /**
   * @brief throw an exception if the folder does not exist
   *
   */
  REQUIRE_THROWS_AS(
      file::FolderExistsException::assertion(file::File("/usr/abc"), __INFO__),
      file::NotFoundException);

  /**
   * @brief throw an exception if the folder is not a folder
   *
   */
  REQUIRE_THROWS_AS(file::FolderExistsException::assertion(
                        file::File("/etc/hosts"), __INFO__),
                    file::NotAFolderException);

  /**
   * @brief do NOT throw an exception if the folder exists
   *
   */
  file::FolderExistsException::assertion(file::File("/usr"), __INFO__);
  file::FolderExistsException::assertion("/usr", __INFO__);

  /**
   * @brief do throw an exception if the folder exists
   *
   */
  // std::string relative_dir = "test/data/project";
  // file::FolderNotFoundException::assertion(relative_dir, __INFO__);
  // system("mkdir -p test/data/project");
  // REQUIRE_THROWS_AS(file::FolderNotFoundException::assertion(
  //                       file::File(relative_dir), __INFO__),
  //                   file::NotAFolderException);
}
