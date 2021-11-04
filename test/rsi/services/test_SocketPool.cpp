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
  const char *args[] = {"127.0.0.1", "8080", "send.txt", "convert", "download"};
  extras::rsi::SocketPoolClient client;
  client.parameters(5, args);
  std::stringstream ss;
  // ss << client;
}
