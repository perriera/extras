/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 * @ref https://github.com/perriera
 *
 * Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
 * a copy of this software and associated documentation files (the “Software”),
 * to deal in the Software  without restriction,  including  without limitation
 * the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
 * and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice  and this permission  notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
 * OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
 * LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#include <cstdint>
#include <ctype.h>
#include <extras/crcs/crc32_support.hpp>
#include <extras/crcs/crc64_support.hpp>
#include <extras/devices/ansi_colors.hpp>
#include <extras/file/clazz.hpp>
#include <extras/filesystem/files.hpp>
#include <extras/strings/string_support.hpp>
#include <string>

namespace extras {

   std::uint64_t crc64::table[256];
   std::uint64_t crc64::initial = 0xC96C5795D7870F42;
   crc64 default_crc64;

   std::uint32_t crc32::table[256];
   std::uint32_t crc32::initial;
   crc32 default_crc32;

} // namespace extras

namespace extras {
   define_color(black, 30) define_color(red, 31) define_color(green, 32)
     define_color(yellow, 33) define_color(blue, 34) define_color(magenta, 35)
       define_color(cyan, 36) define_color(white, 37) define_color(reset, 0)
} // namespace extras

namespace extras {
   void file::FolderExistsException::assertion(const Filename& fn,
                                               const WhereAmI& ref)
   {
      file::File file(fn);
      Interface& i = file;
      assertion(i, ref);
   }

   void file::FolderExistsException::assertion(const Interface& file,
                                               const WhereAmI& ref)
   {
      _assume(file.fullpath().length() == 0)
        _ensure FolderNotSpecifiedException(ref);
      auto fn = file.fullpath();
      auto lastChar = fn[fn.length() - 1];
      _assume(!isalnum(lastChar) && lastChar != '/')
        _ensure NotAFolderNameException(fn, ref);
      struct stat statbuf;
      std::string name = file.fullpath();
      _assume(stat(name.c_str(), &statbuf) != 0)
        _ensure NotFoundException(name, ref);
      _assume(!S_ISDIR(statbuf.st_mode))
        _ensure NotAFolderException(file.fullpath(), ref);
   }

   std::string replace_last(const std::string& str,
                            const std::string& from,
                            const std::string& to,
                            char delim)
   {
      extras::StringContainsDelimException::assertion(str, delim, __INFO__);
      if (!contains(str, from))
         return str;
      if (from.size() == 0)
         return str;
      std::string dup_str = str;
      std::string dup_from = from;
      std::string dup_to = to;
      reverse(dup_str.begin(), dup_str.end());
      reverse(dup_from.begin(), dup_from.end());
      reverse(dup_to.begin(), dup_to.end());
      auto it = dup_str.find(dup_from);
      if (it != std::string::npos) {
         auto parta = dup_str.substr(0, it);
         auto partb = dup_str.substr(it + dup_from.size());
         auto newStr = parta + dup_to + partb;
         reverse(newStr.begin(), newStr.end());
         return newStr;
      }
      return str;
   }

   void ScriptException::assertion(const std::string& script,
                                   const extras::WhereAmI& ref)
   {
      if (!extras::str::contains(script, ".sh")) {
         std::string msg = "[" + script + "] does not end in .sh ";
         throw ScriptException(msg + script, ref);
      }
      auto chmod = "chmod +x " + script;
      if (system(chmod.c_str()) != 0) {
         std::string msg = "[" + script + "] chmod +x failed ";
         throw ScriptException(msg + script, ref);
      }
      auto code = 0;
      if (extras::str::contains(script, "/"))
         code = system(script.c_str());
      else {
         auto extrascript = "./" + script;
         code = system(extrascript.c_str());
      }
      if (code != 0) {
         std::string msg = "[" + script + "] failed with error code: ";
         throw ScriptException(msg + std::to_string(code), ref);
      } else {
         // std::filesystem::remove(script);
         // if (std::filesystem::exists(script)) {
         //   std::string msg = "[" + script + "] rm failed with error code:
         //   "; throw ScriptException(msg + std::to_string(code), ref);
         // }
      }
   }

          void StringContainsDelimException::assertion(const std::string& str,
                            char delim,
                            const extras::WhereAmI& ref)
      {
         std::string test;
         test += delim;
         if (extras::str::contains(str, test))
            throw StringContainsDelimException(str, delim, ref);
      }

}
