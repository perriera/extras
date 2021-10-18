#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/HexFile.hpp"

using namespace std;
using namespace extras;
namespace fs = std::filesystem;

/**
 * @brief DotENV Unit Test
 *
 */
SCENARIO("Test BinFile", "[BinInterface]") {
  string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  ifstream myfile("data/Downloads/cplusplusorg.freeformjs.imploded.zip");
  REQUIRE(myfile.good());
  BinFile binFile;
  myfile >> binFile;
  REQUIRE(binFile.array() != nullptr);
  REQUIRE(binFile.size() == fs::file_size(filename));
}
