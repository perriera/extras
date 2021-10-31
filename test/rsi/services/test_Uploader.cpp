#include <extras/rsi/services/Uploader.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

#include "../../vendor/catch.hpp"
#include "../../vendor/fakeit.hpp"

using namespace extras;
namespace fs = std::filesystem;

SCENARIO("Test UploaderInterface", "[UploaderInterface]") {
  std::string target = "send_downloaded.txt";
  if (fs::exists(target)) fs::remove(target);
  REQUIRE(fs::exists("send.txt"));
  REQUIRE(!fs::exists("send_downloaded.txt"));
  system("build/uploader_server send_downloaded.txt 127.0.0.1 9000 &");
  system("build/uploader_client send.txt 127.0.0.1 9000");
  REQUIRE(fs::exists("send_downloaded.txt"));
  REQUIRE(fs::exists("send.txt"));
  if (fs::exists(target)) fs::remove(target);
}
