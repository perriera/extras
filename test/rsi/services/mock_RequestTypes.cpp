#include <extras/rsi/services/RequestType.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/strings.hpp>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

//
// ss >> prg >> filename >> ip >> port;
//

SCENARIO("Mock RequestTypeInterface: types, request",
         "[RequestTypeInterface]") {
  const char* args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  PortNumber serverPort = 8080;
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortAuthority _portAuthority;
  rsi::RequestTypeList correctList;
  correctList.push_back("convert send.txt 127.0.0.1 9000");
  correctList.push_back("download send.txt 127.0.0.1 9001");
  rsi::RequestTypeCompilation c1(correctList);
  Mock<rsi::RequestTypeCompilerInterface> mock;
  When(Method(mock, compile))
      .AlwaysDo([&typesList, &correctList](
                    const rsi::SocketPoolParametersInterface& client,
                    PortAuthorityInterface& portAuthority) {
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
      });
  rsi::RequestTypeCompilerInterface& i = mock.get();
  REQUIRE(i.compile(client, _portAuthority) == c1);
  Verify(Method(mock, compile));
}

SCENARIO("Mock RequestTypeInterface: sockets", "[RequestTypeInterface]") {
  const char* args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  PortNumber serverPort = 8080;
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortAuthority _portAuthority;
  rsi::RequestTypeList correctList;
  correctList.push_back("convert send.txt 127.0.0.1 9000");
  correctList.push_back("download send.txt 127.0.0.1 9001");
  rsi::RequestTypeCompilation c1(correctList), c2;
  Mock<rsi::RequestTypeCompilationInterface> mock;
  std::string p;
  When(Method(mock, writeSocket)).AlwaysDo([&c1, &p](int socket) {
    std::stringstream ss;
    ss << c1;
    p = extras::replace_all(ss.str(), "\n", ";");
  });
  When(Method(mock, readSocket)).AlwaysDo([&c2, &p](int socket) {
    std::string line = extras::replace_all(p, ";", "\n");
    std::stringstream ss;
    ss << line;
    ss >> c2;
  });
  rsi::RequestTypeCompilationInterface& i = mock.get();
  REQUIRE(c1 != c2);
  i.writeSocket(1);
  i.readSocket(1);
  REQUIRE(c1 == c2);
  Verify(Method(mock, writeSocket));
  Verify(Method(mock, readSocket));
}
