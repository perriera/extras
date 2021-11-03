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
