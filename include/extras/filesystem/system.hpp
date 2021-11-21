#ifndef _EXTRA_SYSTEM_HPP
#define _EXTRA_SYSTEM_HPP

/**
 * @file interfaces.hpp
 * @author Perry Anderson (perryanderson.com)
 * @brief Adds extra keywords for C++ applications
 * @version 1.2.1
 * @date 2021-07-25
 *
 * @copyright Copyright (c) 2021 Perry Anderson,
 * All Rights Reserved, MIT License.
 *
 */

#include <extras/keywords.hpp>
#include <extras/strings.hpp>
#include <filesystem>

namespace extras {

  /**
   * @brief class SystemException
   *
   */
  concrete class SystemException extends extras::AbstractCustomException {
   public:
    SystemException(const std::string& msg, const extras::WhereAmI& whereAmI)
        : extras::AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                          whereAmI._func.c_str(),
                                          whereAmI._line) {}
    static void assertion(const std::string& cmd, const extras::WhereAmI& ref) {
      auto code = system(cmd.c_str());
      if (code != 0) {
        std::string msg = "[" + cmd + "] failed with error code: ";
        throw SystemException(msg + std::to_string(code), ref);
      }
    }
  };

  /**
   * @brief class ScriptException
   *
   */
  concrete class ScriptException extends extras::AbstractCustomException {
   public:
    ScriptException(const std::string& msg, const extras::WhereAmI& whereAmI)
        : extras::AbstractCustomException(msg.c_str(), whereAmI._file.c_str(),
                                          whereAmI._func.c_str(),
                                          whereAmI._line) {}
    static void assertion(const std::string& script,
                          const extras::WhereAmI& ref) {
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
      if (code != 0) {
        std::string msg = "[" + script + "] failed with error code: ";
        throw ScriptException(msg + std::to_string(code), ref);
      } else {
        std::filesystem::remove(script);
        if (std::filesystem::exists(script)) {
          std::string msg = "[" + script + "] rm failed with error code: ";
          throw ScriptException(msg + std::to_string(code), ref);
        }
      }
    }
  };

}  // namespace extras
#endif  // _EXTRA_SYSTEM_HPP