#include <iostream>

#include "catch.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/bin2hex/HexFileTransfer.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock HexFileTransferInterface: transfer", "[HexFileTransfer]") {
  HexFile hexFile;
  Mock<HexFileTransferInterface> mock;
  When(Method(mock, transfer)).Return();

  HexFileTransferInterface &i = mock.get();
  i.transfer(hexFile);
  Verify(Method(mock, transfer));
}
