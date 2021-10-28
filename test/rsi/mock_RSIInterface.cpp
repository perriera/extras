
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock RSIInterface", "[RSIInterface]") {
  bool async_mode = true;
  RSICLient request = "upload";
  RSIServer response = "upload";
  Mock<RSIInterface> mock;
  When(Method(mock, async)).Return(async_mode);
  When(Method(mock, client)).Return(request);
  When(Method(mock, server)).Return(response);

  RSIInterface &i = mock.get();
  REQUIRE(i.async() == async_mode);
  REQUIRE(i.client() == request);
  REQUIRE(i.server() == response);
  Verify(Method(mock, async));
  Verify(Method(mock, client));
  Verify(Method(mock, server));
}
