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
#include "extras/strings.hpp"

#include <extras/exceptions.hpp>
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock ExceptionInterface
 *
 * We need to provide additional information for loggers
 * as well as to streamline the custom exception process
 * for supported applications.
 *
 */
using namespace std;
using namespace extras;

SCENARIO("Test ExceptionInterface: whereiam", "[exceptions_testcases]")
{
   auto test1 = __INFO__;
   auto test2 = __INFO__;
   auto line = __LINE__;
   REQUIRE(test1._file == test2._file);
   REQUIRE(test1._func == test2._func);
   REQUIRE(test1._line == test2._line - 1);
   REQUIRE(test1._line == line - 2);
}

SCENARIO("Test ExceptionInterface: GroupCustomException (args)",
         "[exceptions_testcases]")
{
   auto test = "this is a group level (general) exception";
   GroupCustomException _exception(test, __INFO__);
   REQUIRE(contains(_exception.what(), test));
   REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
   REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____2"));
   auto x = _exception.getline();
   REQUIRE(x == 59);
}

SCENARIO("Test ExceptionInterface: SpecificCustomException (no args)",
         "[exceptions_testcases]")
{
   auto test = "Specific custom exception description";
   SpecificCustomException _exception(__INFO__);
   REQUIRE(contains(_exception.what(), test));
   REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
   REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____4"));
   REQUIRE(_exception.getline() == 71);
}

SCENARIO("Test ExceptionInterface: SpecificCustomException (args)",
         "[exceptions_testcases]")
{
   auto test = "8080";
   SpecificCustomException _exception(test, __INFO__);
   REQUIRE(contains(_exception.what(), "SpecificCustomException"));
   REQUIRE(contains(_exception.what(), "Port: 8080 wasn't found"));
   REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
   REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____6"));
   REQUIRE(_exception.getline() == 82);
}

SCENARIO("Test SpecificCustomException: assertion", "[exceptions_testcases]")
{
   REQUIRE_THROWS_AS(SpecificCustomException::assertion("63", __INFO__),
                     SpecificCustomException);
   REQUIRE_THROWS_AS(SpecificCustomException::assertion(2, 3, __INFO__),
                     SpecificCustomException);
   REQUIRE_NOTHROW(SpecificCustomException::assertion("8080", __INFO__));
   REQUIRE_NOTHROW(SpecificCustomException::assertion(3, 2, __INFO__));
}

/**
 * @brief This is example we show testing for exceptions and how the
 * use of if() statements, (for the purposes of exception testing)
 * adds complexity to the source code.
 *
 */
SCENARIO(
  "Test SpecificCustomException: demonstration (without assertion() methods)",
  "[exceptions_testcases]")
{
   try {
      std::string port = "8080";
      if (port != "8080") {
         throw SpecificCustomException(port, __INFO__);
      }
      int a = 3;
      int b = 7;
      if (a < b) {
         throw SpecificCustomException("a>b", __INFO__);
      }
   } catch (SpecificCustomException& ex) {
      SUCCEED("SpecificCustomException thrown");
   } catch (GroupCustomException& ex) {
      FAIL("GroupCustomException thrown");
   } catch (std::exception& ex) {
      FAIL("std::exception thrown");
   } catch (...) {
      FAIL("exc");
   }
}

/**
 * @brief This is example we show testing for exceptions and how the
 * use of if() statements, (for the purposes of exception testing)
 * greatly removes complexity from the source code.
 *
 */

SCENARIO(
  "Test SpecificCustomException: demonstration (with assertion() methods)",
  "[exceptions_testcases]")
{
   try {
      std::string port = "8080";
      SpecificCustomException::assertion(port, __INFO__);
      int a = 3;
      int b = 7;
      SpecificCustomException::assertion(a, b, __INFO__);
      FAIL("SpecificCustomException not thrown");
   } catch (SpecificCustomException& ex) {
      SUCCEED("SpecificCustomException thrown");
   } catch (GroupCustomException& ex) {
      FAIL("GroupCustomException thrown, (instead)");
   } catch (std::exception& ex) {
      FAIL("std::exception thrown, (instead)");
   } catch (...) {
      FAIL("... thrown, (instead)");
   }
}
