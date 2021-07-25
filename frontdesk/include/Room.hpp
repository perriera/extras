#ifndef _ROOM_HPP
#define _ROOM_HPP

#include <iostream>
#include <map>
#include <vector>

#include "../frontdesk/include/RoomExceptions.hpp"
#include "../frontdesk/include/RoomKey.hpp"
#include "extra/Definitions.hpp"

//
// Room table
//

struct RoomType {
  // number between 0  to 10,000
  int classifaction;
};

struct Room {
  friend inline bool operator==(const Room &a, const Room &b) {
    return a._key == b._key;
  }
  friend inline bool operator!=(const Room &a, const Room &b) {
    return !(a == b);
  }

  RoomKey _key;
  std::string _description;
  RoomType _type;

  Room() : _key(-1){};
  Room(const RoomKey &key) : _key(key) {}
};

std::ostream &operator<<(std::ostream &out, const Room &obj);
std::istream &operator>>(std::istream &in, Room &obj);

typedef std::map<RoomKey, Room> RoomTable;
typedef std::vector<Room> RoomListing;

#endif // _ROOM_HPP
