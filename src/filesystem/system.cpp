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
 * AND NON-INFRINGEMENT.  IN  NO  EVENT  SHALL EXPARX  INCORPORATED
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
