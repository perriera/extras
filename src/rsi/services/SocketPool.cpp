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

    std::ostream &operator<<(std::ostream &out, const StartedServices &obj) {
      out << obj._map.size() << ' ';
      for (auto item : obj._map) {
        out << item.first << ' ' << item.second << ' ';
      }
      return out;
    }
    std::istream &operator>>(std::istream &in, StartedServices &obj) {
      int items = 0;
      in >> items;
      while (items-- > 0 && in.good()) {
        int port;
        string request;
        in >> port >> request;
        obj._map[port] = request;
      }
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
      this->_sockfd =
          connect_to_server(ip().c_str(), stoi(port()), _server_addr);
    }

    void SocketPoolClient::close() const { ::close(this->_sockfd); }

    SocketRequestTypeMap SocketPoolClient::request(
        const PortNumber &, const SocketRequestTypeList &) {
      return SocketRequestTypeMap();
    }

    /**
     * @brief transfer()
     * @note prepare requests to be sent the server
     *
     */
    void SocketPoolClient::transfer() {
      try {
        send_line(*this, this->_sockfd);
        string msg;
        while (msg.size() == 0) msg = read_line(this->_sockfd);
        StartedServices ss(msg);
      } catch (RSIRemoteException &ex) {
      } catch (RSIException &ex) {
      } catch (exception &ex) {
      }
    }

    /**
     * @brief transfer()
     * @note prepare requests to be recieved from the server
     *
     */
    void SocketPoolServer::transfer() {
      try {
        string msg;
        while (msg.size() == 0) msg = read_line(this->_new_sock);
        SocketPoolClient client(msg);
        cout << "msg received: " << client << endl;
        SocketRequestTypeList theserequests = client.requests();
        auto pool = request(stoi(this->port()), theserequests);
        auto services = startServices(pool);
        send_line(services, this->_sockfd);
      } catch (RSIRemoteException &ex) {
      } catch (RSIException &ex) {
      } catch (exception &ex) {
      }
    }

    /**
     * @brief request()
     * @note
     *
     * @param portNumber
     * @param requests
     * @return PortNumberPool
     */
    SocketRequestTypeMap SocketPoolServer::request(
        const PortNumber &, const SocketRequestTypeList &requests) {
      PortNumberPool ports;
      SocketRequestTypeMap map;
      for (auto request : requests) {
        bool found = false;
        for (auto type : this->types()) {
          if (request == type) {
            map[_nextPortNumber++] = request;
            found = true;
          }
        }
        if (!found) throw UnsupportedTokenException(request, __INFO__);
      }
      return map;
    }

    StartedServices SocketPoolServer::startServices(
        const SocketRequestTypeMap &) const {
      return StartedServices();
    }

    // SocketRequestTypeMap SocketPoolClient::request() {
    //   return request(stoi(this->port()), this->requests());
    // }

    // SocketRequestTypeMap SocketPoolServer::request() {
    //   return request(stoi(this->port()), this->requests());
    // }

    StartedServices SocketPoolClient::startServices(
        const SocketRequestTypeMap &) const {
      return StartedServices();
    }

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

  }  // namespace rsi
}  // namespace extras
