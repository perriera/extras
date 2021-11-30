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
 * (See LICENSE.md for complete details)
 *
 */

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

  // void ScriptException::assertion(const std::string& script, bool autoDelete,
  //                                 const extras::WhereAmI& ref) {
  //   (void)system("ls -la");
  //   if (!extras::contains(script, ".sh")) {
  //     std::string msg = "[" + script + "] does not end in .sh ";
  //     throw ScriptException(msg + script, ref);
  //   }
  //   auto chmod = "chmod +x " + script;
  //   if (system(chmod.c_str()) != 0) {
  //     std::string msg = "[" + script + "] chmod +x failed ";
  //     throw ScriptException(msg + script, ref);
  //   }
  //   auto code = system(script.c_str());
  //   if (autoDelete)
  //     if (fs::exists(script)) fs::remove(script);
  //   if (code != 0) {
  //     std::string msg = "[" + script + "] failed with error code: ";
  //     throw ScriptException(msg + std::to_string(code), ref);
  //   }
  // }

}  // namespace extras
