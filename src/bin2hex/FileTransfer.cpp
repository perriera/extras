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

  HexArray FileTransfer::download(SocketInterface& socket) {
    HexArray hexArray;
    int cnt = 0;
    while (true) {
      // recieve
      std::string rawData = socket.read(1024);
      HexPacket request;
      {
        std::stringstream ss;
        ss << rawData << std::flush;
        ss >> request;
        ss << std::endl;
        socket.send(ss.str());
        hexArray.push_back(request.line());
      }
      std::cout << '\r' << request.index() + 1 << ' ' << request.count()
                << std::flush;
      if (request.eof()) {
        std::cout << endl;
        return hexArray;
      }
    }
  }

}  // namespace extras
