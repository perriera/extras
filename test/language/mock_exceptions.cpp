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
 * (See LICENSE.md for complete details)
 *
 */

#include <extras/exceptions.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

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

SCENARIO("Mock ExtrasExceptionInterface: what", "[exceptions_mock]") {
  auto correct_answer = "some error message";
  Mock<ExtrasExceptionInterface> mock;
  When(Method(mock, what)).Return(correct_answer);

  ExtrasExceptionInterface &i = mock.get();
  REQUIRE(i.what() == correct_answer);
  Verify(Method(mock, what));
}

SCENARIO("Mock ExtrasExceptionInterface: getfile", "[exceptions_mock]") {
  auto correct_answer = __FILE__;
  Mock<ExtrasExceptionInterface> mock;
  When(Method(mock, getfile)).Return(correct_answer);

  ExtrasExceptionInterface &i = mock.get();
  REQUIRE(i.getfile() == correct_answer);
  Verify(Method(mock, getfile));
}

SCENARIO("Mock ExtrasExceptionInterface: getfunc", "[exceptions_mock]") {
  auto correct_answer = __func__;
  Mock<ExtrasExceptionInterface> mock;
  When(Method(mock, getfunc)).Return(correct_answer);

  ExtrasExceptionInterface &i = mock.get();
  REQUIRE(i.getfunc() == correct_answer);
  Verify(Method(mock, getfunc));
}

SCENARIO("Mock ExtrasExceptionInterface: getline", "[exceptions_mock]") {
  auto correct_answer = __LINE__;
  Mock<ExtrasExceptionInterface> mock;
  When(Method(mock, getline)).Return(correct_answer);

  ExtrasExceptionInterface &i = mock.get();
  REQUIRE(i.getline() == correct_answer);
  Verify(Method(mock, getline));
}

SCENARIO("Mock ExtrasExceptionInterface: streams", "[exceptions_mock]") {
  try {
    NotADirectoryException::assertion("build/run-unittests-extras", __INFO__);
  } catch (ExtrasExceptionInterface &ex) {
    std::cout << ex << std::endl;
  }
}
