#include <extras/filesystem/system.hpp>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

namespace extras {

  // void SystemException::assertion(const std::string& cmd,
  //                                 const extras::WhereAmI& ref) {
  //   auto code = system(cmd.c_str());
  //   if (code != 0) {
  //     std::string msg = "[" + cmd + "] failed with error code: ";
  //     throw SystemException(msg + std::to_string(code), ref);
  //   }
  // }

  void ScriptException::assertion(const std::string& script, bool autoDelete,
                                  const extras::WhereAmI& ref) {
    (void)system("ls -la");
    if (!extras::contains(script, ".sh")) {
      std::string msg = "[" + script + "] does not end in .sh ";
      throw ScriptException(msg + script, ref);
    }
    auto chmod = "chmod +x " + script;
    if (system(chmod.c_str()) != 0) {
      std::string msg = "[" + script + "] chmod +x failed ";
      throw ScriptException(msg + script, ref);
    }
    auto code = system(script.c_str());
    if (autoDelete)
      if (fs::exists(script)) fs::remove(script);
    if (code != 0) {
      std::string msg = "[" + script + "] failed with error code: ";
      throw ScriptException(msg + std::to_string(code), ref);
    }
  }

}  // namespace extras
