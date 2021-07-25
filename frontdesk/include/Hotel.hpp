#ifndef _HOTEL_HPP
#define _HOTEL_HPP

#include "../frontdesk/include/HotelInterface.hpp"
#include "../frontdesk/include/Room.hpp"
#include "extra/Definitions.hpp"
#include <algorithm>

class Hotel implements HotelInterface {

private:
  RoomListing _available;
  RoomListing _reserved;
  RoomListing _servicing;

  Room _find(const Room &particularRoom, const RoomListing &listing) const {
    auto it = std::find(listing.begin(), listing.end(), particularRoom);
    if (it != listing.end())
      return *it;
    throw RoomNotFoundException();
  }

  RoomListing _remove(const Room &particularRoom,
                      const RoomListing &listing) const {
    RoomListing _updated;
    for (const Room &room : listing)
      if (room != particularRoom)
        _updated.push_back(room);
    return _updated;
  }

public:
  virtual void add(const Room &room) { _available.push_back(room); };

  virtual void remove(const Room &particularRoom) {
    _available = _remove(particularRoom, _available);
  }

  virtual RoomListing allRoomsListing() const {
    RoomListing allRooms = _available;
    allRooms.insert(allRooms.end(), _reserved.begin(), _reserved.end());
    allRooms.insert(allRooms.end(), _servicing.begin(), _servicing.end());
    return allRooms;
  };

  virtual void reserve(const Room &room) {
    Room details = _find(room, _available);
    _available = _remove(room, _available);
    _reserved.push_back(details);
  };

  virtual void checkout(const Room &room) {
    Room details = _find(room, _reserved);
    _reserved = _remove(room, _reserved);
    _servicing.push_back(details);
  };

  virtual void service(const Room &room) {
    Room details = _find(room, _servicing);
    _servicing = _remove(room, _servicing);
    _available.push_back(details);
  };

  virtual void cancel(const Room &room) {
    Room details = _find(room, _reserved);
    _reserved = _remove(room, _reserved);
    _available.push_back(details);
  };

  virtual RoomListing availableRoomsListing() const {
    RoomListing dup = _available;
    return dup;
  };
  virtual RoomListing reservedRoomsListing() const {
    RoomListing dup = _reserved;
    return dup;
  };
  virtual RoomListing checkedoutRoomsListing() const {
    RoomListing dup = _servicing;
    return dup;
  };

  virtual Room selectEconomyRoom();
  virtual Room selectMediumRoom();
  virtual Room selectExpensiveRoom();
};

#endif // _HOTEL_HPP
