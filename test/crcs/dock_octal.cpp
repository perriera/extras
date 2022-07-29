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

#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/crcs/octal_support.hpp"
#include "extras/docking/DockIt.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 * Up till now the FakeIt Mock framework has appeared to be
 * somewhat of a 'extra' option or 'extra' step in the software
 * development process. But the mocks for OctalInterface give
 * a much better  example of how the FakeIt Mock framework
 * can be used to work out minute details of any given interface
 * before and any implementation source code needs to be written.
 *
 * By working out the 'to and fro' of data passing at this level,
 * (that is, because any implementation code or unit tests) can
 * save the developer a lot of time in needless refactoring later.
 *
 * So significant is the time saved in working out the details of
 * the interface using mocks are that when the mocks are working
 * reasonably well, they can actually serve as a blueprint for both
 * the following implementation and unit test cases soon to follow.
 *
 * While the OctalInteface class is *probably* better suited inside
 * the chessmind framework, it is being made part of the extras
 * library for the purposes of demonstrating how to effectively
 * use the FakeIt Mock framework. For anyone new to interface
 * driven development, (Gof Abstract Factory Pattern), this is
 * a great example of how to build an interface, test and refine it
 * before an single line of boilerplate code is required.
 *
 */
SCENARIO("Dock OctalInterface: toOctal", "[octal_support]") {
  auto correct_answer = 0;
  Dock<OctalInterface> dock;
  When(Method(dock, toOctal)).Return(correct_answer);

  OctalInterface &i = dock.get();
  REQUIRE(i.toOctal() == correct_answer);
  Verify(Method(dock, toOctal));
}

SCENARIO("Dock OctalInterface: fromOctal", "[octal_support]") {
  Dock<OctalInterface> dock;
  When(Method(dock, fromOctal)).Return();

  OctalInterface &i = dock.get();
  auto param = 0;
  i.fromOctal(param);
  Verify(Method(dock, fromOctal));
}

SCENARIO("Dock OctalInterface", "[octal_support]") {
  /**
   * @brief Simulate a class and class members here
   *
   * An octal number has a range of 0 to 7, (which is
   * ideal for chess positions for either row or col).
   *
   * In this case we will setup two char values to hold
   * the octal values for a chess piecee, row & col.
   */
  char _col = -1;
  char _row = -1;
  Dock<OctalInterface> dock;
  When(Method(dock, toOctal)).AlwaysDo([&_col, &_row]() {
    int octCol = _col - 'a';
    int octRow = _row - '1';
    int value = octCol * 10 + octRow;
    return value;
  });
  When(Method(dock, fromOctal)).AlwaysDo([&_col, &_row](int &octal) {
    int upper = octal / 10;
    int lower = octal % 10;
    _col = upper + 'a';
    _row = lower + '1';
  });
  OctalInterface &i = dock.get();

  /**
   * @brief Test a value of a1 in octal
   *
   */
  i.fromOctal(0);
  REQUIRE(_col == 'a');
  REQUIRE(_row == '1');
  REQUIRE(i.toOctal() == 0);

  /**
   * @brief Test a value of h8 in octal
   *
   */
  i.fromOctal(77);
  REQUIRE(_col == 'h');
  REQUIRE(_row == '8');
  REQUIRE(i.toOctal() == 77);

  /**
   * @brief Make sure all methods were called
   *
   */
  Verify(Method(dock, fromOctal));
  Verify(Method(dock, toOctal));
}
