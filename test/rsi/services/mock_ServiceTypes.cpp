#include <extras/rsi/services/ServiceType.hpp>
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

SCENARIO("Test ServiceTypeCompilerInterface: types, request",
         "[ServiceTypeCompilerInterface]") {
  rsi::RequestTypeList requestTypeList;
  requestTypeList.push_back("convert send.txt 137.184.218.130 9104");
  requestTypeList.push_back("download send.txt 137.184.218.130 9105");
  rsi::RequestTypeList badRequestTypeList;
  badRequestTypeList.push_back("xoxoxo send.txt 137.184.218.130 9104");
  rsi::RequestTypeList noRequestTypeList;
  noRequestTypeList.push_back("");
  rsi::ServiceTypeList clients;
  clients.push_back("build/converter_client send.txt 137.184.218.130 9104");
  clients.push_back("build/downloader_client send.txt 137.184.218.130 9105");
  rsi::ServiceTypeList servers;
  servers.push_back("build/converter_server send.txt 137.184.218.130 9104");
  servers.push_back("build/downloader_server send.txt 137.184.218.130 9105");
  rsi::ServiceTypeMap forClients;
  forClients["convert"] = "build/converter_client";
  forClients["download"] = "build/downloader_client";
  rsi::ServiceTypeMap forServers;
  forServers["convert"] = "build/converter_server";
  forServers["download"] = "build/downloader_server";

  Mock<rsi::ServiceTypeCompilerInterface> mock;
  When(Method(mock, clients))
      .AlwaysDo([&forClients](const rsi::RequestTypeList& requests) {
        rsi::ServiceTypeList list;
        for (auto request : requests) {
          auto parts = extras::split(request, ' ');
          rsi::NoTokensException::assertion(parts.size(), __INFO__);
          auto serviceType = forClients[parts[0]];
          rsi::UnsupportedTokenException::assertion(serviceType, __INFO__);
          std::string line =
              extras::replace_all(request, parts[0], serviceType);
          list.push_back(line);
        }
        return list;
      });

  When(Method(mock, servers))
      .AlwaysDo([&forServers](const rsi::RequestTypeList& requests) {
        rsi::ServiceTypeList list;
        for (auto request : requests) {
          auto parts = extras::split(request, ' ');
          rsi::NoTokensException::assertion(parts.size(), __INFO__);
          auto serviceType = forServers[parts[0]];
          rsi::UnsupportedTokenException::assertion(serviceType, __INFO__);
          std::string line =
              extras::replace_all(request, parts[0], serviceType);
          list.push_back(line);
        }
        return list;
      });

  rsi::ServiceTypeCompilerInterface& i = mock.get();
  REQUIRE(i.clients(requestTypeList) == clients);
  REQUIRE(i.servers(requestTypeList) == servers);
  REQUIRE_THROWS_AS(i.clients(badRequestTypeList),
                    rsi::UnsupportedTokenException);
  REQUIRE_THROWS_AS(i.clients(noRequestTypeList), rsi::NoTokensException);
  REQUIRE_THROWS_AS(i.servers(badRequestTypeList),
                    rsi::UnsupportedTokenException);
  REQUIRE_THROWS_AS(i.servers(noRequestTypeList), rsi::NoTokensException);
  Verify(Method(mock, clients));
  Verify(Method(mock, servers));
}
