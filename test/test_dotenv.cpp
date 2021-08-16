#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/dotenv.hpp"

using namespace extras;

/**
 * @brief DotENV Unit Test
 *
 */
SCENARIO("Test DotENV", "[test_dotenv]") {
  /**
   * @brief No where near as exciting, (or interestig
   * as mock tests, the unit test gives us a chance
   * to prove that the expected behavior has found
   * its way into the implementation)
   *
   */
  DotENV dotENV;
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  DotENVLine(key, value);
  dotENV.put(DotENVLine(key, value));
  REQUIRE(dotENV.contains(key));
  REQUIRE(dotENV.value(key) == value);
}

SCENARIO("Test DotENV instance()", "[test_dotenv]") {
  /**
   * @brief In the case of a singleton being required
   * we make use of the interface instead of the class;
   * (Mind you, this really clutters the test case as
   * only one static instance can be tested, so we limit
   * the singleton test to one single test case).
   */
  DotENVInterface &instance = DotENV::instance();
  EnvironmentVariableKey key;
  EnvironmentVariableValue value;
  instance.put(DotENVLine(key, value));
  REQUIRE(instance.contains(key));
  REQUIRE(instance.value(key) == value);
}

SCENARIO("Test DotENV load token file", "[test_dotenv]") {
  /**
   * @brief In the case of a singleton being required
   * we make use of the interface instead of the class;
   * (Mind you, this really clutters the test case as
   * only one static instance can be tested, so we limit
   * the singleton test to one single test case).
   */

  extras::DotENV dotENV;
  std::stringstream ss;
  ss << "# FULL_SYNC accepted values [ on : off ]" << std::endl;
  ss << "FULL_SYNC=on" << std::endl;
  ss << "BEARER_TOKEN=skdfkusdgfiusdggsdkfjgsksfjsdgf" << std::endl;
  ss << "# LIBDMG_ENV accepted " << std::endl;
  ss << "LIBDMG_ENV=dev" << std::endl;
  ss << "NEW_TOKEN_ENDPOINT=https://dev-xyz-com//token" << std::endl;
  ss << "CLIENT_ID=sdkfhsdkhekuwhrfksdhgfkjsdgfjsdgf" << std::endl;
  ss << "CLIENT_SECRET=sfkjdhkusdghfkhgsjhdhgsdfsdfs" << std::endl;
  ss << "AUDIENCE=https://jackpot_pc_salmon" << std::endl;
  ss << "COOKIE=dskjfhksjdhdhfkjsdf-sdhfkjdsf-Q; " << std::endl;
  ss << "did_compatible=sdfssdf-sdfsddf-sdf-sdce-" << std::endl;
  ss >> dotENV;
}

// std::string DotEnvManager::tokenize(const std::string &line,
//   const std::string &var) const
// {
//   std::string dup = line;
//   std::size_t pos = 0;
//   std::string delimiter{ "=" };
//   while ((pos = dup.find(delimiter)) != std::string::npos) {
//     std::string token = dup.substr(0, pos);
//     if (token == var) {
//       dup.erase(0, pos + delimiter.length());
//       break;
//     }
//     dup.clear();
//   }
//   return dup;
// }

// // std::string DotEnvManager::tokenize(const std::string &line) const
// // {
// //   errors::BadEnvironmentVariable::assertion(line, __INFO__);
// //   std::deque<std::string> parts = extras::split(line, '=');
// //   return parts[1];
// // }

// std::string
//   DotEnvManager::loadEnvVar(const std::string &_var) const noexcept
// {
//   std::string activePath = utils::getdotenv();
//   std::ifstream envfile(activePath);
//   std::string line{};
//   while (std::getline(envfile, line)) {
//     if (line[0] == '#' || line[0] == ' ' || line[0] == '\n') {
//       continue;
//     }
//     std::string token = tokenize(line, _var);
//     if (!token.empty()) {
//       // this empty check is important
//       envfile.close();
//       return token;
//     }
//   }
//   return "";
// }
