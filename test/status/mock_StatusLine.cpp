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

#include <extras/status/StatusLine.hpp>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

//
// printf("[+]File data downloaded successfully.\n");
//

SCENARIO("Mock StatusLineInterface", "[StatusLineInterface]") {
  extras::StatusLineMsg in1 = "File data downloaded successfully";
  extras::StatusLineMsg in2 = "Error in socket";
  extras::StatusLineMsg good = "[+] File data downloaded successfully.\n";
  extras::StatusLineMsg bad = "[-] Error in socket.\n";
  Mock<extras::StatusLineInterface> mock;
  When(Method(mock, pass)).AlwaysDo([](const extras::StatusLineMsg& msg) {
    std::stringstream ss;
    ss << "[+] " << msg << "." << std::endl;
    return ss.str();
  });
  When(Method(mock, fail)).AlwaysDo([](const extras::StatusLineMsg& msg) {
    std::stringstream ss;
    ss << "[-] " << msg << "." << std::endl;
    return ss.str();
  });

  extras::StatusLineInterface& i = mock.get();
  REQUIRE(i.pass(in1) == good);
  REQUIRE(i.fail(in2) == bad);
  Verify(Method(mock, pass));
  Verify(Method(mock, fail));
}
