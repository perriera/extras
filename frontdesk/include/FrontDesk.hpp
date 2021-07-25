#ifndef _FRONTDESK_HPP
#define _FRONTDESK_HPP

#include "../frontdesk/include/FrontDeskInterface.hpp"
#include "../frontdesk/include/HotelInterface.hpp"
#include "extra/Definitions.hpp"

class FrontDesk implements FrontDeskInterface {

private:
  HotelInterface &_hotel;
  CustomerTable customers;
  RoomTable rooms;
  ReservationTable reservations;

public:
  FrontDesk(HotelInterface &hotel) : _hotel(hotel){};

  virtual void checkIn(const Customer &customer, const Room &room,
                       Reservation &reservation);
  virtual void checkOut(const Customer &customer);
  virtual Room selectRoomType(int classificationQuery);
  virtual Room selectEconomyRoom() { return _hotel.selectEconomyRoom(); };
  virtual Room selectMediumRoom() { return _hotel.selectMediumRoom(); };
  virtual Room selectExpensiveRoom() { return _hotel.selectExpensiveRoom(); };
};

#endif // _FRONTDESK_HPP
