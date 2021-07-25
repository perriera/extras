#include "../frontdesk/include//hotels/DeltaHotel.hpp"
#include "extra/string_support.hpp"
#include <iostream>

using namespace std;

Room DeltaHotel::_selectRoom(char code) {
  auto roomListing = this->availableRoomsListing();
  for (auto room : roomListing) {
    string roomKey = room._key;
    if (roomKey[0] == code)
      return room;
  }
  throw NoRoomsOfAGivenTypeException();
}

Room DeltaHotel::selectEconomyRoom() { return _selectRoom('E'); }

Room DeltaHotel::selectMediumRoom() { return _selectRoom('M'); }

Room DeltaHotel::selectExpensiveRoom() { return _selectRoom('L'); }
