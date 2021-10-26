
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/devices/AverageTemp.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

SCENARIO("Mock AverageTempInterface: array/size", "[AverageTempInterface]") {
  const float correct_answer = 50;
  Mock<AverageTempInterface> mock;
  When(Method(mock, addTemperature)).Return();
  When(Method(mock, calculateTemperature)).Return(correct_answer);
  When(Method(mock, lastCalculatedTemperature)).Return(correct_answer);

  AverageTempInterface& i = mock.get();
  i.addTemperature(correct_answer);
  REQUIRE(i.calculateTemperature() == correct_answer);
  REQUIRE(i.lastCalculatedTemperature() == correct_answer);
  Verify(Method(mock, addTemperature));
  Verify(Method(mock, calculateTemperature));
  Verify(Method(mock, lastCalculatedTemperature));
}