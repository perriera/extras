#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

SCENARIO("Mock UploaderInterface: parameters", "[UploaderInterface]") {
  char const* argv[] = {"build/rsi_client", "159.223.103.27", "8080", "upload",
                        "send.txt"};
  int argc = 5;
  Mock<rsi::UploaderInterface> mock;
  When(Method(mock, parameters)).AlwaysDo([](int argc, char const* argv[]) {
    rsi::Parameters result;
    for (int i = 0; i < argc; i++) result.push_back(argv[i]);
    return result;
  });

  rsi::UploaderInterface& i = mock.get();
  REQUIRE(i.parameters(argc, argv).size() == 5);
  Verify(Method(mock, parameters));
}
