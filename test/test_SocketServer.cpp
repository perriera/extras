#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>

#include "catch.hpp"
#include "extras/sockets/SocketServer.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify SocketServerInterface default", "[SocketServerInterface]") {
  int port = 8000;
  SocketServer socket(port);
  //   std::string value = Paths::instance().actualPath("~/Downloads");
  //   REQUIRE(value != "~/Downloads");
  //   REQUIRE(extras::contains(value, "/home/"));
  //   REQUIRE(!extras::contains(value, "~"));
}
