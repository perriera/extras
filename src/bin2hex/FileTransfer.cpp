#include <iostream>
#include <sstream>

#include "extras/bin2hex/FileTransferInterface.hpp"

using namespace std;

namespace extras {

  void FileTransfer::upload(const HexInterface& hexFile,
                            SocketInterface& socket) {
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
      _echo.push_back(response.line());
    }
  }

  void FileTransfer::download(const HexInterface&, SocketInterface& socket) {}

}  // namespace extras
