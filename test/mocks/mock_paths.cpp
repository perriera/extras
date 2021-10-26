
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/filesystem/paths.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock PathsInterface: toOctal", "[paths_support]") {
  auto correct_answer = "/home/perry/Downloads";
  Mock<PathsInterface> mock;
  When(Method(mock, actualPath)).Return(correct_answer);

  PathsInterface &i = mock.get();
  REQUIRE(i.actualPath("~/Downloads") == correct_answer);
  Verify(Method(mock, actualPath));
}
