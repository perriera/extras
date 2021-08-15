#include <iostream>

#include "catch.hpp"
#include "extras/dotenv.hpp"

using namespace extras;

/**
 * @brief DotENV Unit Test
 *
 */
SCENARIO("Test DotENV", "[test_dotenv]") {
  /**
   * @brief No where near as exciting, (or interestig
   * as mock tests, the unit test gives us a chance
   * to prove that the expected behavior has found
   * its way into the implementation)
   *
   */
  DotENV dotENV;
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  dotENV.put(key, value);
  REQUIRE(dotENV.contains(key));
  REQUIRE(dotENV.value(key) == value);
}

SCENARIO("Test DotENV instance()", "[test_dotenv]") {
  /**
   * @brief In the case of a singleton being required
   * we make use of the interface instead of the class;
   * (Mind you, this really clutters the test case as
   * only one static instance can be tested, so we limit
   * the singleton test to one single test case).
   */
  DotENVInterface& instance = DotENV::instance();
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  instance.put(key, value);
  REQUIRE(instance.contains(key));
  REQUIRE(instance.value(key) == value);
}
