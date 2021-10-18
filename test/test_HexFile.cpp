#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "extras/bin2hex/BinConverter.hpp"
#include "extras/bin2hex/BinFile.hpp"
#include "extras/bin2hex/ConvertBin2Hex.hpp"
#include "extras/bin2hex/HexConverter.hpp"
#include "extras/bin2hex/HexFile.hpp"

using namespace std;
using namespace extras;
namespace fs = std::filesystem;

/**
 * @brief BinFile Unit Tests
 *
 */
SCENARIO("Test HexFile >>", "[BinInterface]") {
  string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
  ifstream myfile(filename);
  REQUIRE(myfile.good());
  BinFile binFile;
  myfile >> binFile;
  auto file_size = fs::file_size(filename);
  REQUIRE(binFile.array() != nullptr);
  REQUIRE(binFile.size() == file_size);
  HexConverter hexConverter;
  HexFile hexFile = hexConverter.bin2hex(binFile);
  REQUIRE(hexFile.size() == file_size * 2);
  BinConverter binConverter;
  BinArray binArray = binConverter.hex2bin(hexFile);
  auto z1 = binArray.size();
  auto z2 = z1 - file_size;
  REQUIRE(binArray.size() == file_size);
}

// SCENARIO("Test HexFile <<", "[BinInterface]") {
//   string filename = "data/Downloads/cplusplusorg.freeformjs.imploded.zip";
//   ifstream myfile(filename);
//   REQUIRE(myfile.good());
//   BinFile binFile;
//   myfile >> binFile;
//   REQUIRE(binFile.array() != nullptr);
//   REQUIRE(binFile.size() == fs::file_size(filename));
//   string filename2 = "/tmp/cplusplusorg.freeformjs.imploded.zip";
//   {
//     ofstream tmpfile(filename2);
//     REQUIRE(tmpfile.good());
//     tmpfile << binFile;
//   }
//   ifstream myfile2(filename2);
//   REQUIRE(myfile2.good());
//   BinFile binFile2;
//   myfile2 >> binFile2;
//   REQUIRE(binFile2.array() != nullptr);
//   REQUIRE(binFile2.size() == fs::file_size(filename2));
//   REQUIRE(binFile == binFile2);
// }
