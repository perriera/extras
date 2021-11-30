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

#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/language/exceptions.hpp"

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
 * When it comes to testing, (or mocking) interfaces all
 * that is required are that the methods identified in the
 * interface are returning the information they were
 * designed to return, (or make changes to the system
 * in a way that is meaningful to the end user).
 *
 */

SCENARIO("Mock CustomExceptionInterface: what", "[exceptions_mock]") {
  auto correct_answer = "some error message";
  Mock<CustomExceptionInterface> mock;
  When(Method(mock, what)).Return(correct_answer);

  CustomExceptionInterface &i = mock.get();
  REQUIRE(i.what() == correct_answer);
  Verify(Method(mock, what));
}

SCENARIO("Mock CustomExceptionInterface: getfile", "[exceptions_mock]") {
  auto correct_answer = __FILE__;
  Mock<CustomExceptionInterface> mock;
  When(Method(mock, getfile)).Return(correct_answer);

  CustomExceptionInterface &i = mock.get();
  REQUIRE(i.getfile() == correct_answer);
  Verify(Method(mock, getfile));
}

SCENARIO("Mock CustomExceptionInterface: getfunc", "[exceptions_mock]") {
  auto correct_answer = __func__;
  Mock<CustomExceptionInterface> mock;
  When(Method(mock, getfunc)).Return(correct_answer);

  CustomExceptionInterface &i = mock.get();
  REQUIRE(i.getfunc() == correct_answer);
  Verify(Method(mock, getfunc));
}

SCENARIO("Mock CustomExceptionInterface: getline", "[exceptions_mock]") {
  auto correct_answer = __LINE__;
  Mock<CustomExceptionInterface> mock;
  When(Method(mock, getline)).Return(correct_answer);

  CustomExceptionInterface &i = mock.get();
  REQUIRE(i.getline() == correct_answer);
  Verify(Method(mock, getline));
}
