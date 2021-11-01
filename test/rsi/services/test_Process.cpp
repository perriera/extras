#include <extras/rsi/services/Process.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
namespace fs = std::filesystem;

SCENARIO("Test ProcessInterface", "[ProcessInterface]") {
  std::string target = "send_up.txt";
  if (fs::exists(target)) fs::remove(target);
  REQUIRE(fs::exists("send.txt"));
  REQUIRE(!fs::exists(target));
  system("build/process_server send_up.txt 127.0.0.1 9001 &");
  REQUIRE(system("build/process_client send.txt 127.0.0.1 9001") == 0);
  REQUIRE(fs::exists(target));
  REQUIRE(fs::exists("send.txt"));
  if (fs::exists(target)) fs::remove(target);
}
