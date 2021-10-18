
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/bin2hex/HexFileTransfer.hpp"
#include "extras/sockets/SocketClient.hpp"
#include "extras/sockets/SocketServer.hpp"
#include "fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;
namespace fs = std::filesystem;

HexArray packets;
HexLine nextLine;

class MockSocket implements SocketInterface {
  virtual void send(const std::string& msg) { packets.push_back(msg); };
  virtual SocketInterface& read(int expectedMaxSize) {
    nextLine = packets.front();
    packets.erase(packets.begin());
  };
  virtual operator std::string() const { return nextLine; };
  virtual operator SocketPacket() const {};
};

SCENARIO("Mock HexFileTransferInterface: array/size", "[HexFileTransfer]") {
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

  // setup server

  MockSocket mockServer;
  Mock<SocketServerInterface> mock_server;
  When(Method(mock_server, read)).Return(mockServer);
  SocketServerInterface& i_server = mock_server.get();
  nextLine = "Hello";
  std::string text1 = i_server.read(1024);
  REQUIRE(text1 == "Hello");
  Verify(Method(mock_server, read));

  // setup client

  MockSocket mockClient;
  Mock<SocketServerInterface> mock_client;
  When(Method(mock_client, read)).Return(mockClient);
  SocketServerInterface& i_client = mock_client.get();
  std::string text2 = i_client.read(1024);
  REQUIRE(text2 == "Hello");
  Verify(Method(mock_client, read));

  // SocketServerInterface

  const byte correct_answer[] = {0x01, 0x02, 0x03};
  Mock<HexFileTransferInterface> mock;
  When(Method(mock, size)).Return(sizeof(correct_answer) / sizeof(byte));
  HexFileTransferInterface& i = mock.get();
  REQUIRE(i.size() == 3);
  Verify(Method(mock, size));
}