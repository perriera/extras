#include <extras/dotenv.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Mock DotENVLineInterface: key", "[mock_dotenv]") {
  auto correct_answer = EnvironmentVariableKey();
  Mock<DotENVLineInterface> mock;
  When(Method(mock, key)).Return(correct_answer);

  DotENVLineInterface &i = mock.get();
  REQUIRE(i.key() == correct_answer);
  Verify(Method(mock, key));
}

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Mock DotENVLineInterface: value", "[mock_dotenv]") {
  auto correct_answer = EnvironmentVariableValue();
  Mock<DotENVLineInterface> mock;
  When(Method(mock, value)).Return(correct_answer);

  DotENVLineInterface &i = mock.get();
  REQUIRE(i.value() == correct_answer);
  Verify(Method(mock, value));
}

/**
 * @brief Mock DotENVInterface
 *
 */
SCENARIO("Mock DotENVInterface: map", "[mock_dotenv]") {
  auto correct_answer = EnvironmentVariableMap();
  Mock<DotENVInterface> mock;
  When(Method(mock, map)).Return(correct_answer);

  DotENVInterface &i = mock.get();
  REQUIRE(i.map() == correct_answer);
  Verify(Method(mock, map));
}

SCENARIO("Mock DotENVInterface: put", "[mock_dotenv]") {
  Mock<DotENVInterface> mock;
  When(Method(mock, put)).Return();

  DotENVInterface &i = mock.get();
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  DotENVLine line(key, value);
  i.put(line);
  Verify(Method(mock, put));
}

SCENARIO("Mock DotENVInterface: contains", "[mock_dotenv]") {
  /**
   * @brief Simulate a class and class members here
   *
   * An EnvironmentVariableMap mains a key/value list
   * in sorted, searchable order.
   *
   */
  EnvironmentVariableMap correct_answer = EnvironmentVariableMap();
  Mock<DotENVInterface> mock;
  When(Method(mock, put))
      .AlwaysDo([&correct_answer](const DotENVLineInterface &entry) {
        correct_answer[entry.key()] = entry.value();
      });
  When(Method(mock, map)).Return(correct_answer);
  When(Method(mock, contains)).AlwaysDo([&correct_answer](auto key) {
    return correct_answer.find(key) != correct_answer.end();
  });
  When(Method(mock, value)).AlwaysDo([&correct_answer](auto key) {
    return correct_answer[key];
  });
  DotENVInterface &i = mock.get();

  /**
   * @brief Test map
   *
   */
  REQUIRE(i.map() == correct_answer);
  Verify(Method(mock, map));

  /**
   * @brief Test put
   *
   */
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  DotENVLine line(key, value);
  i.put(line);
  Verify(Method(mock, put));

  /**
   * @brief Test contains
   *
   */
  REQUIRE(i.contains(key));
  Verify(Method(mock, contains));

  /**
   * @brief Test value
   *
   */
  REQUIRE(i.value(key) == value);
  Verify(Method(mock, value));
}
