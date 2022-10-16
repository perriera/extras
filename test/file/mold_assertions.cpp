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
  REQUIRE_THROWS_AS(
      file::FolderExistsException::assertion(file::File(""), __INFO__),
      file::FolderNotSpecifiedException);
  REQUIRE_THROWS_AS(file::FolderExistsException::assertion(
                        file::File("/usr/abc/*"), __INFO__),
                    file::NotAFolderNameException);
  REQUIRE_THROWS_AS(
      file::FolderExistsException::assertion(file::File("/usr/abc"), __INFO__),
      file::NotFoundException);
  REQUIRE_THROWS_AS(file::FolderExistsException::assertion(
                        file::File("/etc/hosts"), __INFO__),
                    file::NotAFolderException);
  file::FolderExistsException::assertion(file::File("/usr"), __INFO__);
}
