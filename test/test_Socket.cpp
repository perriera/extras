#include <cstdint>
#include <extras/paths.hpp>
#include <extras/strings.hpp>

#include "catch.hpp"
#include "extras/sockets/Socket.hpp"

using namespace std;
using namespace extras;

SCENARIO("Verify SocketInterface default", "[SocketInterface]") {
  string hostname = "localhost";
  int port = 8000;
  Socket socket(hostname, port);
  //   std::string value = Paths::instance().actualPath("~/Downloads");
  //   REQUIRE(value != "~/Downloads");
  //   REQUIRE(extras::contains(value, "/home/"));
  //   REQUIRE(!extras::contains(value, "~"));
}
