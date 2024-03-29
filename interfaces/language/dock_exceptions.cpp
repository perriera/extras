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

// #include <extras/exceptions.hpp>
// #include <iostream>

// #include "../../test/vendor/catch.hpp"
// #include "../../test/vendor/fakeit.hpp"
// #include <extras/docking/DockIt.hpp>

// //
// // https://github.com/eranpeer/FakeIt/wiki/Quickstart
// //

// using namespace extras;
// using namespace fakeit;

// /**
//  * @brief Mock ExceptionInterface
//  *
//  * We need to provide additional information for loggers
//  * as well as to streamline the custom exception process
//  * for supported applications.
//  *
//  * When it comes to testing, (or mocking) interfaces all
//  * that is required are that the methods identified in the
//  * interface are returning the information they were
//  * designed to return, (or make changes to the system
//  * in a way that is meaningful to the end user).
//  *
//  */

// SCENARIO("Dock ExtrasExceptionInterface: what", "[exceptions_mock]") {
//   auto correct_answer = "some error message";
//   Mold<ExtrasExceptionInterface> dock;
//   When(Method(dock, what)).Return(correct_answer);

//   ExtrasExceptionInterface &i = dock.get();
//   REQUIRE(i.what() == correct_answer);
//   Verify(Method(dock, what));
// }

// SCENARIO("Dock ExtrasExceptionInterface: getfile", "[exceptions_mock]") {
//   auto correct_answer = __FILE__;
//   Mold<ExtrasExceptionInterface> dock;
//   When(Method(dock, getfile)).Return(correct_answer);

//   ExtrasExceptionInterface &i = dock.get();
//   REQUIRE(i.getfile() == correct_answer);
//   Verify(Method(dock, getfile));
// }

// SCENARIO("Dock ExtrasExceptionInterface: getfunc", "[exceptions_mock]") {
//   auto correct_answer = __func__;
//   Mold<ExtrasExceptionInterface> dock;
//   When(Method(dock, getfunc)).Return(correct_answer);

//   ExtrasExceptionInterface &i = dock.get();
//   REQUIRE(i.getfunc() == correct_answer);
//   Verify(Method(dock, getfunc));
// }

// SCENARIO("Dock ExtrasExceptionInterface: getline", "[exceptions_mock]") {
//   auto correct_answer = __LINE__;
//   Mold<ExtrasExceptionInterface> dock;
//   When(Method(dock, getline)).Return(correct_answer);

//   ExtrasExceptionInterface &i = dock.get();
//   REQUIRE(i.getline() == correct_answer);
//   Verify(Method(dock, getline));
// }

// SCENARIO("Dock ExtrasExceptionInterface: streams", "[exceptions_mock]") {
//   try {
//     NotADirectoryException::assertion("build/run-unittests-extras",
//     __INFO__); FAIL("exception not thrown");
//   } catch (extras::exception &ex) {
//     std::cout << ex << std::endl;
//     SUCCEED("exception caught");
//   } catch (std::exception &ex) {
//     std::cout << ex.what() << std::endl;
//     FAIL("wrong exception caught");
//   }
//   try {
//     NotAFileException::assertion("build/", __INFO__);
//     FAIL("exception not thrown");
//   } catch (extras::exception &ex) {
//     std::cout << ex << std::endl;
//     SUCCEED("exception caught");
//   } catch (std::exception &ex) {
//     std::cout << ex.what() << std::endl;
//     FAIL("wrong exception caught");
//   }
// }
