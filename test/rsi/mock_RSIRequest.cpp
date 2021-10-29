
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock RSIRequestInterface", "[RSIRequestInterface]") {
  PortServerNumber before = 8080;
  PortNumber after = 9000;
  RSIUpload request("filename", "ip", before, true);

  Mock<RSIRequestInterface> mock;
  When(Method(mock, request))
      .AlwaysDo(
          [&after](RSIInterface& requestedService, const PortServerNumber&) {
            requestedService.setPort(after);
          });

  RSIRequestInterface& i = mock.get();
  REQUIRE(request.port() == before);
  i.request(request, before);
  REQUIRE(request.port() == after);
  Verify(Method(mock, request));
}
