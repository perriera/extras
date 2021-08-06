#ifndef _EXTRA_CRC16_SUPPORT_HPP
#define _EXTRA_CRC16_SUPPORT_HPP

#include <iostream>
#include <stddef.h>
#include <stdint.h>

namespace extras
{

  //
  // simplest crc16 c++ implementation
  // https://github.com/jpralves/crc16
  //

  class crc16
  {
  public:
    crc16();
    uint16_t update(const std::string &str);
    uint16_t processBuffer(const char *data_p, uint16_t length);

  private:
    uint16_t processByte(uint8_t data);
    uint16_t getCrc() { return crc; };
    uint16_t crc;
  };

  class Crc16CollisionException : std::exception
  {
  };

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

} // namespace extras

#endif // _EXTRA_CRC16_SUPPORT_HPP
