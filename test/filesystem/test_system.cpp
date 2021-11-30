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
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE  EXPARX  INCORPORATED
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
#include <extras/filesystem/system.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

#include "../vendor/catch.hpp"

using namespace extras;

SCENARIO("Test SystemException", "[SystemException]") {
  std::string good_cmd = "ls -la";
  std::string bad_cmd = "lsxyz@ -la";
  SystemException::assertion(good_cmd, __INFO__);
  REQUIRE_THROWS_AS(SystemException::assertion(bad_cmd, __INFO__),
                    SystemException);
}

SCENARIO("Test ScriptException", "[SystemException]") {
  std::string good_script = "./good_script.sh";
  {
    std::ofstream out(good_script);
    out << "ls -la" << std::endl;
  }
  std::string bad_script = "./bad_script.sh";
  {
    std::ofstream out(bad_script);
    out << "lsxyz@ -la" << std::endl;
  }
  ScriptException::assertion(good_script, __INFO__);
  REQUIRE_THROWS_AS(ScriptException::assertion(bad_script, __INFO__),
                    ScriptException);
}