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

SCENARIO("Mock SocketPoolInterface: types, request", "[SocketPoolInterface]") {
  PortNumber serverPort = 8080;
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortNumber nextPortNumber = 9000;
  rsi::PortNumberPool correctList = {9000, 9001};
  Mock<rsi::SocketPoolInterface> mock;
  When(Method(mock, types)).AlwaysDo([&typesList]() { return typesList; });
  When(Method(mock, request))
      .AlwaysDo(
          [&typesList, &nextPortNumber](
              const PortNumber&, const rsi::SocketRequestTypeList& requests) {
            rsi::PortNumberPool ports;
            for (auto request : requests)
              for (auto type : typesList)
                if (request == type) ports.push_back(nextPortNumber++);
            return ports;
          });
  rsi::SocketPoolInterface& i = mock.get();
  REQUIRE(i.types() == typesList);
  REQUIRE(i.request(serverPort, requestsList) == correctList);
  Verify(Method(mock, types));
  Verify(Method(mock, request));
}

SCENARIO("Mock SocketPoolInterface: startServices", "[SocketPoolInterface]") {
  PortNumber serverPort = 8080;
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  rsi::SocketRequestTypeList badRequestsList = {"upload", "apples"};
  PortNumber nextPortNumber = 9000;
  rsi::PortNumberPool correctList = {9000, 9001};
  rsi::SocketRequestTypeMap lastRequestsMap;
  Mock<rsi::SocketPoolInterface> mock;
  When(Method(mock, types)).AlwaysDo([&typesList]() { return typesList; });
  When(Method(mock, request))
      .AlwaysDo(
          [&typesList, &nextPortNumber, &lastRequestsMap](
              const PortNumber&, const rsi::SocketRequestTypeList& requests) {
            rsi::PortNumberPool ports;
            for (auto request : requests) {
              bool found = false;
              for (auto type : typesList) {
                if (request == type) {
                  lastRequestsMap[nextPortNumber] = request;
                  ports.push_back(nextPortNumber++);
                  found = true;
                }
              }
              if (!found)
                throw rsi::UnsupportedTokenException(request, __INFO__);
            }
            return ports;
          });
  When(Method(mock, lastRequest)).AlwaysDo([&lastRequestsMap]() {
    return lastRequestsMap;
  });
  When(Method(mock, startServices))
      .AlwaysDo(
          [&typesList](const rsi::SocketRequestTypeMap& map) { return map; });
  rsi::SocketPoolInterface& i = mock.get();
  REQUIRE(i.types() == typesList);
  auto list = i.request(serverPort, requestsList);
  REQUIRE(list == correctList);
  REQUIRE_THROWS_AS(i.request(serverPort, badRequestsList),
                    rsi::UnsupportedTokenException);
  auto latestRequestsMap = i.lastRequest();
  REQUIRE(i.startServices(latestRequestsMap) == latestRequestsMap);
  Verify(Method(mock, types));
  Verify(Method(mock, request));
  Verify(Method(mock, lastRequest));
  Verify(Method(mock, startServices));
}

SCENARIO("Mock SocketPoolParametersInterface", "[SocketPoolInterface]") {
  PortNumber serverPort = 8080;
  rsi::Parameter program = "build/rsi_client";
  rsi::Parameter filename = "send.txt";
  rsi::Parameter ip = "159.223.103.27";
  rsi::Parameter port = "8080";
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  const char* argv[] = {
      program.c_str(), filename.c_str(),        ip.c_str(),
      port.c_str(),    requestsList[0].c_str(), requestsList[1].c_str()};
  int argc = 4;
  Mock<rsi::SocketPoolParametersInterface> mock;
  When(Method(mock, parameters)).AlwaysDo([](int argc, char const* argv[]) {
    rsi::Parameters result;
    for (int i = 0; i < argc; i++) result.push_back(argv[i]);
    return result;
  });
  When(Method(mock, program)).Return(program);
  When(Method(mock, filename)).Return(filename);
  When(Method(mock, ip)).Return(ip);
  When(Method(mock, port)).Return(port);
  When(Method(mock, requests)).Return(requestsList);
  rsi::SocketPoolParametersInterface& i = mock.get();
  REQUIRE(i.parameters(argc, argv).size() == argc);
  REQUIRE(i.program() == program);
  REQUIRE(i.ip() == ip);
  REQUIRE(i.port() == port);
  REQUIRE(i.requests() == requestsList);
  Verify(Method(mock, parameters));
  Verify(Method(mock, program));
  Verify(Method(mock, ip));
  Verify(Method(mock, port));
  Verify(Method(mock, requests));
}