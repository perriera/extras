#ifndef _ROOMKEY_HPP
#define _ROOMKEY_HPP

#include "extra/Definitions.hpp"
#include "extra/crc32_support.hpp"

//
// RoomKey
//

class RoomKey {
  friend inline bool operator==(const RoomKey &a, const RoomKey &b) {
    return a._crcValue == b._crcValue;
  }
  friend inline bool operator!=(const RoomKey &a, const RoomKey &b) {
    return !(a == b);
  }

  long _crcValue;
  std::string _textValue;

public:
  RoomKey() {
    _textValue = "-1";
    _crcValue = crc32().update(_textValue);
  }

  RoomKey(long roomKey) {
    _textValue = std::to_string(roomKey);
    _crcValue = crc32().update(_textValue);
  }

  RoomKey(const std::string &roomKey) : _textValue(roomKey) {
    _crcValue = crc32().update(roomKey);
  }

  operator std::string() const { return _textValue; }
  operator long() const { return _crcValue; }
};

#endif // _ROOMKEY_HPP
