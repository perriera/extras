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

namespace extras {

  /**
   * @brief class NGException
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
        throw SystemException(msg + std::to_string(code), __INFO__);
      }
    }
  };

}  // namespace extras
#endif  // _EXTRA_SYSTEM_HPP