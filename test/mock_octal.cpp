
#include <iostream>

#include "extras/octal_support.hpp"
#include "vendor/catch.hpp"
#include "vendor/fakeit.hpp"

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
SCENARIO("Mock OctalInterface: toOctal", "[octal_support]") {
  auto correct_answer = 0;
  Mock<OctalInterface> mock;
  When(Method(mock, toOctal)).Return(correct_answer);

  OctalInterface &i = mock.get();
  REQUIRE(i.toOctal() == correct_answer);
  Verify(Method(mock, toOctal));
}

SCENARIO("Mock OctalInterface: fromOctal", "[octal_support]") {
  Mock<OctalInterface> mock;
  When(Method(mock, fromOctal)).Return();

  OctalInterface &i = mock.get();
  auto param = 0;
  i.fromOctal(param);
  Verify(Method(mock, fromOctal));
}

SCENARIO("Mock OctalInterface", "[octal_support]") {
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
  Mock<OctalInterface> mock;
  When(Method(mock, toOctal)).AlwaysDo([&_col, &_row]() {
    int octCol = _col - 'a';
    int octRow = _row - '1';
    int value = octCol * 10 + octRow;
    return value;
  });
  When(Method(mock, fromOctal)).AlwaysDo([&_col, &_row](int &octal) {
    int upper = octal / 10;
    int lower = octal % 10;
    _col = upper + 'a';
    _row = lower + '1';
  });
  OctalInterface &i = mock.get();

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
  Verify(Method(mock, fromOctal));
  Verify(Method(mock, toOctal));
}
