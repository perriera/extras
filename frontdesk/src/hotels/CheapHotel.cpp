#include "../frontdesk/include//hotels/CheapHotel.hpp"
#include "extra/string_support.hpp"
#include <iostream>

using namespace std;

Room CheapHotel::selectEconomyRoom() {
  auto roomListing = this->availableRoomsListing();
  for (auto room : roomListing) {
    string roomKey = room._key;
    int roomKeyValue = stoi(roomKey);
    if (roomKeyValue > 100 && roomKeyValue < 300)
      return room;
  }
  throw NoRoomsOfAGivenTypeException();
}

Room CheapHotel::selectMediumRoom() { return Room(); }
Room CheapHotel::selectExpensiveRoom() { return Room(); }
