
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock RSIInterface", "[RSIInterface]") {
  bool async_mode = true;
  RSIRequest request = "upload";
  RSIResponse response = "upload";
  Mock<RSIInterface> mock;
  When(Method(mock, async)).Return(async_mode);
  When(Method(mock, request)).Return(request);
  When(Method(mock, response)).Return(response);

  RSIInterface &i = mock.get();
  REQUIRE(i.async() == async_mode);
  REQUIRE(i.request() == request);
  REQUIRE(i.response() == response);
  Verify(Method(mock, async));
  Verify(Method(mock, request));
  Verify(Method(mock, response));
}
