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

SCENARIO("Mock ServerInterface: types, request", "[SocketPoolInterface]") {
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