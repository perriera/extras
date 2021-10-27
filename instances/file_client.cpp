#include <extras/sockets/SocketClient.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/bin2hex/BinConverter.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/FileTransferInterface.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/filesystem/paths.hpp"

using namespace std;
using namespace extras;
namespace fs = std::filesystem;

HexFile createHexFile() {
  string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  std::string path = ~Paths(filename);
  ifstream myfile(path);
  BinFile binFile;
  myfile >> binFile;
  auto file_size = fs::file_size(filename);
  HexConverter hexConverter(64000);
  HexFile hexFile = hexConverter.bin2hex(binFile);
  return hexFile;
}

#define PORT 8000
int main(int, char const* argv[]) {
  try {
    HexFile hexFile = createHexFile();

    std::string argv1 = argv[1];
    SocketClient client(argv1, PORT);
    client.connect();

    FileTransfer fileTransfer;
    fileTransfer.upload(hexFile, client);

    stringstream ss;
    ss << "Hello from SocketClient" << endl;
    client.send(ss.str());
    string msg = client.read();
    cout << msg << endl;
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
