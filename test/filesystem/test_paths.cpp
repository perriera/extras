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
 * The above copyright notice and  this permission  notice shall be
 * included in all copies or  substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESSED  OR   IMPLIED,  INCLUDING   BUT  NOT  LIMITED  TO  THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE
 * AND NON-INFRINGEMENT.  IN  NO  EVENT  SHALL EXPARX  INCORPORATED
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM, OUT  OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Except  as  contained  in this  notice, the  name of  the EXPARX
 * INCORPORATED shall not  be used in  advertising or  otherwise to
 * promote the sale, use or other dealings in this Software without
 * prior written authorization from EXPARX INCORPORATED.
 *
 * exparx.com and www.exparx.com  are domain names  registered with
 * EXPARX INCORPORATED, (other GPL-themed licenses are included).
 *
 */

#include <cstdint>
#include <extras/filesystem/paths.hpp>
#include <extras/strings.hpp>
#include <fstream>

#include "../vendor/catch.hpp"

using namespace extras;

SCENARIO("Verify PathsInterface default", "[paths_support]") {
  std::string value = Paths::instance().actualPath("~/Downloads");
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
}

SCENARIO("Verify PathsInterface operator~()", "[paths_support]") {
  Paths path("~/Downloads");
  std::string value = ~path;
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
  // std::cout << value << std::endl;
}

SCENARIO("Verify PathsInterface filename", "[paths_support]") {
  std::string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  Paths path(filename);
  Path actual_path = ~path;
  // std::cout << actual_path << std::endl;
  std::ifstream myfile(actual_path);
  REQUIRE(myfile.good());
  std::string value = ~path;
  REQUIRE(value != "~/Downloads");
  REQUIRE(extras::contains(value, "/home/"));
  REQUIRE(!extras::contains(value, "~"));
  // std::cout << value << std::endl;
}
