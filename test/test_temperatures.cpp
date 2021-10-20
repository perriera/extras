
#include <iostream>

#include "catch.hpp"
#include "extras/devices/AverageTemp.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;

SCENARIO("Test AverageTemp: array/size", "[AverageTempInterface]") {
  const float correct_answer = 50;
  AverageTemp averageTemp;
  averageTemp.addTemperature(correct_answer);

  REQUIRE(averageTemp.calculateTemperature() == correct_answer);
  REQUIRE(averageTemp.lastCalculatedTemperature() == correct_answer);
}