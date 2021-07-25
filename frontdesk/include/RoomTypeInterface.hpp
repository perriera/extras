#ifndef _ROOMTYPEINTERFACE_HPP
#define _ROOMTYPEINTERFACE_HPP

#include "../frontdesk/include/Room.hpp"
#include "extra/Definitions.hpp"

interface RoomTypeInterface {

  virtual Room selectRoomType(int classificationQuery) pure;
};

#endif // _ROOMTYPEINTERFACE_HPP
