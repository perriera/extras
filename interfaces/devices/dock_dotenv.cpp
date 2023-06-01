/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include "../../test/vendor/catch.hpp"
#include "../../test/vendor/fakeit.hpp"

#include <extras/devices/dotenv.hpp>
#include <extras/docking/DockIt.hpp>
#include <iostream>

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Dock DotENVLineInterface: key", "[mock_dotenv]")
{
   auto correct_answer = EnvironmentVariableKey();
   Mold<DotENVLineInterface> dock;
   When(Method(dock, key)).Return(correct_answer);

   DotENVLineInterface& i = dock.get();
   REQUIRE(i.key() == correct_answer);
   Verify(Method(dock, key));
}

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Dock DotENVLineInterface: value", "[mock_dotenv]")
{
   auto correct_answer = EnvironmentVariableValue();
   Mold<DotENVLineInterface> dock;
   When(Method(dock, value)).Return(correct_answer);

   DotENVLineInterface& i = dock.get();
   REQUIRE(i.value() == correct_answer);
   Verify(Method(dock, value));
}

/**
 * @brief Mock DotENVInterface
 *
 */
SCENARIO("Dock DotENVInterface: map", "[mock_dotenv]")
{
   auto correct_answer = EnvironmentVariableMap();
   Mold<DotENVInterface> dock;
   When(Method(dock, map)).Return(correct_answer);

   DotENVInterface& i = dock.get();
   REQUIRE(i.map() == correct_answer);
   Verify(Method(dock, map));
}

SCENARIO("Dock DotENVInterface: put", "[mock_dotenv]")
{
   Mold<DotENVInterface> dock;
   When(Method(dock, put)).Return();

   DotENVInterface& i = dock.get();
   EnvironmentVariableKey key;
   EnvironmentVariableValue value;
   DotENVLine line(key, value);
   i.put(line);
   Verify(Method(dock, put));
}

SCENARIO("Dock DotENVInterface: contains", "[mock_dotenv]")
{
   /**
    * @brief Simulate a class and class members here
    *
    * An EnvironmentVariableMap mains a key/value list
    * in sorted, searchable order.
    *
    */
   EnvironmentVariableMap correct_answer = EnvironmentVariableMap();
   Mold<DotENVInterface> dock;
   When(Method(dock, put))
     .AlwaysDo([&correct_answer](const DotENVLineInterface& entry) {
        correct_answer[entry.key()] = entry.value();
     });
   When(Method(dock, map)).Return(correct_answer);
   When(Method(dock, contains)).AlwaysDo([&correct_answer](auto key) {
      return correct_answer.find(key) != correct_answer.end();
   });
   When(Method(dock, value)).AlwaysDo([&correct_answer](auto key) {
      return correct_answer[key];
   });
   DotENVInterface& i = dock.get();

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
