#include <extras/sockets/Domains.hpp>
#include <iostream>

#include "vendor/catch.hpp"
#include "vendor/fakeit.hpp"

using namespace extras;

/**
 * @brief Test DomainInterface
 *
 */
SCENARIO("Test DomainInterface", "[DomainInterface]") {
  IPAddress ip = "104.236.207.122";
  DomainName dn = "cplusplus.org";
  Domain test(dn);
  REQUIRE(test.name() == dn);
  REQUIRE(test.ip() == ip);
  REQUIRE(test.exists());
  std::string test_ip = ~test;
  REQUIRE(test_ip == ip);
}

SCENARIO("Test DomainInterface: not found", "[DomainInterface]") {
  REQUIRE_THROWS_AS(Domain("cplusplusxxx.org"), DomainException);
  // REQUIRE(!Domain("cplusplusxxx.org").exists());
}