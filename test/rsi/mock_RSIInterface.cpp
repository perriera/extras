
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

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
  When(Method(mock, request)).Return(request);

  RSIInterface& i = mock.get();
  REQUIRE(i.async() == async_mode);
  REQUIRE(i.client() == client);
  REQUIRE(i.server() == server);
  REQUIRE(i.request(request, 8080) == request);
  Verify(Method(mock, async));
  Verify(Method(mock, client));
  Verify(Method(mock, server));
  Verify(Method(mock, request));
}
