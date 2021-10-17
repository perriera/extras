
#include <iostream>

#include "catch.hpp"
#include "extras/sockets/SocketServer.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock SocketServerInterface: toOctal", "[SocketServerInterface]") {
  auto correct_answer = InputStream();
  Mock<SocketServerInterface> mock;
  When(Method(mock, getInputStream)).Return(correct_answer);

  SocketServerInterface &i = mock.get();
  REQUIRE(i.getInputStream() == correct_answer);
  Verify(Method(mock, getInputStream));
}
