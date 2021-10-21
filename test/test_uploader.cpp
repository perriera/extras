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

#include "MockSocket.hpp"
#include "catch.hpp"
#include "fakeit.hpp"

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
  virtual void upload(const HexLine& line) override {
    std::stringstream ss;
    ss << line << std::endl;
    _socket.send(line);
    // std::string response = _socket.read(1024);
  }
};

struct Downloader implements DownloaderInterface {
  SocketInterface& _socket;
  Downloader(SocketInterface& socket) : _socket(socket) {}
  virtual SocketInterface& socket() override { return _socket; };
  virtual HexLine download() override {
    HexLine line = _socket.read(1024);
    // _socket.send(line);
    return line;
  }
};

/**
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Mock UploaderInterface: upload", "[HexFileTransfer]") {
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
  Uploader uploader(mockClient);
  Downloader downloader(mockServer);
  HexLine line1 = hexFile.array()[0];
  uploader.upload(line1);
  HexLine line2 = downloader.download();
  REQUIRE(line1 == line2);
}
