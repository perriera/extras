#ifndef _HOTELINTERFACE_HPP
#define _HOTELINTERFACE_HPP

#include "../frontdesk/include/Room.hpp"
#include "../frontdesk/include/RoomSelectionInterface.hpp"
#include "extra/Definitions.hpp"

interface HotelInterface extends RoomSelectionInterface {
  virtual void add(const Room &room) pure;
  virtual void remove(const Room &room) pure;
  virtual RoomListing allRoomsListing() const pure;
  virtual void reserve(const Room &room) pure;
  virtual void checkout(const Room &room) pure;
  virtual void cancel(const Room &room) pure;
  virtual void service(const Room &room) pure;
  virtual RoomListing availableRoomsListing() const pure;
  virtual RoomListing reservedRoomsListing() const pure;
  virtual RoomListing checkedoutRoomsListing() const pure;
};

#endif // _HOTELINTERFACE_HPP
