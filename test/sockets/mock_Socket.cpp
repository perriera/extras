
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/SocketClient.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock SocketClientInterface: connect", "[SocketInterface]") {
  Mock<SocketClientInterface> mock;
  When(Method(mock, connect)).Return();

  SocketClientInterface &i = mock.get();
  i.connect();
  Verify(Method(mock, connect));
}
