#include <extras/rsi/services/SocketPool.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>
#include <sstream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
namespace fs = std::filesystem;

SCENARIO("Test SocketPoolInterface: upload", "[SocketPoolInterface]") {
  const char *args[] = {"socketclient", "127.0.0.1", "8080",
                        "send.txt",     "convert",   "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(6, args);
  REQUIRE(client.program() == args[0]);
  REQUIRE(client.ip() == args[1]);
  REQUIRE(client.port() == args[2]);
  REQUIRE(client.filename() == args[3]);
  rsi::SocketRequestTypeList list = {args[4], args[5]};
  REQUIRE(client.requests() == list);
  std::stringstream ss;
  ss << client;
  std::string test = ss.str();
  extras::rsi::SocketPoolClient client2;
  std::stringstream ss2;
  ss2 << test;
  ss2 >> client2;
  REQUIRE(client == client2);
  extras::rsi::SocketPoolClient client3;
  REQUIRE(client != client3);
}
