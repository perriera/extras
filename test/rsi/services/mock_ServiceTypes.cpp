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
  requestList.push_back("build/uploader_client send.txt 127.0.0.1 9000");
  requestList.push_back("build/downloader_client send.txt 127.0.0.1 9001");
  rsi::ServiceTypeMap serviceTypeMap;
  serviceTypeMap["upload"] = "build/uploader_client";
  serviceTypeMap["download"] = "build/downloader_client";
  rsi::ServiceTypeList serviceList;

  Mock<rsi::ServiceTypeCompilerInterface> mock;
  When(Method(mock, compile))
      .AlwaysDo([&serviceTypeMap,
                 &serviceList](const rsi::RequestTypeCompilation& requests) {
        rsi::ServiceTypeList list;
        for (auto request : requests.compilation()) {
                    //     if ()
          //   rsi::ServiceType line = extras::replace_all(request,);
          std::cout << request << std::endl;
          //   list.push_back(line);
        }
        return list;
      });

  rsi::ServiceTypeCompilerInterface& i = mock.get();
  REQUIRE(i.compile(c1) == correctList);
  Verify(Method(mock, compile));
}
