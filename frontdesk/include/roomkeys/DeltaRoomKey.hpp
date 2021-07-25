#ifndef _DELTAROOMKEY_HPP
#define _DELTAROOMKEY_HPP

#include "../frontdesk/include/RoomKey.hpp"
#include "../frontdesk/include/roomkeys/DeltaRoomKeyExceptions.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// HiltonRoomKey
//

class DeltaRoomKey extends RoomKey {

public:
  DeltaRoomKey() {}

  DeltaRoomKey(const std::string &roomKey) : RoomKey(roomKey) {
    DeltaRoomKeyFormatException::assertion(roomKey);
  }
};

#endif // _DELTAROOMKEY_HPP
