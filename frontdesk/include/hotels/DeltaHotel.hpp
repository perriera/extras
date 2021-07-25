#ifndef _DELTAHOTEL_HPP
#define _DELTAHOTEL_HPP

#include "../frontdesk/include/Hotel.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// DeltaHotel
//

class DeltaHotel extends Hotel {

  Room _selectRoom(char code);

public:
  virtual Room selectEconomyRoom();
  virtual Room selectMediumRoom();
  virtual Room selectExpensiveRoom();
};

#endif // _DELTAHOTEL_HPP
