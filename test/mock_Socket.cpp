
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
SCENARIO("Mock SocketClientInterface: connect", "[SocketInterface]") {
  Mock<SocketClientInterface> mock;
  When(Method(mock, connect)).Return();

  SocketClientInterface &i = mock.get();
  i.connect();
  Verify(Method(mock, connect));
}
