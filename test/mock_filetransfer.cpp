#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "MockSocket.hpp"
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
  // const HexFile& correct_answer = hexFile;
  Mock<SocketClientInterface> mock_client;
  When(Method(mock_client, connect)).Return();
  SocketClientInterface& i_client = mock_client.get();
  Mock<FileTransferInterface> mock;
  When(Method(mock, upload))
      .AlwaysDo(
          [&hexFile, &i_client](const HexInterface&, SocketInterface&) {});

  FileTransferInterface& i = mock.get();
  i.upload(hexFile, i_client);
  Verify(Method(mock, upload));
}

SCENARIO("Mock FileTransferInterface upload", "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();
  const HexArray& array = hexFile.array();

  HexArray packets;
  HexArray echo;
  HexArray echo2;
  MockServer mockServer(packets);
  MockClient mockClient(packets);

  SocketInterface& i_client = mockClient;
  Mock<FileTransferInterface> mock;
  When(Method(mock, upload))
      .AlwaysDo([&echo](const HexInterface& hexFile, SocketInterface& socket) {
        int i = 0;
        int count = hexFile.array().size();
        for (auto line : hexFile.array()) {
          // send
          HexPacket request(line, i++, count);
          {
            std::stringstream ss;
            ss << request << std::endl;
            socket.send(ss.str());
          }
          // recieve
          std::string rawData = socket.read(1024);
          HexPacket response;
          {
            std::stringstream ss;
            ss << rawData << std::flush;
            ss >> response;
          }
          if (response != request) throw "Somethign wrong";
          echo.push_back(response.line());
        }
      });

  FileTransferInterface& i = mock.get();
  i.upload(hexFile, i_client);
  REQUIRE(array == echo);
  Verify(Method(mock, upload));
}

SCENARIO("Mock FileTransferInterface download", "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();
  const HexArray& array = hexFile.array();

  HexArray packets;
  HexArray echo;
  HexArray echo2;
  MockServer mockServer(packets);
  MockClient mockClient(packets);

  SocketInterface& i_server = mockServer;
  Mock<FileTransferInterface> mock;
  When(Method(mock, download))
      .AlwaysDo([&echo](const HexInterface& hexFile, SocketInterface& socket) {
        int i = 0;
        int count = hexFile.array().size();
        for (auto line : hexFile.array()) {
          // send
          HexPacket request(line, i++, count);
          {
            std::stringstream ss;
            ss << request << std::endl;
            socket.send(ss.str());
          }
          // recieve
          std::string rawData = socket.read(1024);
          HexPacket response;
          {
            std::stringstream ss;
            ss << rawData << std::flush;
            ss >> response;
          }
          if (response != request) throw "Somethign wrong";
          echo.push_back(response.line());
        }
      });

  FileTransferInterface& i = mock.get();
  i.download(hexFile, i_server);
  REQUIRE(array == echo);
  Verify(Method(mock, download));
}
