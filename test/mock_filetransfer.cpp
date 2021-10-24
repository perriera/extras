#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinConverter.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/types.hpp"
#include "fakeit.hpp"

using namespace fakeit;
using namespace extras;
namespace fs = std::filesystem;

HexFile createHexFile();

SCENARIO("Mock FileTransferInterface", "[FileTransferInterface]") {
  const byte correct_answer[] = {0x01, 0x02, 0x03};
  Mock<BinInterface> mock;
  When(Method(mock, array)).Return(correct_answer);
  When(Method(mock, size)).Return(sizeof(correct_answer) / sizeof(byte));

  HexFile hexFile = createHexFile();

  BinInterface& i = mock.get();
  REQUIRE(i.array() == correct_answer);
  REQUIRE(i.size() == 3);
  Verify(Method(mock, array));
  Verify(Method(mock, size));
}
