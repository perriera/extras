
#include <extras/bin2hex/BinFile.hpp>
#include <extras/bin2hex/HexConverter.hpp>
#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexFileTransfer.hpp>
#include <extras/paths.hpp>
#include <extras/sockets/SocketClient.hpp>
#include <extras/sockets/SocketServer.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "MockSocket.hpp"
#include "catch.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
namespace fs = std::filesystem;

HexFile createHexFile();

SCENARIO("MockSocketServer/MockSocketClient", "[HexFileTransfer2]") {
  HexFile hexFile = createHexFile();

  HexArray packets;
  MockServer mockServer(packets);
  MockClient mockClient(packets);
  for (auto packet : hexFile.array()) {
    mockClient.send(packet);
    std::string line = mockServer.read(1024);
    std::cout << "\r" << line << std::flush;
    REQUIRE(line == packet);
  }
  std::cout << std::endl;

  mockServer.processData();

  for (auto processedLine : mockServer._processed) {
    mockServer.send(processedLine);
    std::string packetBack = mockClient.read(1024);
    std::cout << "\r" << packetBack << std::flush;
    REQUIRE(packetBack == processedLine);
  }
  std::cout << std::endl;

  REQUIRE(mockServer._sent == mockClient._recieved);
  REQUIRE(mockServer._recieved == mockClient._sent);

  // setup client
}