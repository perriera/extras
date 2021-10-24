#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinConverter.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/FileTransferInterface.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/sockets/SocketClient.hpp"
#include "extras/types.hpp"
#include "fakeit.hpp"

using namespace fakeit;
using namespace extras;
namespace fs = std::filesystem;

HexFile createHexFile();

SCENARIO("Mock FileTransferInterface: HexInterface",
         "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();
  const HexFile& correct_answer = hexFile;
  Mock<HexInterface> mock;
  When(Method(mock, array)).Return(correct_answer.array());
  When(Method(mock, lines)).Return(correct_answer.lines());
  When(Method(mock, size)).Return(correct_answer.size());

  const HexArray& array = hexFile.array();
  std::cout << array.size() << std::endl;
  std::cout << hexFile.size() << std::endl;
  std::cout << hexFile.lines() << std::endl;

  HexInterface& i = mock.get();
  REQUIRE(i.array() == array);
  REQUIRE(i.lines() == 7778);
  REQUIRE(i.size() == 622178);
  Verify(Method(mock, array));
  Verify(Method(mock, lines));
  Verify(Method(mock, size));
}

SCENARIO("Mock FileTransferInterface", "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();
  const HexFile& correct_answer = hexFile;
  Mock<SocketClientInterface> mock_client;
  When(Method(mock_client, connect)).Return();
  SocketClientInterface& i_client = mock_client.get();
  Mock<FileTransferInterface> mock;
  When(Method(mock, transfer))
      .AlwaysDo([&hexFile, &i_client](const HexInterface&,
                                      SocketInterface& socket) {});

  FileTransferInterface& i = mock.get();
  i.transfer(hexFile, i_client);
  Verify(Method(mock, transfer));
}
