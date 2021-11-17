#include <cstdint>
#include <extras/filesystem/system.hpp>
#include <extras/strings.hpp>
#include <fstream>

#include "../vendor/catch.hpp"

using namespace extras;

SCENARIO("Test SystemException", "[SystemException]") {
  std::string good_cmd = "ls -la";
  std::string bad_cmd = "lsxyz@ -la";
  SystemException::assertion(good_cmd, __INFO__);
  REQUIRE_THROWS_AS(SystemException::assertion(bad_cmd, __INFO__),
                    SystemException);
}

SCENARIO("Test ScriptException", "[SystemException]") {
  std::string good_cmd = "ls -la";
  std::string bad_cmd = "lsxyz@ -la";
  ScriptException::assertion(good_cmd, __INFO__);
  REQUIRE_THROWS_AS(ScriptException::assertion(bad_cmd, __INFO__),
                    ScriptException);
}