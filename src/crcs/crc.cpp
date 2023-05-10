/**
 * @brief The MIT License (MIT)
 * @copyright © 2023 Perry Anderson, (perry@exparx.ca)
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

#include "extras/crcs.hpp"

#include <iostream>

using namespace std;

namespace extras {

   CRC::operator uint16_t() const
   {
      crc16 crc16;
      if (_len == 0)
         return crc16.update(_str);
      else
         return crc16.processBuffer((const char*)this->_buffer,
                                    (uint16_t)this->_len);
   }

   CRC::operator uint32_t() const
   {
      crc32 crc32;
      if (_len == 0)
         return crc32.update(_str);
      else
         return crc32.update(this->_buffer, (size_t)this->_len);
   }

   CRC::operator uint64_t() const
   {
      crc64 crc64;
      if (_len == 0)
         return crc64.update(_str);
      else
         return crc64.update(this->_buffer, (size_t)this->_len);
   }

   //
   //

} // namespace extras
