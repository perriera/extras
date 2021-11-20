#include <extras/status/StatusLine.hpp>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

//
// printf("[+]File data downloaded successfully.\n");
//

SCENARIO("Mock StatusLineInterface", "[StatusLineInterface]") {
  extras::StatusLineMsg in1 = "File data downloaded successfully";
  extras::StatusLineMsg in2 = "Error in socket";
  extras::StatusLineMsg good = "[+] File data downloaded successfully.\n";
  extras::StatusLineMsg bad = "[-] Error in socket.\n";
  Mock<extras::StatusLineInterface> mock;
  When(Method(mock, pass)).AlwaysDo([](const extras::StatusLineMsg& msg) {
    std::stringstream ss;
    ss << "[+] " << msg << "." << std::endl;
    return ss.str();
  });
  When(Method(mock, fail)).AlwaysDo([](const extras::StatusLineMsg& msg) {
    std::stringstream ss;
    ss << "[-] " << msg << "." << std::endl;
    return ss.str();
  });

  extras::StatusLineInterface& i = mock.get();
  REQUIRE(i.pass(in1) == good);
  REQUIRE(i.fail(in2) == bad);
  Verify(Method(mock, pass));
  Verify(Method(mock, fail));
}
