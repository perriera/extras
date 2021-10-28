#include <extras/uploader/UploaderInterface.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

#include "extras/rsi/RSIInterface.hpp"

using namespace std;

namespace extras {

  // 'build/uploader_client send.txt 159.223.103.27 9010 &'
  std::ostream& operator<<(std::ostream& out, const RSIInterface& obj) {
    stringstream ss;
    ss << obj.service() << ' ' << obj.filename() << ' ' << obj.ip() << ' ';
    ss << obj.port() << ' ' << (obj.async() ? '&' : '.');
    string test = ss.str();
    out << test;
    return out;
  }
  std::istream& operator>>(std::istream& in, RSIInterface& obj) {
    string service, filename, ip, port, async;
    in >> service >> filename >> ip >> port >> async;
    obj.setService(service);
    obj.setFilename(filename);
    obj.setIP(ip);
    obj.setPort(stoi(port));
    obj.setAsync(async == "&");
    return in;
  }

  const RSIInterface& RSI::request(const RSIInterface& request,
                                   const PortServerNumber& serverSocket) {
    return request;
  }

  void RSIServerImp::request(RSIInterface& requestedService,
                             const PortServerNumber& serverSocket) {}

  std::string RSIServerImp::send_line(const std::string& request,
                                      int serverSocket) const {};
  std::string RSIServerImp::read_line(int serverSocket) {}

  std::string RSIClientImp::send_line(const std::string& request,
                                      int serverSocket) const {};
  std::string RSIClientImp::read_line(int serverSocket) {}

  void RSIClientImp::request(RSIInterface& requestedService,
                             const PortServerNumber& serverSocket) {
    stringstream ss_in;
    ss_in << requestedService;
    string request = ss_in.str();
    send_line(request, serverSocket);
    string response = read_line(serverSocket);
    stringstream ss_out;
    ss_out << response;
    ss_out >> requestedService;
  }

}  // namespace extras
