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
#include <extras/strings.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"

using namespace extras;

/**
 * @brief extras::str::replace_first() test cases
 *
 */

SCENARIO("Test Split (string with string)", "[string_support]") {
  std::string _sqlplus_full_query =
      "SELECT owner, table_name, tablespace_name, cluster_name, iot_name FROM "
      "all_tables;";

  std::string s = str::to_lower(_sqlplus_full_query);
  auto filters = str::split(s, " from ");
  filters = str::split(filters[0], "select ");
  filters = str::split(filters[1], ", ");

  REQUIRE(filters[0] == "owner");
  REQUIRE(filters[1] == "table_name");
  REQUIRE(filters[2] == "tablespace_name");
  REQUIRE(filters[3] == "cluster_name");
  REQUIRE(filters[4] == "iot_name");
}

SCENARIO("Test Split (string with car)", "[string_support]") {
  std::string _sqlplus_full_query =
      "SELECT owner, table_name, tablespace_name, cluster_name, iot_name FROM "
      "all_tables;";

  std::string s = str::to_lower(_sqlplus_full_query);
  s = str::replace_all(s, ",", "");
  s = str::replace_all(s, ";", "");
  auto filters = str::split(s, ' ');

  REQUIRE(filters[0] == "select");
  REQUIRE(filters[1] == "owner");
  REQUIRE(filters[2] == "table_name");
  REQUIRE(filters[3] == "tablespace_name");
  REQUIRE(filters[4] == "cluster_name");
  REQUIRE(filters[5] == "iot_name");
  REQUIRE(filters[6] == "from");
  REQUIRE(filters[7] == "all_tables");
}
