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

}
