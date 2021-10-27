#include <iostream>

#include "extras/crcs.hpp"

using namespace std;

namespace extras {

  CRC::operator uint16_t() const {
    crc16 crc16;
    if (_len == 0)
      return crc16.update(_str);
    else
      return crc16.processBuffer((const char *)this->_buffer,
                                 (uint16_t)this->_len);
  }

  CRC::operator uint32_t() const {
    crc32 crc32;
    if (_len == 0)
      return crc32.update(_str);
    else
      return crc32.update(this->_buffer, (size_t)this->_len);
  }

  CRC::operator uint64_t() const {
    crc64 crc64;
    if (_len == 0)
      return crc64.update(_str);
    else
      return crc64.update(this->_buffer, (size_t)this->_len);
  }

  //
  //

}  // namespace extras