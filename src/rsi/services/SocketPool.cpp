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
     * @brief SocketPoolParametersInterface ostream
     *
     * @param out
     * @param obj
     * @return std::ostream&
     */

    std::ostream &operator<<(std::ostream &out,
                             const SocketPoolParametersInterface &obj) {
      out << obj.program() << ' ';
      out << obj.ip() << ' ';
      out << obj.port() << ' ';
      out << obj.filename() << ' ';
      for (auto request : obj.requests()) out << request << ' ';
      return out;
    }

    /**
     * @brief SocketPoolParametersInterface istream
     *
     * @param in
     * @param obj
     * @return std::istream&
     */
    std::istream &operator>>(std::istream &in,
                             SocketPoolParametersInterface &obj) {
      std::string program, ip, port, filename, request;
      in >> program >> ip >> port >> filename;
      SocketRequestTypeList requests;
      while (in.good()) {
        in >> request;
        if (in.good()) requests.push_back(request);
      }
      obj.setProgram(program);
      obj.setIP(ip);
      obj.setPort(stoi(port));
      obj.setFilename(filename);
      obj.setRequests(requests);
      return in;
    }
    /**
     * @brief abstract class SocketPool
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    Parameters SocketPool::parameters(int argc, char const *argv[]) {
      if (argc < 4) {
        std::cout << "params: filename ip port" << std::endl;
        throw RSIException("params: filename ip port", __INFO__);
      }
      Parameters copy;
      std::stringstream ss;
      for (int i = 0; i < argc; i++) {
        ss << argv[i] << ' ';
        copy.push_back(argv[i]);
      }
      ss >> *this;
      return copy;
    }

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

    void SocketPoolServer::transfer() const {
      try {
        string msg;
        while (msg.size() == 0) msg = read_line(this->_client_socket);
        if (msg.size() == 0) throw std::string("test exception");
        SocketPoolClient client(msg);
        cout << "msg received: " << client << endl;
        RequestTypeCompiler compiler;
        auto compilation = compiler.compile(client);
        compilation.writeSocket(this->_client_socket);
      } catch (exception &ex) {
        cout << ex.what() << endl;
        send_line(ex.what(), this->_client_socket);
      } catch (...) {
        send_line("Unknown exception thrown", this->_client_socket);
      }
    }

    PortNumberPool SocketPoolClient::request() {
      return request(stoi(this->port()), this->requests());
    }

    PortNumberPool SocketPoolServer::request() {
      return request(stoi(this->port()), this->requests());
    }
    SocketRequestTypeMap SocketPoolClient::startServices(
        const SocketRequestTypeMap &) const {
      throw "not used";
    }

    /**
     * @brief concrete class SocketPoolServer
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    void SocketPoolServer::connect() {
      this->_server_socket = configure_serversocket(ip().c_str(), stoi(port()),
                                                    _server_addr, false);
      if (this->_server_socket == -1) {
        ::close(this->_server_socket);
        throw RSIException("Timeout on uploader_server accept", __INFO__);
      }
    }

    void SocketPoolServer::accept() {
      socklen_t addr_size = sizeof(_new_addr);
      this->_client_socket = ::accept(
          this->_server_socket, (struct sockaddr *)&_new_addr, &addr_size);
      if (_client_socket == -1) {
        ::close(this->_server_socket);
        throw RSIException("Timeout on uploader_server accept", __INFO__);
      }
    }

    void SocketPoolServer::close() const {
      ::close(this->_client_socket);
      ::close(this->_server_socket);
    }

    PortNumberPool SocketPoolServer::request(
        const PortNumber &, const SocketRequestTypeList &requests) {
      PortNumberPool ports;
      SocketRequestTypeMap lastRequestsMap;
      for (auto request : requests) {
        bool found = false;
        for (auto type : this->types()) {
          if (request == type) {
            int _nextPortNumber = this->portAuthority().request();
            lastRequestsMap[_nextPortNumber] = request;
            ports.push_back(_nextPortNumber);
            found = true;
          }
        }
        if (!found) throw UnsupportedTokenException(request, __INFO__);
      }
      return ports;
    }
    SocketRequestTypeMap SocketPoolServer::startServices(
        const SocketRequestTypeMap &) const {
      throw "not used";
    }
  }  // namespace rsi
}  // namespace extras
