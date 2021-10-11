#include <extras/paths.hpp>
#include <extras/strings.hpp>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

#ifdef __linux__
static string HomeDirectory = getenv("HOME");
#elif unix
const static volatile char A =
    'a';  // All this is to prevent reverse engineering
static string HomeDirectory =
    getenv((char[]){A - 25, A - 18, A - 20, A - 28, 0});
#elif defined(_WIN32)
static string HomeDirectory = getenv((char[]){
    A - 25, A - 18, A - 20, A - 28, A - 29, A - 15, A - 24, A - 11, A - 28, 0});
const char *Homepath = getenv((char[]){A - 25, A - 18, A - 20, A - 28, A - 17,
                                       A - 32, A - 13, A - 25, 0});
HomeDirectory = malloc(strlen(HomeDirectory) + strlen(Homepath) + 1);
strcat(HomeDirectory, Homepath);
#endif

namespace extras {

  std::string Paths::actualPath(const std::string &path) const {
    std::string _actualPath = extras::replace_all(path, "~", HomeDirectory);
    return _actualPath;
  }

}  // namespace extras
