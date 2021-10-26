
#include <iostream>

#include "extras/devices/AverageTemp.hpp"
#include "vendor/catch.hpp"

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

SCENARIO("Test AverageTempLast10Optimized: methods", "[AverageTempInterface]") {
  const float correct_answer = 50;
  AverageTempLast10Optimized averageTempOptimized;
  averageTempOptimized.addTemperature(correct_answer);

  REQUIRE(averageTempOptimized.calculateTemperature() == correct_answer);
  REQUIRE(averageTempOptimized.lastCalculatedTemperature() == correct_answer);
}

SCENARIO("Test AverageTempLast10Optimized: 1000 adds",
         "[AverageTempInterface]") {
  const float correct_answer = 50;
  AverageTempLast10Optimized averageTempOptimized;

  for (int i = 0; i < 1000; i++)
    averageTempOptimized.addTemperature(correct_answer);

  REQUIRE(averageTempOptimized.calculateTemperature() == correct_answer);
  REQUIRE(averageTempOptimized.lastCalculatedTemperature() == correct_answer);
}
