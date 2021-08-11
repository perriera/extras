
#include <iostream>

#include "catch.hpp"
#include "extras/exceptions.hpp"
#include "extras/strings.hpp"
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
using namespace std;
using namespace extras;

SCENARIO("Test ExceptionInterface: whereiam", "[exceptions_testcases]") {
  auto test1 = __INFO__;
  auto test2 = __INFO__;
  auto line = __LINE__;
  REQUIRE(test1._file == test2._file);
  REQUIRE(test1._func == test2._func);
  REQUIRE(test1._line == test2._line - 1);
  REQUIRE(test1._line == line - 2);
}

SCENARIO("Test ExceptionInterface: GroupCustomException (args)",
         "[exceptions_testcases]") {
  auto test = "this is a group level (general) exception";
  GroupCustomException _exception(test, __INFO__);
  REQUIRE(contains(_exception.what(), test));
  REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
  REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____2"));
  REQUIRE(_exception.getline() == 40);
}

SCENARIO("Test ExceptionInterface: SpecificCustomException (no args)",
         "[exceptions_testcases]") {
  auto test = "Specific custom exception description";
  SpecificCustomException _exception(__INFO__);
  REQUIRE(contains(_exception.what(), test));
  REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
  REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____4"));
  REQUIRE(_exception.getline() == 50);
}

SCENARIO("Test ExceptionInterface: SpecificCustomException (args)",
         "[exceptions_testcases]") {
  auto test = "8080";
  SpecificCustomException _exception(test, __INFO__);
  REQUIRE(contains(_exception.what(), "Port: 8080 wasn't found"));
  REQUIRE(ends_with(_exception.getfile(), "test_exceptions.cpp"));
  REQUIRE(contains(_exception.getfunc(), "____C_A_T_C_H____T_E_S_T____6"));
  REQUIRE(_exception.getline() == 60);
}
