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
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE  EXPARX  INCORPORATED
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

#include <cstdint>
#include <extras/crcs/crc32_support.hpp>
#include <string>

namespace extras {

  // simplest crc32 c++ implementation
  // https://gist.github.com/timepp

  void crc32::generate_table(std::uint32_t (&table)[256]) {
    std::uint32_t polynomial = 0xEDB88320;
    for (std::uint32_t i = 0; i < 256; i++) {
      std::uint32_t c = i;
      for (std::size_t j = 0; j < 8; j++) {
        if (c & 1) {
          c = polynomial ^ (c >> 1);
        } else {
          c >>= 1;
        }
        table[i] = c;
      }
    }
  }

  std::uint32_t crc32::update(std::uint32_t (&table)[256],
                              std::uint32_t initial, const void *buf,
                              std::size_t len) {
    std::uint32_t c = initial ^ 0xFFFFFFFF;
    const std::uint8_t *u = static_cast<const std::uint8_t *>(buf);
    for (std::size_t i = 0; i < len; ++i) {
      c = table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
    }
    return c ^ 0xFFFFFFFF;
  }

  std::uint32_t crc32::update(std::uint32_t (&table)[256],
                              std::uint32_t initial, const std::string &str) {
    return update(table, initial, str.c_str(), str.length());
  }

  uint32_t crc32::update(const std::string &str) {
    return update(table, crc32::initial, str.c_str(), str.length());
  }

  uint32_t crc32::update(const byte *buffer, int len) {
    return update(table, crc32::initial, buffer, len);
  }

  std::uint32_t crc32::table[256];
  std::uint32_t crc32::initial;
  crc32 default_crc32;

  crc32::crc32(const char *randomString) {
    crc32::generate_table(crc32::table);
    crc32::initial = crc32::update(table, 0, randomString);
  }

}  // namespace extras
