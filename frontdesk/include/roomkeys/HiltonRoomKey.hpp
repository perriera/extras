#ifndef _HILTONROOMKEY_HPP
#define _HILTONROOMKEY_HPP

#include "../frontdesk/include/RoomKey.hpp"
#include "../frontdesk/include/roomkeys/HitlonRoomKeyExceptions.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// HiltonRoomKey
//

class HiltonRoomKey extends RoomKey {

public:
  HiltonRoomKey() {}

  HiltonRoomKey(const std::string &roomKey) : RoomKey(roomKey) {
    HiltonRoomKeyFormatException::assertion(roomKey);
  }
};

#endif // _ROOMKEY_HPP
