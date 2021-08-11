
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

SCENARIO("Mock ExceptionInterface: what", "[exceptions_mock]") {
  auto correct_answer = "some error message";
  Mock<ExceptionInterface> mock;
  When(Method(mock, what)).Return(correct_answer);

  ExceptionInterface &i = mock.get();
  REQUIRE(i.what() == correct_answer);
  Verify(Method(mock, what));
}

SCENARIO("Mock ExceptionInterface: getfile", "[exceptions_mock]") {
  auto correct_answer = __FILE__;
  Mock<ExceptionInterface> mock;
  When(Method(mock, getfile)).Return(correct_answer);

  ExceptionInterface &i = mock.get();
  REQUIRE(i.getfile() == correct_answer);
  Verify(Method(mock, getfile));
}

SCENARIO("Mock ExceptionInterface: getfunc", "[exceptions_mock]") {
  auto correct_answer = __func__;
  Mock<ExceptionInterface> mock;
  When(Method(mock, getfunc)).Return(correct_answer);

  ExceptionInterface &i = mock.get();
  REQUIRE(i.getfunc() == correct_answer);
  Verify(Method(mock, getfunc));
}

SCENARIO("Mock ExceptionInterface: getline", "[exceptions_mock]") {
  auto correct_answer = __LINE__;
  Mock<ExceptionInterface> mock;
  When(Method(mock, getline)).Return(correct_answer);

  ExceptionInterface &i = mock.get();
  REQUIRE(i.getline() == correct_answer);
  Verify(Method(mock, getline));
}
