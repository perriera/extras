#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
namespace fs = std::filesystem;

// SCENARIO("Test SocketPoolInterface: upload", "[SocketPoolInterface]") {
//   std::string target = "send_up.txt";
//   if (fs::exists(target)) fs::remove(target);
//   REQUIRE(fs::exists("send.txt"));
//   REQUIRE(!fs::exists(target));
//   system("build/socket_client send_up.txt 127.0.0.1 9002 &");
//   REQUIRE(system("build/socket_server send.txt 127.0.0.1 9002") == 0);
//   REQUIRE(fs::exists(target));
//   REQUIRE(fs::exists("send.txt"));
//   if (fs::exists(target)) fs::remove(target);
// }
