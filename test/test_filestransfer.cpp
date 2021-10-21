
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

  MockSocket(HexArray& packets) : _packets(packets) {}

  virtual void send(const std::string& msg) { _packets.push_back(msg); };
  virtual SocketInterface& read(int) {
    _nextLine = _packets.front();
    _packets.erase(_packets.begin());
    return *this;
  };
  virtual operator std::string() const { return _nextLine; };
  virtual operator SocketPacket() const { return SocketPacket(); };
};

// SCENARIO("Mock HexFileTransferInterface: read one", "[HexFileTransfer]") {
//   HexArray packets;

//   MockSocket mockServer(packets);
//   MockSocket mockClient(packets);
// //   mockServer.send("hello");
// //   std::string text = mockClient.read();
// //   REQUIRE(text == "hello");
// // }

// SCENARIO("Mock HexFileTransferInterface: read many", "[HexFileTransfer]") {
//   std::string filename =
//   "data/Downloads/cplusplusorg.freeformjs.imploded.zip"; std::ifstream
//   myfile(filename); REQUIRE(myfile.good()); BinFile binFile; myfile >>
//   binFile; auto file_size = fs::file_size(filename); REQUIRE(binFile.array()
//   != nullptr); REQUIRE(binFile.size() == file_size); HexConverter
//   hexConverter; HexFile hexFile = hexConverter.bin2hex(binFile);
//   REQUIRE(hexFile.size() == file_size * 2);

//   HexArray packets;
//   MockSocket mockServer(packets);
//   MockSocket mockClient(packets);
//   for (auto packet : hexFile.array()) {
//     mockServer.send(packet);
//     std::string line = mockClient.read();
//     std::cout << "\r" << line << std::flush;
//     REQUIRE(line == packet);
//   }

//   // setup client
// }