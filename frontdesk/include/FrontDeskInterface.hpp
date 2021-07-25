#ifndef _FRONTDESKINTERFACE_HPP
#define _FRONTDESKINTERFACE_HPP

#include "../frontdesk/include/Customer.hpp"
#include "../frontdesk/include/Reservation.hpp"
#include "../frontdesk/include/Room.hpp"
#include "../frontdesk/include/RoomSelectionInterface.hpp"
#include "../frontdesk/include/RoomTypeInterface.hpp"
#include "extra/Definitions.hpp"

interface FrontDeskInterface extends RoomSelectionInterface with
    RoomTypeInterface {
  virtual void checkIn(const Customer &customer, const Room &room,
                       Reservation &reservation) pure;

  virtual void checkOut(const Customer &customer) pure;
};

#endif // _FRONTDESKINTERFACE_HPP
