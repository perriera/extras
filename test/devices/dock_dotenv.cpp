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

#include <extras/devices/dotenv.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/docking/DockIt.hpp"

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
  Dock<DotENVLineInterface> dock;
  When(Method(dock, key)).Return(correct_answer);

  DotENVLineInterface &i = dock.get();
  REQUIRE(i.key() == correct_answer);
  Verify(Method(dock, key));
}

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Mock DotENVLineInterface: value", "[mock_dotenv]") {
  auto correct_answer = EnvironmentVariableValue();
  Dock<DotENVLineInterface> dock;
  When(Method(dock, value)).Return(correct_answer);

  DotENVLineInterface &i = dock.get();
  REQUIRE(i.value() == correct_answer);
  Verify(Method(dock, value));
}

/**
 * @brief Mock DotENVInterface
 *
 */
SCENARIO("Mock DotENVInterface: map", "[mock_dotenv]") {
  auto correct_answer = EnvironmentVariableMap();
  Dock<DotENVInterface> dock;
  When(Method(dock, map)).Return(correct_answer);

  DotENVInterface &i = dock.get();
  REQUIRE(i.map() == correct_answer);
  Verify(Method(dock, map));
}

SCENARIO("Mock DotENVInterface: put", "[mock_dotenv]") {
  Dock<DotENVInterface> dock;
  When(Method(dock, put)).Return();

  DotENVInterface &i = dock.get();
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  DotENVLine line(key, value);
  i.put(line);
  Verify(Method(dock, put));
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
  Dock<DotENVInterface> dock;
  When(Method(dock, put))
      .AlwaysDo([&correct_answer](const DotENVLineInterface &entry) {
        correct_answer[entry.key()] = entry.value();
      });
  When(Method(dock, map)).Return(correct_answer);
  When(Method(dock, contains)).AlwaysDo([&correct_answer](auto key) {
    return correct_answer.find(key) != correct_answer.end();
  });
  When(Method(dock, value)).AlwaysDo([&correct_answer](auto key) {
    return correct_answer[key];
  });
  DotENVInterface &i = dock.get();

  /**
   * @brief Test map
   *
   */
  REQUIRE(i.map() == correct_answer);
  Verify(Method(dock, map));

  /**
   * @brief Test put
   *
   */
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  DotENVLine line(key, value);
  i.put(line);
  Verify(Method(dock, put));

  /**
   * @brief Test contains
   *
   */
  REQUIRE(i.contains(key));
  Verify(Method(dock, contains));

  /**
   * @brief Test value
   *
   */
  REQUIRE(i.value(key) == value);
  Verify(Method(dock, value));
}
