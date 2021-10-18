
#include <iostream>

#include "catch.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

SCENARIO("Mock BinInterface: array/size", "[BinInterface]") {
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

SCENARIO("Mock HexInterface: array", "[BinInterface]") {
  const HexArray correct_answer;
  Mock<HexInterface> mock;
  When(Method(mock, array)).Return(correct_answer);
  When(Method(mock, lines)).Return(0);
  When(Method(mock, size)).Return(0);

  HexInterface& i = mock.get();
  REQUIRE(i.array() == correct_answer);
  REQUIRE(i.lines() == 0);
  REQUIRE(i.size() == 0);
  Verify(Method(mock, array));
  Verify(Method(mock, lines));
  Verify(Method(mock, size));
}

SCENARIO("Mock Bin2HexInterface: bin2hex", "[BinInterface]") {
  HexArray correct_answer;
  Mock<Bin2HexInterface> mock;
  When(Method(mock, bin2hex)).Return(correct_answer);

  BinFile param1;
  Bin2HexInterface& i = mock.get();
  REQUIRE(i.bin2hex(param1) == correct_answer);
  Verify(Method(mock, bin2hex));
}

SCENARIO("Mock Hex2BinInterface: hex2bin", "[BinInterface]") {
  BinArray correct_answer;
  Mock<Hex2BinInterface> mock;
  When(Method(mock, hex2bin)).Return(correct_answer);

  HexFile param1;
  Hex2BinInterface& i = mock.get();
  REQUIRE(i.hex2bin(param1) == correct_answer);
  Verify(Method(mock, hex2bin));
}
