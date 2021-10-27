
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/Requests.hpp"

using namespace extras;
using namespace fakeit;
using namespace std;

SCENARIO("Mock RequestsInterface", "[RequestsInterface]") {
  RequestedService serviceName = "upload";
  PortServerNumber serverSocket = 8080;
  int port_to_use = 9000;
  Mock<RequestsInterface> mock;
  When(Method(mock, request)).Return(port_to_use);

  RequestsInterface& i = mock.get();
  REQUIRE(i.request(serviceName, serverSocket) == port_to_use);
  Verify(Method(mock, request));
}
