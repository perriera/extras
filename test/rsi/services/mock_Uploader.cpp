#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
using namespace fakeit;

//
// ss >> prg >> filename >> ip >> port;
//

SCENARIO("Mock UploaderInterface: parameters", "[UploaderInterface]") {
  rsi::Parameter program = "build/rsi_client";
  rsi::Parameter filename = "send.txt";
  rsi::Parameter ip = "159.223.103.27";
  rsi::Parameter port = "8080";
  int socket = 5;
  const char* argv[] = {program.c_str(), filename.c_str(), ip.c_str(),
                        port.c_str()};
  int argc = 4;
  Mock<rsi::UploaderInterface> mock;
  When(Method(mock, parameters)).AlwaysDo([](int argc, char const* argv[]) {
    rsi::Parameters result;
    for (int i = 0; i < argc; i++) result.push_back(argv[i]);
    return result;
  });
  When(Method(mock, program)).Return(program);
  When(Method(mock, filename)).Return(filename);
  When(Method(mock, ip)).Return(ip);
  When(Method(mock, port)).Return(port);
  When(Method(mock, socket)).Return(socket);
  When(Method(mock, send_file)).Return();
  When(Method(mock, close)).Return();

  rsi::UploaderInterface& i = mock.get();
  REQUIRE(i.parameters(argc, argv).size() == argc);
  REQUIRE(i.program() == program);
  REQUIRE(i.ip() == ip);
  REQUIRE(i.port() == port);
  REQUIRE(i.socket() == socket);
  i.send_file();
  i.close();
  Verify(Method(mock, parameters));
  Verify(Method(mock, program));
  Verify(Method(mock, ip));
  Verify(Method(mock, port));
  Verify(Method(mock, socket));
  Verify(Method(mock, send_file));
  Verify(Method(mock, close));
}
