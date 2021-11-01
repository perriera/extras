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
  When(Method(mock, upload)).Return();
  When(Method(mock, process)).Return();
  When(Method(mock, download)).Return();
  rsi::ProcessInterface& i = mock.get();
  i.upload();
  i.process();
  i.download();
  Verify(Method(mock, upload));
  Verify(Method(mock, process));
  Verify(Method(mock, download));
}
