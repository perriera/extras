
#include <extras/rsi/interfaces.hpp>
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock RSIInterface", "[RSIInterface]") {
  bool async_mode = true;
  RSIClient client = "upload";
  RSIServer server = "upload";
  RSIUpload request("filename", "ip", 8080, true);
  Mock<RSIInterface> mock;
  When(Method(mock, async)).Return(async_mode);
  When(Method(mock, client)).Return(client);
  When(Method(mock, server)).Return(server);

  RSIInterface& i = mock.get();
  REQUIRE(i.async() == async_mode);
  REQUIRE(i.client() == client);
  REQUIRE(i.server() == server);
  Verify(Method(mock, async));
  Verify(Method(mock, client));
  Verify(Method(mock, server));
}
