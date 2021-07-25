#ifndef _ROOMEXCEPTIONS_HPP
#define _ROOMEXCEPTIONS_HPP

#include "../frontdesk/include/RoomKey.hpp"
#include "extra/Definitions.hpp"

//
// RoomExceptions
//

class NoRoomsTypeException extends std::exception {

public:
  NoRoomsTypeException(int) {}
};

class RoomNotFoundException extends std::exception {};

class NoRoomsOfAGivenTypeException extends std::exception {};

#endif // _ROOMEXCEPTIONS_HPP
