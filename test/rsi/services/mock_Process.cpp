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
  Mock<rsi::ProcessInterface> mock;
  When(Method(mock, process)).Return();
  rsi::ProcessInterface& i = mock.get();
  i.process();
  Verify(Method(mock, process));
}
