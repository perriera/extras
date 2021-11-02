#include <extras/rsi/services/Process.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

//
// ss >> prg >> filename >> ip >> port;
//

SCENARIO("Mock ProcessInterface", "[ProcessInterface]") {
  std::string filename_a = "send_a.txt";
  std::string filename_b = "send_b.txt";
  std::string filename_c = "send_c.txt";
  Mock<rsi::ProcessInterface> mock;
  When(Method(mock, upload))
      .AlwaysDo([&filename_a, &filename_b, &filename_c]() {
        filename_b = filename_a;
      });
  When(Method(mock, process))
      .AlwaysDo([&filename_a, &filename_b, &filename_c]() {
        filename_c = filename_b;
      });
  When(Method(mock, download))
      .AlwaysDo([&filename_a, &filename_b, &filename_c]() {
        filename_a = filename_c;
      });
  rsi::ProcessInterface& i = mock.get();
  REQUIRE(filename_a == "send_a.txt");
  REQUIRE(filename_b == "send_b.txt");
  REQUIRE(filename_c == "send_c.txt");
  i.upload();
  i.process();
  i.download();
  REQUIRE(filename_a == "send_a.txt");
  REQUIRE(filename_b == "send_a.txt");
  REQUIRE(filename_c == "send_a.txt");
  Verify(Method(mock, upload));
  Verify(Method(mock, process));
  Verify(Method(mock, download));
}
