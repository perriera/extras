#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
namespace fs = std::filesystem;

SCENARIO("Test UploaderInterface: upload", "[UploaderInterface]") {
  std::string target = "send_up.txt";
  if (fs::exists(target)) fs::remove(target);
  REQUIRE(fs::exists("send.txt"));
  REQUIRE(!fs::exists(target));
  system("build/uploader_server send_up.txt 127.0.0.1 9000 &");
  REQUIRE(system("build/uploader_client send.txt 127.0.0.1 9000") == 0);
  REQUIRE(fs::exists(target));
  REQUIRE(fs::exists("send.txt"));
  if (fs::exists(target)) fs::remove(target);
}

SCENARIO("Test UploaderInterface: download", "[UploaderInterface]") {
  std::string target = "send_down.txt";
  if (fs::exists(target)) fs::remove(target);
  REQUIRE(fs::exists("send.txt"));
  REQUIRE(!fs::exists(target));
  system("build/downloader_server send.txt 127.0.0.1 9000 &");
  REQUIRE(system("build/downloader_client send_down.txt 127.0.0.1 9000") == 0);
  REQUIRE(fs::exists(target));
  REQUIRE(fs::exists("send.txt"));
  if (fs::exists(target)) fs::remove(target);
}
