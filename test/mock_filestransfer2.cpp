
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

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
namespace fs = std::filesystem;

struct MockSocket implements SocketInterface {
  HexArray& _packets;
  HexLine _nextLine;
  HexArray _sent;
  HexArray _recieved;

  MockSocket(HexArray& packets) : _packets(packets) {}

  virtual void send(const std::string& msg) {
    _packets.push_back(msg);
    _sent.push_back(msg);
  };
  virtual SocketInterface& read(int expectedMaxSize = 1024) {
    _nextLine = _packets.front();
    _packets.erase(_packets.begin());
    _recieved.push_back(_nextLine);
    return *this;
  };
  virtual operator std::string() const { return _nextLine; };
  virtual operator SocketPacket() const { return SocketPacket(); };
};

struct MockServer extends MockSocket {
  HexArray _processed;
  MockServer(HexArray& packets) : MockSocket(packets){};
  void processData() { _processed = _recieved; }
};

struct MockClient extends MockSocket {
  HexArray _processed;
  MockClient(HexArray& packets) : MockSocket(packets){};
  void processData() { _processed = _recieved; }
};

SCENARIO("MockSocketServer/MockSocketClient", "[HexFileTransfer2]") {
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

  HexArray packets;
  MockServer mockServer(packets);
  MockClient mockClient(packets);
  for (auto packet : hexFile.array()) {
    mockClient.send(packet);
    std::string line = mockServer.read();
    std::cout << "\r" << line << std::flush;
    REQUIRE(line == packet);
  }
  std::cout << std::endl;

  mockServer.processData();

  for (auto processedLine : mockServer._processed) {
    mockServer.send(processedLine);
    std::string packetBack = mockClient.read();
    std::cout << "\r" << packetBack << std::flush;
    REQUIRE(packetBack == processedLine);
  }
  std::cout << std::endl;

  REQUIRE(mockServer._sent == mockClient._recieved);
  REQUIRE(mockServer._recieved == mockClient._sent);

  // setup client
}