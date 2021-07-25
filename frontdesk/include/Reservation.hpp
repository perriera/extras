#ifndef _RESERVATION_HPP
#define _RESERVATION_HPP

#include "../frontdesk/include/Customer.hpp"
#include "../frontdesk/include/ReservationExceptions.hpp"
#include "../frontdesk/include/Room.hpp"
#include "extra/Definitions.hpp"

//
// Reservations table
//

typedef long ReservationKey;

struct Reservation {
  ReservationKey key;
  RoomKey room;
  CustomerKey customer;
};

typedef std::map<ReservationKey, Reservation> ReservationTable;

#endif // _RESERVATION_HPP
