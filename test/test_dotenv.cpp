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

SCENARIO("Test DotENVLine", "[test_dotenv]") {
  /**
   * @brief In the case various formats in a
   * given environmental file, perform several
   * tests.
   */

  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "# FULL_SYNC accepted values [ on : off ]" << std::endl;
    REQUIRE_THROWS_AS(operator>>(ss, dotENVLine), DotENVLineKeyException);
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "FULL_SYNC=on" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "FULL_SYNC");
    REQUIRE(dotENVLine.value() == "on");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "BEARER_TOKEN=skdfkusdgfiusdggsdkfjgsksfjsdgf" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "BEARER_TOKEN");
    REQUIRE(dotENVLine.value() == "skdfkusdgfiusdggsdkfjgsksfjsdgf");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "# YOURAPPTOKEN accepted " << std::endl;
    REQUIRE_THROWS_AS(operator>>(ss, dotENVLine), DotENVLineKeyException);
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "NEW_TOKEN_ENDPOINT=https://dev-xyz-com//token" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "NEW_TOKEN_ENDPOINT");
    REQUIRE(dotENVLine.value() == "https://dev-xyz-com//token");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "CLIENT_ID=sdkfhsdkhekuwhrfksdhgfkjsdgfjsdgf" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "CLIENT_ID");
    REQUIRE(dotENVLine.value() == "sdkfhsdkhekuwhrfksdhgfkjsdgfjsdgf");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "CLIENT_SECRET=sfkjdhkusdghfkhgsjhdhgsdfsdfs" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "CLIENT_SECRET");
    REQUIRE(dotENVLine.value() == "sfkjdhkusdghfkhgsjhdhgsdfsdfs");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "AUDIENCE=https://jackpot_pc_salmon" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "AUDIENCE");
    REQUIRE(dotENVLine.value() == "https://jackpot_pc_salmon");
  }
  {
    extras::DotENVLine dotENVLine;
    std::stringstream ss;
    ss << "COOKIE=did_compatible=sdfs; df-sd fsddce-" << std::endl;
    ss >> dotENVLine;
    REQUIRE(dotENVLine.key() == "COOKIE");
    REQUIRE(dotENVLine.value() == "did_compatible=sdfs; df-sd fsddce-");
  }
}

SCENARIO("Test DotENV load token file", "[test_dotenv]") {
  /**
   * @brief The DotENVInterface handles a lot of the
   * common issues with formatting Unix/Linux style
   * parameters.
   */

  extras::DotENV dotENV;
  std::stringstream ss;
  ss << "# ASYNC accepted values [ on : off ]" << std::endl;
  ss << "ASYNC=on" << std::endl;
  ss << "YOURAPPTOKEN=dev" << std::endl;
  ss << "CLIENT_ID=sample_client_id" << std::endl;
  ss << "CLIENT_SECRET=34343-dfdfd-3343-fsfdf-334-sd" << std::endl;
  ss << "AUDIENCE=https://jackpot_pc_salmon" << std::endl;
  ss << "COOKIE=sample_cookie; ";
  ss << "did_compatible=sample_did_compatible" << std::endl;
  ss >> dotENV;
  std::stringstream test;
  std::stringstream ss2;
  ss2 << dotENV;
  extras::DotENV dotENV_compare;
  ss2 >> dotENV_compare;
  REQUIRE(dotENV == dotENV_compare);
  std::cout << dotENV_compare;
  REQUIRE(dotENV.value("YOURAPPTOKEN") == "dev");
}
