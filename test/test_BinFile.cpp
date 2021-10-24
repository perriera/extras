#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/HexFile.hpp"
#include "extras/paths.hpp"

using namespace std;
using namespace extras;
namespace fs = std::filesystem;

/**
 * @brief BinFile Unit Tests
 *
 */
SCENARIO("Test BinFile >>", "[BinInterface]") {
  string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  ifstream myfile(~Paths(filename));
  REQUIRE(myfile.good());
  BinFile binFile;
  myfile >> binFile;
  REQUIRE(binFile.array() != nullptr);
  REQUIRE(binFile.size() == fs::file_size(filename));
}

SCENARIO("Test BinFile <<", "[BinInterface]") {
  string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  ifstream myfile(~Paths(filename));
  REQUIRE(myfile.good());
  BinFile binFile;
  myfile >> binFile;
  REQUIRE(binFile.array() != nullptr);
  REQUIRE(binFile.size() == fs::file_size(filename));
  string filename2 = "/tmp/cplusplusorg.freeformjs.imploded.zip";
  {
    ofstream tmpfile(filename2);
    REQUIRE(tmpfile.good());
    tmpfile << binFile;
  }
  ifstream myfile2(filename2);
  REQUIRE(myfile2.good());
  BinFile binFile2;
  myfile2 >> binFile2;
  REQUIRE(binFile2.array() != nullptr);
  REQUIRE(binFile2.size() == fs::file_size(filename2));
  REQUIRE(binFile == binFile2);
}
