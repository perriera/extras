
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/Services.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock ServicesInterface", "[ServicesInterface]") {
  PortNumber portNumber = 9000;
  RequestedService requestedService = "upload";
  Mock<ServicesInterface> mock;
  When(Method(mock, request)).Return(requestedService);

  ServicesInterface &i = mock.get();
  REQUIRE(i.request(portNumber) == requestedService);
  Verify(Method(mock, request));
}
