
#include <iostream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"
#include "extras/sockets/PortAuthority.hpp"

using namespace extras;

SCENARIO("Test PortAuthorityInterface", "[PortAuthorityInterface]") {
  int correct_socketserverport = 8080;
  int correct_request = 9000;

  PortAuthority portAuthority;

  REQUIRE(portAuthority.serversocketport() == correct_socketserverport);
  REQUIRE(portAuthority.request() == correct_request);
  REQUIRE(portAuthority.request() == correct_request + 1);
}

SCENARIO("Test PortAuthorityInterface: test wrap", "[PortAuthorityInterface]") {
  int correct_socketserverport = 8080;
  int correct_start = 9000;
  int correct_size = 3;

  PortAuthority portAuthority(correct_socketserverport, correct_start,
                              correct_size);

  REQUIRE(portAuthority.serversocketport() == correct_socketserverport);
  REQUIRE(portAuthority.request() == correct_start + 0);
  REQUIRE(portAuthority.request() == correct_start + 1);
  REQUIRE(portAuthority.request() == correct_start + 2);
  REQUIRE(portAuthority.request() == correct_start + 0);
  REQUIRE(portAuthority.request() == correct_start + 1);
  REQUIRE(portAuthority.request() == correct_start + 2);
}
