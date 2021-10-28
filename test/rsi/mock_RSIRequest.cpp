
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock RSIRequestInterface", "[RSIRequestInterface]") {
  PortServerNumber port = 8080;
  PortNumber client = 9000;
  RSIUpload request("filename", "ip", port, true);
  Mock<RSIRequestInterface> mock_client;
  When(Method(mock_client, request)).Return(request);
  Mock<RSIRequestInterface> mock_server;
  When(Method(mock_server, request)).Return(request);
  RSIRequestInterface& i_client = mock_client.get();
  RSIRequestInterface& i_server = mock_server.get();
  REQUIRE(i_client.request(request, port) == request);
  REQUIRE(i_server.request(request, port) == request);
  Verify(Method(mock_client, request));
  Verify(Method(mock_server, request));
}
