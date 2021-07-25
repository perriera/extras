#ifndef _HILTONROOMKEYEXCEPTIONS_HPP
#define _HILTONROOMKEYEXCEPTIONS_HPP

#include "../frontdesk/include/RoomKey.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// HiltonRoomKeyFormatException
//

class HiltonRoomKeyFormatException extends std::exception {

  std::string _msg;

public:
  HiltonRoomKeyFormatException(const std::string &roomKey) {
    _msg = "Not in Hilton Hotel Room Key format: " + roomKey;
  }

  static void assertion(const std::string &roomKey) {
    if (roomKey.length() == 7 && roomKey[2] == ':') {
      auto parts = split(roomKey, ':');
      if (!isalpha(parts[0][0]) && !isalpha(parts[0][1]))
        throw HiltonRoomKeyFormatException(roomKey);
      auto number = std::stoi(parts[1]);
      if (number < 1)
        throw HiltonRoomKeyFormatException(roomKey);
    } else
      throw HiltonRoomKeyFormatException(roomKey);
  }
};

#endif // _HILTONROOMKEYEXCEPTIONS_HPP
