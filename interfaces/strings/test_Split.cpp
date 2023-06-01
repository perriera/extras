/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "../../test/vendor/catch.hpp"

#include <extras/exceptions.hpp>
#include <extras/strings.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <sstream>

using namespace extras;

/**
 * @brief extras::str::replace_first() test cases
 *
 */

SCENARIO("Test Split (string with string)", "[string_support]")
{
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

SCENARIO("Test Split (string with car)", "[string_support]")
{
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
