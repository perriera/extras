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
            rsi::SocketRequestTypeMap map;
            for (auto request : requests)
              for (auto type : typesList)
                if (request == type) map[nextPortNumber++] = request;
            return map;
          });
  rsi::SocketPoolInterface& i = mock.get();
  REQUIRE(i.types() == typesList);
  REQUIRE(i.request(serverPort, requestsList).size() == 2);
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
            rsi::SocketRequestTypeMap map;
            for (auto request : requests) {
              bool found = false;
              for (auto type : typesList) {
                if (request == type) {
                  map[nextPortNumber++] = request;
                  found = true;
                }
              }
              if (!found)
                throw rsi::UnsupportedTokenException(request, __INFO__);
            }
            return map;
          });
  // When(Method(mock, lastRequest)).AlwaysDo([&lastRequestsMap]() {
  //   return lastRequestsMap;
  // });
  When(Method(mock, startServices))
      .AlwaysDo([&typesList](const rsi::SocketRequestTypeMap& map) {
        return rsi::StartedServices();
      });
  rsi::SocketPoolInterface& i = mock.get();
  REQUIRE(i.types() == typesList);
  auto list = i.request(serverPort, requestsList);
  REQUIRE(list.size() == 2);
  REQUIRE_THROWS_AS(i.request(serverPort, badRequestsList),
                    rsi::UnsupportedTokenException);
  // auto latestRequestsMap = i.lastRequest();
  i.startServices(list);
  Verify(Method(mock, types));
  Verify(Method(mock, request));
  // Verify(Method(mock, lastRequest));
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

SCENARIO("Mock SocketPoolClientInterface", "[SocketPoolInterface]") {
  Mock<rsi::SocketPoolClientInterface> mock;
  When(Method(mock, connect)).Return();
  When(Method(mock, close)).Return();
  rsi::SocketPoolClientInterface& i = mock.get();
  i.connect();
  i.close();
  Verify(Method(mock, connect));
  Verify(Method(mock, close));
}

SCENARIO("Mock SocketPoolServerInterface", "[SocketPoolInterface]") {
  Mock<rsi::SocketPoolServerInterface> mock;
  When(Method(mock, accept)).Return();
  When(Method(mock, close)).Return();
  rsi::SocketPoolServerInterface& i = mock.get();
  i.accept();
  i.close();
  Verify(Method(mock, accept));
  Verify(Method(mock, close));
}

SCENARIO("Mock SocketPoolInterface: startServices2", "[SocketPoolInterface]") {
  Mock<rsi::SocketPoolInterface> mock;
  When(Method(mock, startServices))
      .AlwaysDo([](const rsi::SocketRequestTypeMap& map) {
        return rsi::StartedServices();
      });
  rsi::SocketPoolInterface& i = mock.get();
  rsi::SocketRequestTypeMap map;
  i.startServices(map);
  Verify(Method(mock, startServices));
}

SCENARIO("Mock SocketPoolInterface: startServices3", "[SocketPoolInterface]") {
  Mock<rsi::SocketPoolInterface> mock;
  When(Method(mock, startServices))
      .AlwaysDo([](const rsi::SocketRequestTypeMap& map) {
        return rsi::StartedServices();
      });
  rsi::SocketPoolInterface& i = mock.get();
  rsi::SocketRequestTypeMap map;
  map[9000] = "upload";
  map[9001] = "process";
  map[9002] = "download";
  i.startServices(map);
  Verify(Method(mock, startServices));
}

SCENARIO("Mock SocketPoolInterface: StartedServices", "[SocketPoolInterface]") {
  Mock<rsi::SocketPoolInterface> mock;
  When(Method(mock, startServices))
      .AlwaysDo([](const rsi::SocketRequestTypeMap& map) {
        rsi::StartedServices ss;
        ss.setStartedServices(map);
        return ss;
      });
  rsi::SocketPoolInterface& i = mock.get();
  rsi::SocketRequestTypeMap map;
  map[9000] = "upload";
  map[9001] = "process";
  map[9002] = "download";
  auto list = i.startServices(map);
  REQUIRE(list.startedServices().size() == 3);
  std::stringstream ss;
  ss << list;
  rsi::StartedServices list2, list3;
  ss >> list2;
  REQUIRE(list == list2);
  REQUIRE(list != list3);
  Verify(Method(mock, startServices));
}