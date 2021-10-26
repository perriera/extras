
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/SocketServer.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock SocketServerInterface: accept", "[SocketServerInterface]") {
  Mock<SocketServerInterface> mock;
  When(Method(mock, accept)).Return();

  SocketServerInterface &i = mock.get();
  i.accept();
  Verify(Method(mock, accept));
}
