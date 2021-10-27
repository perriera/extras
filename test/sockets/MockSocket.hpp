
#ifndef __MOCKSOCKET_HPP
#define __MOCKSOCKET_HPP

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

using namespace extras;
namespace fs = std::filesystem;

struct MockSocket implements SocketInterface {
  HexArray& _packets;
  HexArray _localEcho;
  HexLine _nextLine;
  HexArray _sent;
  HexArray _recieved;
  int _next = 0;

  MockSocket(HexArray& packets) : _packets(packets) {}

  virtual void send(const std::string& msg) {
    _packets.push_back(msg);
    _sent.push_back(msg);
  };
  virtual SocketInterface& read(int) {
    _nextLine = _packets.front();
    _localEcho.push_back(_nextLine);
    _packets.erase(_packets.begin());
    _recieved.push_back(_nextLine);
    return *this;
  };
  virtual operator std::string() const { return _nextLine; };
  virtual operator SocketPacket() const { return SocketPacket(); };
  const HexArray& localEcho() { return _localEcho; }
  void reload(const HexArray& localEcho) {
    _packets = localEcho;
    std::cout << _packets.size() << std::endl;
  }
};

struct MockServer extends MockSocket {
  HexArray _processed;
  MockServer(HexArray& packets) : MockSocket(packets){};
  void processData() { _processed = _recieved; }
};

struct MockClient extends MockSocket {
  HexArray _processed;
  MockClient(HexArray& packets) : MockSocket(packets){};
  void processData() { _processed = _recieved; }
};

#endif  // __MOCKSOCKET_HPP