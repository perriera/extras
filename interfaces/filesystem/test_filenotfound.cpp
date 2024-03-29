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

// #include <cstdint>
// #include <extras/exceptions.hpp>
// #include <fstream>

// #include "../../test/vendor/catch.hpp"

// using namespace extras;

// SCENARIO("Verify FileNotFoundException: true", "[FileNotFoundException]") {
//   FileNotFoundException::assertion("build/run-unittests-extras", __INFO__);
// }

// SCENARIO("Verify FileNotFoundException: false", "[FileNotFoundException]") {
//   REQUIRE_THROWS_AS(FileNotFoundException::assertion("build/abc.exe",
//   __INFO__),
//                     FileNotFoundException);
// }

// SCENARIO("Verify PathNotFoundException: true", "[FileNotFoundException]") {
//   PathNotFoundException::assertion("build/", __INFO__);
// }

// // SCENARIO("Verify PathNotFoundException: false", "[FileNotFoundException]")
// {
// //   REQUIRE_THROWS_AS(PathNotFoundException::assertion("build/abc.exe",
// //   __INFO__),
// //                     PathNotFoundException);
// //   REQUIRE_THROWS_AS(
// //       PathNotFoundException::assertion("build/run-unittests-extras",
// //       __INFO__), NotADirectoryException);
// //   REQUIRE_THROWS_AS(PathNotFoundException::assertion("buildx/", __INFO__),
// //                     PathNotFoundException);
// // }
