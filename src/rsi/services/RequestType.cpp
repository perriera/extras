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

    std::ostream &operator<<(std::ostream &out,
                             const RequestTypeCompilationInterface &obj) {
      RequestTypeList list = obj.compilation();
      out << list.size() << endl;
      for (auto line : list) {
        out << line << endl;
      }
      return out;
    }

    std::istream &operator>>(std::istream &in,
                             RequestTypeCompilationInterface &obj) {
      int size = 0;
      in >> size;
      RequestType line;
      getline(in, line);
      RequestTypeList list;
      while (size-- > 0 && in.good()) {
        RequestType line;
        getline(in, line);
        if (in.good()) list.push_back(line);
      }
      obj.setCompilation(list);
      return in;
    }

    void RequestTypeCompilation::writeSocket(int socket) const {}
    void RequestTypeCompilation::readSocket(int socket) {}

    RequestTypeCompilation RequestTypeCompiler::compile(
        const SocketPoolParametersInterface &client,
        PortAuthorityInterface &portAuthority) const {
      rsi::RequestTypeList list;
      for (auto request : client.requests()) {
        auto port = portAuthority.request();
        std::stringstream ss;
        ss << request << ' ';
        ss << client.filename() << ' ';
        ss << client.ip() << ' ';
        ss << port;
        std::string line = ss.str();
        list.push_back(line);
      }
      return rsi::RequestTypeCompilation(list);
    }

  }  // namespace rsi
}  // namespace extras
