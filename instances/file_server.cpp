#include <extras/sockets/SocketServer.hpp>
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
#include "extras/paths.hpp"

using namespace std;
using namespace extras;
namespace fs = std::filesystem;

#include <iostream>
#include <sstream>

using namespace std;
using namespace extras;

#define PORT 8000
int main(int, char const*[]) {
  try {
    SocketServer server(PORT);
    server.accept();
    FileTransfer fileTransfer;
    // HexArray hexArray = fileTransfer.download(server);

    string msg = server.read();
    cout << msg << endl;
    stringstream ss;
    ss << "Hello from SocketServer" << endl;
    server.send(ss.str());
  } catch (SocketException& ex) {
    cout << ex.what() << endl;
  }
}
