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

#ifndef _EXTRA_CRC16_SUPPORT_HPP
#define _EXTRA_CRC16_SUPPORT_HPP

#include <stddef.h>
#include <stdint.h>

#include <iostream>

namespace extras {

  //
  // simplest crc16 c++ implementation
  // https://github.com/jpralves/crc16
  //

  class crc16 {
   public:
    crc16();
    uint16_t update(const std::string &str);
    uint16_t processBuffer(const char *data_p, uint16_t length);

   private:
    uint16_t processByte(uint8_t data);
    uint16_t getCrc() { return crc; };
    uint16_t crc;
  };

  class Crc16CollisionException : std::exception {};

  /*
  * Library Name: CRC16
  *
  * Filename: CRC16.h
  * Description: library CRC16 interface
  *
  * generate a ccitt 16 bit cyclic redundancy check (crc)
  * The code in this module generates the crc for a block of data.
  *
  * Version: 1.0.2
  * Author: Joao Alves <jpralves@gmail.com>
  * Required files: crc16.cpp, crc16.h
  *
  * History:
  * 1.0.2 - 2017-03-14 - Initial Version
  *
  * This library is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.

  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.

  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

  // #include "crc16.h"

  // char *buffer = "The quick brown fox jumps over the lazy dog";
  // CRC16 crc;

  // void setup() {
  //   Serial.begin(9600);
  //   Serial.println("CRC16 test!");
  //   crc.processBuffer(buffer, strlen(buffer));
  //   Serial.print("The resulting CRC16 is : 0x");
  //   Serial.println(crc.getCrc(),HEX);
  // }

  // void loop() {
  // }

}  // namespace extras

#endif  // _EXTRA_CRC16_SUPPORT_HPP
