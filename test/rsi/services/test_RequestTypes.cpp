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

SCENARIO("Test RequestTypeInterface: types, request",
         "[RequestTypeInterface]") {
  const char* args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortAuthority _portAuthority;
  rsi::RequestTypeList correctList;
  correctList.push_back("convert send.txt 127.0.0.1 9000");
  correctList.push_back("download send.txt 127.0.0.1 9001");
  rsi::RequestTypeCompilation c1(correctList);

  rsi::RequestTypeCompiler compiler;

  REQUIRE(compiler.compile(client, _portAuthority) == c1);
}

SCENARIO("Test RequestTypeInterface: streams", "[RequestTypeInterface]") {
  const char* args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  rsi::SocketRequestTypeList typesList = {"upload", "process", "download"};
  rsi::SocketRequestTypeList requestsList = {"upload", "download"};
  PortAuthority _portAuthority;
  rsi::RequestTypeList correctList;
  correctList.push_back("convert send.txt 127.0.0.1 9000");
  correctList.push_back("download send.txt 127.0.0.1 9001");
  rsi::RequestTypeCompilation c1(correctList);

  std::stringstream ss;
  ss << c1;
  rsi::RequestTypeCompilation c2;
  ss >> c2;

  REQUIRE(c1 == c2);
}
