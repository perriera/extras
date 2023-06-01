/**
 * @file crc32_support.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief CRC 32 implementation
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRA_CRC32_SUPPORT_HPP
#define _EXTRA_CRC32_SUPPORT_HPP

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

#include <extras/keywords.hpp>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

namespace extras {

   //
   // simplest crc32 c++ implementation
   // https://gist.github.com/timepp
   //

   class crc32
   {
    public:

      crc32(const char* randomString = "default seed")
      {
         crc32::generate_table(crc32::table);
         crc32::initial = crc32::update(table, 0, randomString);
      }

      uint32_t update(const std::string& str)
      {
         return update(table, crc32::initial, str.c_str(), str.length());
      }

      uint32_t update(const byte* buffer, int len)
      {
         return update(table, crc32::initial, buffer, len);
      }

    private:

      static void generate_table(uint32_t (&table)[256])
      {
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

      static uint32_t update(uint32_t (&table)[256],
                             uint32_t initial,
                             const void* buf,
                             size_t len)
      {
         std::uint32_t c = initial ^ 0xFFFFFFFF;
         const std::uint8_t* u = static_cast<const std::uint8_t*>(buf);
         for (std::size_t i = 0; i < len; ++i) {
            c = table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
         }
         return c ^ 0xFFFFFFFF;
      }

      static uint32_t update(uint32_t (&table)[256],
                             uint32_t initial,
                             const std::string& str)
      {
         return update(table, initial, str.c_str(), str.length());
      }

      static uint32_t table[256];
      static uint32_t initial;
   };

   class Crc32CollisionException : public std::exception
   {
    public:

      virtual char const* what() const noexcept
      {
         return "Crc32CollisionException";
      }
   };

   // usage: the following code generates crc for 2 pieces of data
   // uint32_t table[256];
   // crc32::generate_table(table);
   // uint32_t crc = crc32::update(table, 0, data_piece1, len1);
   // crc = crc32::update(table, crc, data_piece2, len2);
   // output(crc);

   //
   // 32bit CRC COLLISIONS
   //
   // crc32 _crc;
   //
   //     cout <<
   //     _crc.update("r1bq1rk1/2p1bppp/p2p1n2/np2p3/4P3/1BPP1N2/PP3PPP/RNBQR1K")
   //     << endl; cout <<
   //     _crc.update("2r2k2/p2bpp2/3p2p1/1pr4p/4PN1P/1P3P2/P1PR2P1/1K2R") <<
   //     endl;
   //
   //  With only perhaps a 100,000 to 200,000 entries (if that), we managed to
   //  beat 1 chance in 4.2 billion with the above two strings.
   //
} // namespace extras

#endif // _EXTRA_CRC32_SUPPORT_HPP
