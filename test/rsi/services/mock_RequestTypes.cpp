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
  Mock<rsi::RequestTypeCompilerInterface> mock;
  When(Method(mock, compile))
      .AlwaysDo([&typesList, &correctList](
                    const rsi::SocketPoolClientInterface& client,
                    PortAuthorityInterface& portAuthority) {
        rsi::PortNumberPool ports;
        // for (auto request : requests)
        //   for (auto type : typesList)
        //     if (request == type) ports.push_back(nextPortNumber++);
        return correctList;
      });
  rsi::RequestTypeCompilerInterface& i = mock.get();
  REQUIRE(i.compile(client, _portAuthority) == correctList);
  Verify(Method(mock, compile));
}
