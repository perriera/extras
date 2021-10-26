#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../mocks/MockSocket.hpp"
#include "../vendor/catch.hpp"
#include "extras/bin2hex/BinConverter.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/FileTransferInterface.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/language/types.hpp"
#include "extras/sockets/SocketClient.hpp"

using namespace extras;
namespace fs = std::filesystem;

HexFile createHexFile();

SCENARIO("Test FileTransferInterface MockClient/MockServer",
         "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();

  HexArray packets;
  HexArray echo;
  HexArray echo2;
  MockServer mockServer(packets);
  MockClient mockClient(packets);

  SocketInterface& i_client = mockClient;

  FileTransfer fileTransfer;
  fileTransfer.upload(hexFile, i_client);
  const HexArray& a = fileTransfer;
  const HexArray& b = hexFile;
  REQUIRE(a == b);
}

SCENARIO("Test FileTransferInterface FileClient/FileServer",
         "[FileTransferInterface]") {
  HexFile hexFile = createHexFile();

  HexArray packets;
  HexArray echo;
  HexArray echo2;
  MockServer mockServer(packets);
  MockClient mockClient(packets);

  SocketInterface& i_client = mockClient;

  FileTransfer fileTransfer;
  fileTransfer.upload(hexFile, i_client);
  const HexArray& a = fileTransfer;
  const HexArray& b = hexFile;
  REQUIRE(a == b);
}
