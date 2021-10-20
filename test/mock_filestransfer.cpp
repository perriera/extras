#include <extras/bin2hex/BinFile.hpp>
#include <extras/bin2hex/HexConverter.hpp>
#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexFileTransfer.hpp>
#include <extras/sockets/SocketClient.hpp>
#include <extras/sockets/SocketServer.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;
namespace fs = std::filesystem;

struct MockHexFileTransfer implements HexFileTransferInterface {
  const HexInterface& _hexFile;
  MockHexFileTransfer(const HexInterface& hexInterface)
      : _hexFile(hexInterface) {}
  virtual void transfer(const HexInterface&) override{};
  virtual const HexArray& lines() const override { return _hexFile.array(); };

  virtual int size() const override { return _hexFile.size(); };
};

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock HexFileTransferInterface: transfer", "[HexFileTransfer]") {
  std::string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  std::ifstream myfile(filename);
  REQUIRE(myfile.good());
  BinFile binFile;
  myfile >> binFile;
  auto file_size = fs::file_size(filename);
  REQUIRE(binFile.array() != nullptr);
  REQUIRE(binFile.size() == file_size);
  HexConverter hexConverter;
  HexFile hexFile = hexConverter.bin2hex(binFile);
  REQUIRE(hexFile.size() == file_size * 2);

  MockHexFileTransfer mockHexFileTransfer(hexFile);

  Mock<HexFileTransferInterface> mock;
  When(Method(mock, transfer))
      .AlwaysDo([&mockHexFileTransfer](const HexInterface&) {});

  HexFileTransferInterface& i = mock.get();
  i.transfer(hexFile);
  Verify(Method(mock, transfer));
}
