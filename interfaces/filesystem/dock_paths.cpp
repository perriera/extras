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
#include "../../test/vendor/fakeit.hpp"
#include "extras/filesystem/paths.hpp"

#include <extras/docking/DockIt.hpp>
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 *
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Dock PathsInterface: toOctal", "[paths_support]")
{
   auto correct_answer = "/home/perry/Downloads";
   Mold<PathsInterface> dock;
   When(Method(dock, actualPath)).AlwaysDo([&correct_answer](const Path&) {
      {
         return correct_answer;
      }
   });

   PathsInterface& i = dock.get();
   REQUIRE(i.actualPath("~/Downloads") == correct_answer);
   Verify(Method(dock, actualPath));
}
