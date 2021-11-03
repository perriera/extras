#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/rsi/subsystem.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace extras {

  /**
   * @brief abstract class SocketPool
   *
   *   build/rsi_client 127.0.0.1 8080 transfer send.txt
   *   ss >> prg >> filename >> ip >> port;
   *
   */
  rsi::Parameters rsi::SocketPool::parameters(int argc, char const *argv[]) {
    if (argc < 4) {
      std::cout << "params: filename ip port" << std::endl;
      throw RSIException("params: filename ip port", __INFO__);
    }
    rsi::Parameters result;
    for (int i = 0; i < argc; i++) result.push_back(argv[i]);
    _parameters = result;
    return _parameters;
  }

  /**
   * @brief concrete class SocketPoolClient
   *
   *   build/rsi_client 127.0.0.1 8080 transfer send.txt
   *   ss >> prg >> filename >> ip >> port;
   *
   */

  rsi::PortNumberPool rsi::SocketPoolClient::request(
      const PortNumber &portNumber, const SocketRequestTypeList &requests){};
  rsi::SocketRequestTypeMap rsi::SocketPoolClient::startServices(
      const SocketRequestTypeMap &map) const {};

  /**
   * @brief concrete class SocketPoolServer
   *
   *   build/rsi_client 127.0.0.1 8080 transfer send.txt
   *   ss >> prg >> filename >> ip >> port;
   *
   */

  rsi::PortNumberPool rsi::SocketPoolServer::request(
      const PortNumber &portNumber, const SocketRequestTypeList &requests){};
  rsi::SocketRequestTypeMap rsi::SocketPoolServer::startServices(
      const SocketRequestTypeMap &map) const {};

}  // namespace extras
