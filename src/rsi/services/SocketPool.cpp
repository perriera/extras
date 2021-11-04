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
  namespace rsi {
    std::ostream &operator<<(std::ostream &out, const SocketPoolClient &obj) {
      return out;
    }
    std::istream &operator>>(std::istream &in, SocketPoolClient &obj) {
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
      Parameters result;
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
    void SocketPoolClient::connect() {
      this->_sockfd =
          connect_to_server(ip().c_str(), stoi(port()), _server_addr);
    }

    void SocketPoolClient::close() const { ::close(this->_sockfd); }

    PortNumberPool SocketPoolClient::request(
        const PortNumber &portNumber, const SocketRequestTypeList &requests){};

    void SocketPoolClient::transfer() const {
      string msg = "hello";
      send_line(msg, this->_sockfd);
    };

    void SocketPoolServer::transfer() const {
      string msg;
      while (msg.size() == 0) msg = read_line(this->_new_sock);
      std::cout << msg << std::endl;
      // char buffer[1024] = {0};
      // int valread = read(new_socket, buffer, 1024);
      // if (valread < 0) {
      //   perror("listen");
      //   exit(EXIT_FAILURE);
      // }
      // printf("%s\n", buffer);
    };

    PortNumberPool SocketPoolClient::request() {
      return request(stoi(this->port()), this->requests());
    };

    PortNumberPool SocketPoolServer::request() {
      return request(stoi(this->port()), this->requests());
    };
    SocketRequestTypeMap SocketPoolClient::startServices(
        const SocketRequestTypeMap &map) const {};

    /**
     * @brief concrete class SocketPoolServer
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    void SocketPoolServer::connect() {
      this->_sockfd =
          configure_serversocket(ip().c_str(), stoi(port()), _server_addr);
      if (this->_sockfd == -1) {
        ::close(this->_sockfd);
        throw RSIException("Timeout on uploader_server accept", __INFO__);
      }
    }

    void SocketPoolServer::accept() {
      socklen_t addr_size = sizeof(_new_addr);
      this->_new_sock =
          ::accept(this->_sockfd, (struct sockaddr *)&_new_addr, &addr_size);
      if (_new_sock == -1) {
        ::close(this->_sockfd);
        throw RSIException("Timeout on uploader_server accept", __INFO__);
      }
    }

    void SocketPoolServer::close() const {
      ::close(this->_new_sock);
      ::close(this->_sockfd);
    }

    PortNumberPool SocketPoolServer::request(
        const PortNumber &portNumber, const SocketRequestTypeList &requests) {
      PortNumberPool ports;
      SocketRequestTypeMap lastRequestsMap;
      for (auto request : requests) {
        bool found = false;
        for (auto type : this->types()) {
          if (request == type) {
            lastRequestsMap[_nextPortNumber] = request;
            ports.push_back(_nextPortNumber++);
            found = true;
          }
        }
        if (!found) throw UnsupportedTokenException(request, __INFO__);
      }
      return ports;
    };
    SocketRequestTypeMap SocketPoolServer::startServices(
        const SocketRequestTypeMap &map) const {};
  }  // namespace rsi
}  // namespace extras
