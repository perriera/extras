#include <cstdint>
#include <extras/filesystem/system.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

#include "../vendor/catch.hpp"

using namespace extras;

SCENARIO("Test SystemException", "[SystemException]") {
  std::string good_cmd = "ls -la";
  std::string bad_cmd = "lsxyz@ -la";
  SystemException::assertion(good_cmd, __INFO__);
  REQUIRE_THROWS_AS(SystemException::assertion(bad_cmd, __INFO__),
                    SystemException);
}

SCENARIO("Test ScriptException 2", "[SystemException]") {
  std::string good_script = "./good_script.sh";
  {
    std::ofstream out(good_script);
    out << "ls -la" << std::endl;
  }
  std::string bad_script = "./bad_script.sh";
  {
    std::ofstream out(bad_script);
    out << "lsxyz@ -la" << std::endl;
  }
  std::cout << "cock sucking jesus" << std::endl;
}