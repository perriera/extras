#ifndef _DELTAROOMKEYEXCEPTIONS_HPP
#define _DELTAROOMKEYEXCEPTIONS_HPP

#include "../frontdesk/include/RoomKey.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// DeltaRoomKeyFormatException
//

class DeltaRoomKeyFormatException extends std::exception {

  std::string _msg;

public:
  DeltaRoomKeyFormatException(const std::string &roomKey) {
    _msg = "Not in Delta Hotel Room Key format: " + roomKey;
  }

  static void assertion(const std::string &roomKey) {
    if (roomKey.length() == 5) {
      if (!isalpha(roomKey[0]))
        throw DeltaRoomKeyFormatException(roomKey);
      auto substr = roomKey.substr(1);
      auto number = std::stoi(substr);
      if (number < 1000)
        throw DeltaRoomKeyFormatException(roomKey);
    } else
      throw DeltaRoomKeyFormatException(roomKey);
  }
};

#endif // _DELTAROOMKEYEXCEPTIONS_HPP
