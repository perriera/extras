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
  SocketInterface& _socket;
  MockHexFileTransfer(SocketInterface& socket) : _socket(socket) {}
  virtual SocketInterface& socket();
  virtual void transfer(const HexInterface&) {}
};

struct MockSocket2 implements SocketInterface {
  HexLine _nextLine;
  HexArray _sent;
  HexArray _recieved;
  int _next = 0;

  virtual void send(const std::string& msg) override {
    _nextLine = msg;
    _sent.push_back(msg);
  };
  virtual SocketInterface& read(int) override {
    _recieved.push_back(_nextLine);
    return *this;
  };
  virtual operator std::string() const override { return _nextLine; };
  virtual operator SocketPacket() const override { return SocketPacket(); };
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

  MockSocket2 socket;
  MockSocket2 client;

  Mock<HexFileTransferInterface> mock;
  When(Method(mock, transfer))
      .AlwaysDo([&client](const HexInterface& hexInterface) {
        HexLine line = hexInterface.array()[client._next++];
        std::stringstream ss;
        ss << line << std::endl;
        client.send(line);
        std::string nextLine = client.read(1024);
        REQUIRE(line == nextLine);
      });

  HexFileTransferInterface& i = mock.get();
  i.transfer(hexFile);
  Verify(Method(mock, transfer));
}
