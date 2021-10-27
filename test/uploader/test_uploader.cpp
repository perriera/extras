#include <extras/bin2hex/BinFile.hpp>
#include <extras/bin2hex/HexConverter.hpp>
#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexFileTransfer.hpp>
#include <extras/bin2hex/HexPacket.hpp>
#include <extras/filesystem/paths.hpp>
#include <extras/sockets/SocketClient.hpp>
#include <extras/sockets/SocketServer.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../sockets/MockSocket.hpp"
#include "../vendor/catch.hpp"
#include "../vendor/fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;
namespace fs = std::filesystem;

struct Uploader implements UploaderInterface {
  SocketInterface& _socket;
  Uploader(SocketInterface& socket) : _socket(socket) {}
  virtual SocketInterface& socket() override { return _socket; };
  virtual void upload(const HexPacket& packet) override {
    std::stringstream ss;
    ss << packet << std::endl;
    _socket.send(ss.str());
  }
};

struct Downloader implements DownloaderInterface {
  SocketInterface& _socket;
  Downloader(SocketInterface& socket) : _socket(socket) {}
  virtual SocketInterface& socket() override { return _socket; };
  virtual HexPacket download() override {
    std::string rawData = _socket.read(1024);
    std::stringstream ss;
    ss << rawData << std::flush;
    HexPacket packet;
    ss >> packet;
    return packet;
  }
};

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock UploaderInterface: upload", "[HexFileTransfer]") {
  std::string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  std::ifstream myfile(~Paths(filename));
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
  HexArray echo;
  HexArray echo2;
  MockServer mockServer(packets);
  MockClient mockClient(packets);
  Uploader uploader(mockClient);
  Downloader downloader(mockServer);

  int i = 0;
  int count = hexFile.array().size();
  for (auto line1 : hexFile.array()) {
    HexPacket packet1(line1, i++, count);
    uploader.upload(packet1);
    HexPacket packet2 = downloader.download();
    std::cout << '\r' << packet2 << std::flush;
    REQUIRE(packet1 == packet2);
    echo.push_back(packet2.line());
  }

  //  mockServer.process(echo);

  MockServer mockServer2(echo);
  MockClient mockClient2(echo);
  Uploader uploader2(mockServer2);
  Downloader downloader2(mockClient2);
  int j = 0;
  int count2 = hexFile.array().size();
  for (auto line1 : hexFile.array()) {
    HexPacket packet1(line1, j++, count2);
    uploader.upload(packet1);
    HexPacket packet2 = downloader.download();
    std::cout << '\r' << packet2 << std::flush;
    REQUIRE(packet1 == packet2);
    echo2.push_back(packet2.line());
  }

  REQUIRE(i == j);
  REQUIRE(count == count2);
  REQUIRE(echo == echo2);
}
