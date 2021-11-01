#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

namespace fs = std::filesystem;

#define PORT 8000
int main(int argc, char const*[]) {
  /**
   * @return this returns the number of argments given, (less 1)
   * @note when used via system() the return value can be divided by 256 to get
   * the actual value of the number returned by main.
   */
  return argc - 1;
}
