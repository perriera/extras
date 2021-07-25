#include "../frontdesk/include/FrontDesk.hpp"
#include "extra/string_support.hpp"
#include <iostream>

using namespace std;

void FrontDesk::checkIn(const Customer &customer, const Room &room,
                        Reservation &reservation) {
  customers[customer.key] = customer;
  reservation.room = room._key;
  reservation.customer = customer.key;
  reservations[reservation.key] = reservation;
  _hotel.reserve(room);
};

void FrontDesk::checkOut(const Customer &customer) {
  customers.erase(customer.key);
  for (auto reservation : reservations) {
    if (reservation.second.customer == customer.key) {
      reservations.erase(reservation.first);
      _hotel.checkout(reservation.second.room);
      return;
    }
  }
  throw ReservationNotFoundException();
};

Room FrontDesk::selectRoomType(int classificationQuery) {
  for (auto room : rooms) {
    if (room.second._type.classifaction == classificationQuery)
      return room.second;
  }
  throw NoRoomsTypeException(classificationQuery);
}
