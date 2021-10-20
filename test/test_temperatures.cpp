
#include <iostream>

#include "catch.hpp"
#include "extras/devices/AverageTemp.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;

SCENARIO("Test AverageTemp: methods", "[AverageTempInterface]") {
  const float correct_answer = 50;
  AverageTemp averageTemp;
  averageTemp.addTemperature(correct_answer);

  REQUIRE(averageTemp.calculateTemperature() == correct_answer);
  REQUIRE(averageTemp.lastCalculatedTemperature() == correct_answer);
}

SCENARIO("Test AverageTempLast10: methods", "[AverageTempInterface]") {
  const float correct_answer = 50;
  AverageTempLast10 averageTempLast10;
  averageTempLast10.addTemperature(correct_answer);

  REQUIRE(averageTempLast10.calculateTemperature() == correct_answer);
  REQUIRE(averageTempLast10.lastCalculatedTemperature() == correct_answer);
}