
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/PortAuthority.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock PortAuthorityInterface: domainName",
         "[PortAuthorityInterface]") {
  std::string correct_answer = "cplusplus.org";
  Mock<PortAuthorityInterface> mock;
  When(Method(mock, domainName)).Return(correct_answer);

  PortAuthorityInterface &i = mock.get();
  REQUIRE(i.domainName() == correct_answer);
  Verify(Method(mock, domainName));
}
