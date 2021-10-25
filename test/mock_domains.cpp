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
  auto correct_answer = "1.2.3.4";
  Mock<DomainInterface> mock;
  When(Method(mock, resolve)).Return(correct_answer);
  When(Method(mock, name)).Return("www.xyz.com");
  When(Method(mock, ip)).Return(correct_answer);
  When(Method(mock, exists)).Return(true);

  DomainInterface &i = mock.get();
  REQUIRE(i.resolve("www.xyz.com") == correct_answer);
  REQUIRE(i.name() == "www.xyz.com");
  REQUIRE(i.ip() == correct_answer);
  REQUIRE(i.exists() == true);
  Verify(Method(mock, resolve));
  Verify(Method(mock, name));
  Verify(Method(mock, ip));
  Verify(Method(mock, exists));
}
