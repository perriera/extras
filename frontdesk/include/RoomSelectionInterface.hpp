#ifndef _ROOMSELECTIONINTERFACE_HPP
#define _ROOMSELECTIONINTERFACE_HPP

#include "../frontdesk/include/Room.hpp"
#include "extra/Definitions.hpp"

interface RoomSelectionInterface {

  virtual Room selectEconomyRoom() pure;
  virtual Room selectMediumRoom() pure;
  virtual Room selectExpensiveRoom() pure;
};

#endif // _ROOMSELECTIONINTERFACE_HPP
