#include <extras/rsi/requests.hpp>
#include <extras/rsi/subsystems.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

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

  void RSIServerImp::send_line(const std::string& request,
                               int serverSocket) const {
    extras::rsi::send_line(request, serverSocket);
  }

  std::string RSIServerImp::read_line(int serverSocket) {
    return extras::rsi::read_line(serverSocket);
  }

  void RSIClientImp::send_line(const std::string& request,
                               int serverSocket) const {
    extras::rsi::send_line(request, serverSocket);
  }

  std::string RSIClientImp::read_line(int serverSocket) {
    return extras::rsi::read_line(serverSocket);
  }

  void RSIServerImp::request(RSIInterface& requestedService,
                             const PortServerNumber& serverSocket) {
    string request = read_line(serverSocket);
    stringstream ss_in;
    ss_in << request;
    ss_in >> requestedService;
    int _nextAvailablePort = _portAuthority.request();
    requestedService.setPort(_nextAvailablePort);
    stringstream ss_out;
    ss_out << requestedService;
    string response = ss_out.str();
    system(requestedService.server().c_str());
    send_line(response, serverSocket);
  }

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
