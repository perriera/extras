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

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

#include <extras/docking/DockIt.hpp>
#include <extras/status/StatusLine.hpp>
#include <iostream>
#include <sstream>

using namespace extras;
using namespace fakeit;

//
// printf("[+]File data downloaded successfully.\n");
//

SCENARIO("Dock StatusLineInterface", "[StatusLineInterface]")
{
   extras::StatusLineMsg in1 = "File data downloaded successfully";
   extras::StatusLineMsg in2 = "Error in socket";
   extras::StatusLineMsg good = "[+] File data downloaded successfully.\n";
   extras::StatusLineMsg bad = "[-] Error in socket.\n";
   Mold<extras::StatusLineInterface> dock;
   When(Method(dock, pass)).AlwaysDo([](const extras::StatusLineMsg& msg) {
      std::stringstream ss;
      ss << "[+] " << msg << "." << std::endl;
      return ss.str();
   });
   When(Method(dock, fail)).AlwaysDo([](const extras::StatusLineMsg& msg) {
      std::stringstream ss;
      ss << "[-] " << msg << "." << std::endl;
      return ss.str();
   });

   extras::StatusLineInterface& i = dock.get();
   REQUIRE(i.pass(in1) == good);
   REQUIRE(i.fail(in2) == bad);
   Verify(Method(dock, pass));
   Verify(Method(dock, fail));
}
