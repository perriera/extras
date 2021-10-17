
#include <iostream>

#include "catch.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

SCENARIO("Mock BinInterface: toOctal", "[BinInterface]") {
  const byte correct_answer[] = {0x01, 0x02, 0x03};
  Mock<BinInterface> mock;
  When(Method(mock, array)).Return(correct_answer);
  When(Method(mock, size)).Return(sizeof(correct_answer) / sizeof(byte));

  BinInterface& i = mock.get();
  REQUIRE(i.array() == correct_answer);
  REQUIRE(i.size() == 3);
  Verify(Method(mock, array));
  Verify(Method(mock, size));
}