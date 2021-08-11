
#include <iostream>

#include "catch.hpp"
#include "extras/exceptions.hpp"
#include "fakeit.hpp"

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
