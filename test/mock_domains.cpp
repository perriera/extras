#include <extras/sockets/Domains.hpp>
#include <iostream>

#include "catch.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock DotENVLineInterface
 *
 */
SCENARIO("Mock DomainInterface: key", "[DomainInterface]") {
  auto dns = "www.xyz.com";
  auto ip = "1.2.3.4";
  Mock<DomainInterface> mock;
  When(Method(mock, resolve)).Return(ip);
  When(Method(mock, name)).Return(dns);
  When(Method(mock, ip)).Return(ip);
  When(Method(mock, exists)).Return(true);

  DomainInterface &i = mock.get();
  REQUIRE(i.resolve() == ip);
  REQUIRE(i.name() == dns);
  REQUIRE(i.ip() == ip);
  REQUIRE(i.exists() == true);
  Verify(Method(mock, resolve));
  Verify(Method(mock, name));
  Verify(Method(mock, ip));
  Verify(Method(mock, exists));
}
