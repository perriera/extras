
#include <iostream>

#include "catch.hpp"
#include "extras/sockets/Socket.hpp"
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
SCENARIO("Mock SocketInterface: toOctal", "[SocketInterface]") {
  auto correct_answer = InputStream();
  Mock<SocketInterface> mock;
  When(Method(mock, getInputStream)).Return(correct_answer);

  SocketInterface &i = mock.get();
  REQUIRE(i.getInputStream() == correct_answer);
  Verify(Method(mock, getInputStream));
}
