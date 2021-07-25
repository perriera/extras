#include "../frontdesk/include//Hotel.hpp"
#include "extra/string_support.hpp"
#include <iostream>

using namespace std;

Room Hotel::selectEconomyRoom() {
  auto roomListing = this->availableRoomsListing();
  if (roomListing.size() > 0)
    return roomListing[0];
  throw "Nothing found";
}

Room Hotel::selectMediumRoom() { return Room(); }
Room Hotel::selectExpensiveRoom() { return Room(); }
