#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/services/RequestType.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/rsi/subsystem.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// virtual const Parameter &program() const pure;
// virtual const Parameter &ip() const pure;
// virtual const Parameter &port() const pure;
// virtual const Parameter &filename() const pure;
// virtual const SocketRequestTypeList &requests() const pure;

namespace extras {
  namespace rsi {

    /**
     * @brief concrete class SocketPoolClient
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    void SocketPoolClient::connect() {
      this->_client_socket =
          connect_to_server(ip().c_str(), stoi(port()), _server_addr);
    }

    void SocketPoolClient::close() const { ::close(this->_client_socket); }

    PortNumberPool SocketPoolClient::request(const PortNumber &,
                                             const SocketRequestTypeList &) {
      throw "not used";
    }

    void SocketPoolClient::transfer() const {
      try {
        std::string msg = *this;
        send_line(msg, this->_client_socket);
        RequestTypeCompilation compilation;
        compilation.readSocket(this->_client_socket);
        cout << "msg received: " << compilation << endl;
      } catch (exception &ex) {
        cout << ex.what() << endl;
      }
    }

    PortNumberPool SocketPoolClient::request() {
      return request(stoi(this->port()), this->requests());
    }

    SocketRequestTypeMap SocketPoolClient::startServices(
        const SocketRequestTypeMap &) const {
      throw "not used";
    }

  }  // namespace rsi
}  // namespace extras
