
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
SCENARIO("Mock SocketInterface: connect", "[SocketInterface]") {
  Mock<SocketInterface> mock;
  When(Method(mock, connect)).Return();

  SocketInterface &i = mock.get();
  i.connect();
  Verify(Method(mock, connect));
}
