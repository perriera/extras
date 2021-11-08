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
  const char* args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  PortNumber serverPort = 8080;
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortAuthority _portAuthority;
  rsi::RequestTypeList requestList;
  requestList.push_back("upload send.txt 127.0.0.1 9000");
  requestList.push_back("download send.txt 127.0.0.1 9001");
  rsi::RequestTypeCompilation c1(requestList);
  rsi::ServiceTypeList correctList;
  correctList.push_back("build/uploader_client send.txt 127.0.0.1 9000");
  correctList.push_back("build/downloader_client send.txt 127.0.0.1 9001");
  rsi::ServiceTypeMap serviceTypeMap;
  rsi::ServiceTypeList serviceList;
  serviceTypeMap["upload"] = "build/uploader_client";
  serviceTypeMap["download"] = "build/downloader_client";

  Mock<rsi::ServiceTypeCompilerInterface> mock;
  When(Method(mock, compile))
      .AlwaysDo([&serviceTypeMap,
                 &serviceList](const rsi::RequestTypeCompilation& requests) {
        rsi::ServiceTypeList list;
        for (auto request : requests.compilation()) {
          auto parts = extras::split(request, ' ');
          rsi::NoTokensException::assertion(parts.size(), __INFO__);
          auto serviceType = serviceTypeMap[parts[0]];
          rsi::UnsupportedTokenException::assertion(serviceType, __INFO__);
          std::string line =
              extras::replace_all(request, parts[0], serviceType);
          list.push_back(line);
        }
        return list;
      });

  rsi::ServiceTypeCompilerInterface& i = mock.get();
  //   REQUIRE_THROWS_AS(i.compile(c1), rsi::UnsupportedTokenException);
  REQUIRE(i.compile(c1) == correctList);
  Verify(Method(mock, compile));
}
