/**
 * @file crc64_support.hpp
 * @author Perry Anderson (perry@exparx.ca)
 * @brief CRC 64 implementation
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
 *
 */

#ifndef _EXTRA_CRC64_SUPPORT_HPP
#define _EXTRA_CRC64_SUPPORT_HPP

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
   // simplest crc64 c++ implementation
   // http://pages.pathcom.com/~vadco/crc.html
   //

   class crc64
   {
    public:

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

      crc64(const char* randomString = nullptr)
      {
         crc64::generate_table(crc64::table);
         // crc64::initial = crc64::update(table, 0, randomString);
      }

#pragma GCC diagnostic pop

      uint64_t update(const std::string& str)
      {
         return update(table,
                       crc64::initial,
                       (const std::uint8_t*)str.c_str(),
                       str.length());
      }

      uint32_t update(const byte* buffer, int len)
      {
         return update(table, crc64::initial, buffer, len);
      }

    private:

      static void generate_table(uint64_t (&table)[256])
      {
         for (int i = 0; i < 256; ++i) {
            std::uint64_t crc = i;

            for (std::uint8_t j = 0; j < 8; ++j) {
               // is current coefficient set?
               if (crc & 1) {
                  // yes, then ensure it gets zero'd (by implied x^64
                  // coefficient of dividend)
                  crc >>= 1;

                  // and add rest of the divisor
                  crc ^= initial;
               } else {
                  // no? then move to next coefficient
                  crc >>= 1;
               }

               table[i] = crc;
            }
         }
      }

      static uint64_t update(uint64_t (&table)[256],
                             uint64_t,
                             const uint8_t* buf,
                             size_t len)
      {
         std::uint64_t crc = 0;

         for (std::size_t i = 0; i < len; ++i) {
            std::uint8_t index = buf[i] ^ crc;
            std::uint64_t lookup = table[index];

            crc >>= 8;
            crc ^= lookup;
         }

         return crc;
      }

      static uint64_t update(uint64_t (&table)[256],
                             uint64_t initial,
                             const std::string& str)
      {
         return update(
           table, initial, (const std::uint8_t*)str.c_str(), str.length());
      }

      static uint64_t table[256];
      static uint64_t initial;
   };

   class Crc64CollisionException : public std::exception
   {
    public:

      Crc64CollisionException()
      {
         std::cout << "Beating the odds of 1 in just over 1.84+e19"
                   << std::endl;
      }

      virtual char const* what() const noexcept
      {
         return "Crc64CollisionException";
      }
   };

   //
   // (c) Copyright http://andrewl.dreamhosters.com, crc64
   //
   // // 64-bit CRC implementation - andrewl
   // //
   // // history:
   // // Jun 22, 2021 - ported to Linux
   // // Aug 02, 2009 - test inputs added, some explanations corrected
   // // Jul 08, 2009 - created

   // #include <iostream>
   // #include <stdio.h>

   // // poly is: x^64 + x^62 + x^57 + x^55 + x^54 + x^53 + x^52 + x^47 + x^46 +
   // x^45 + x^40 + x^39 +
   // //          x^38 + x^37 + x^35 + x^33 + x^32 + x^31 + x^29 + x^27 + x^24 +
   // x^23 + x^22 + x^21 +
   // //          x^19 + x^17 + x^13 + x^12 + x^10 + x^9  + x^7  + x^4  + x^1  +
   // 1
   // //
   // // represented here with lsb = highest degree term
   // //
   // // 1100100101101100010101111001010111010111100001110000111101000010_
   // // ||  |  | || ||   | | ||||  | | ||| | ||||    |||    |||| |    | |
   // // ||  |  | || ||   | | ||||  | | ||| | ||||    |||    |||| |    | +- x^64
   // (implied)
   // // ||  |  | || ||   | | ||||  | | ||| | ||||    |||    |||| |    |
   // // ||  |  | || ||   | | ||||  | | ||| | ||||    |||    |||| |    +--- x^62
   // // ||  |  | || ||   | | ||||  | | ||| | ||||    |||    |||| +-------- x^57
   // // .......................................................................
   // // ||
   // // |+---------------------------------------------------------------- x^1
   // // +----------------------------------------------------------------- x^0
   // (1) uint64_t poly = 0xC96C5795D7870F42;

   // // input is dividend: as
   // 0000000000000000000000000000000000000000000000000000000000000000<8-bit
   // byte>
   // // where the lsb of the 8-bit byte is the coefficient of the highest
   // degree term (x^71) of the dividend
   // // so division is really for input byte * x^64

   // // you may wonder how 72 bits will fit in 64-bit data type... well as the
   // shift-right occurs, 0's are supplied
   // // on the left (most significant) side ... when the 8 shifts are done, the
   // right side (where the input
   // // byte was placed) is discarded

   // // when done, table[XX] (where XX is a byte) is equal to the CRC of 00 00
   // 00 00 00 00 00 00 XX
   // //
   // uint64_t table[256];

   // void generate_table()
   // {
   //     for (int i = 0; i < 256; ++i)
   //     {
   //         uint64_t crc = i;

   //         for (uint8_t j = 0; j < 8; ++j)
   //         {
   //             // is current coefficient set?
   //             if (crc & 1)
   //             {
   //                 // yes, then ensure it gets zero'd (by implied x^64
   //                 coefficient of dividend) crc >>= 1;

   //                 // and add rest of the divisor
   //                 crc ^= poly;
   //             }
   //             else
   //             {
   //                 // no? then move to next coefficient
   //                 crc >>= 1;
   //             }
   //         }

   //         table[i] = crc;
   //     }
   // }

   // // will give an example CRC calculation for input array {0xDE, 0xAD}
   // //
   // // each byte represents a group of 8 coefficients for 8 dividend terms
   // //
   // // the actual polynomial dividend is:
   // //
   // // = DE       AD       00 00 00 00 00 00 00 00 (hex)
   // // = 11011110 10101101 0000000000000000000...0 (binary)
   // //   || ||||  | | || |
   // //   || ||||  | | || +------------------------ x^71
   // //   || ||||  | | |+-------------------------- x^69
   // //   || ||||  | | +--------------------------- x^68
   // //   || ||||  | +----------------------------- x^66
   // //   || ||||  +------------------------------- x^64
   // //   || ||||
   // //   || |||+---------------------------------- x^78
   // //   || ||+----------------------------------- x^77
   // //   || |+------------------------------------ x^76
   // //   || +------------------------------------- x^75
   // //   |+--------------------------------------- x^73
   // //   +---------------------------------------- x^72
   // //

   // // the basic idea behind how the table lookup results can be used with one
   // // another is that:
   // //
   // // Mod(A * x^n, P(x)) = Mod(x^n * Mod(A, P(X)), P(X))
   // //
   // // in other words, an input data shifted towards the higher degree terms
   // // changes the pre-computed crc of the input data by shifting it also
   // // the same amount towards higher degree terms (mod the polynomial)

   // // here is an example:
   // //
   // // 1) input:
   // //
   // //    00 00 00 00 00 00 00 00 AD DE
   // //
   // // 2) index crc table for byte DE (really for dividend 00 00 00 00 00 00
   // 00 00 DE)
   // //
   // //    we get A8B4AFBDC5A6ACA4
   // //
   // // 3) apply that to the input stream:
   // //
   // //    00 00 00 00 00 00 00 00 AD DE
   // //       A8 B4 AF BD C5 A6 AC A4
   // //    -----------------------------
   // //    00 A8 B4 AF BD C5 A6 AC 09
   // //
   // // 4) index crc table for byte 09 (really for dividend 00 00 00 00 00 00
   // 00 00 09)
   // //
   // //    we get 448FCBB7FCB9E309
   // //
   // // 5) apply that to the input stream
   // //
   // //    00 A8 B4 AF BD C5 A6 AC 09
   // //    44 8F CB B7 FC B9 E3 09
   // //    --------------------------
   // //    44 27 7F 18 41 7C 45 A5
} // namespace extras

#endif // _EXTRA_CRC64_SUPPORT_HPP
