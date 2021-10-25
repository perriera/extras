#include <extras/sockets/Domains.hpp>
#include <iostream>

#include "catch.hpp"
#include "fakeit.hpp"

using namespace extras;

/**
 * @brief Test DomainInterface
 *
 */
SCENARIO("Test DomainInterface", "[DomainInterface]") {
  Domain test("cplusplus.org");
  REQUIRE(test.name() == "cplusplus.org");
  REQUIRE(test.ip() == "104.236.207.122");
  REQUIRE(test.exists());
}

SCENARIO("Test DomainInterface: not found", "[DomainInterface]") {
  REQUIRE_THROWS_AS(Domain("cplusplusxxx.org"), DomainException);
}