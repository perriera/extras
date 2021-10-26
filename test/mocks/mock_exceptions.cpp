
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/exceptions.hpp"

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
