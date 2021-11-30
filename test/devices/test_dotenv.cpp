/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * The above copyright notice and  this permission  notice shall be
 * included in all copies or  substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESSED  OR   IMPLIED,  INCLUDING   BUT  NOT  LIMITED  TO  THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE  EXPARX  INCORPORATED
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM, OUT  OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Except  as  contained  in this  notice, the  name of  the EXPARX
 * INCORPORATED shall not  be used in  advertising or  otherwise to
 * promote the sale, use or other dealings in this Software without
 * prior written authorization from EXPARX INCORPORATED.
 *
 * exparx.com and www.exparx.com  are domain names  registered with
 * EXPARX INCORPORATED, (other GPL-themed licenses are included).
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"
#include "extras/devices/dotenv.hpp"

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
  REQUIRE(dotENV.value("YOURAPPTOKEN") == "dev");
}
