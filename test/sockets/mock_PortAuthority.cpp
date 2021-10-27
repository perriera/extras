
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/PortAuthority.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock PortAuthorityInterface", "[PortAuthorityInterface]") {
  int correct_request = 9000;
  Mock<PortAuthorityInterface> mock;
  When(Method(mock, request)).Return(correct_request);

  PortAuthorityInterface &i = mock.get();
  REQUIRE(i.request() == correct_request);
  Verify(Method(mock, request));
}
