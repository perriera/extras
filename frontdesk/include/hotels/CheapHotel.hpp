#ifndef _CHEAPHOTEL_HPP
#define _CHEAPHOTEL_HPP

#include "../frontdesk/include/Hotel.hpp"
#include "extra/Definitions.hpp"
#include "extra/string_support.hpp"
#include <ctype.h>

//
// CheapHotel
//

class CheapHotel extends Hotel {

public:
  virtual Room selectEconomyRoom();
  virtual Room selectMediumRoom();
  virtual Room selectExpensiveRoom();
};

#endif // _CHEAPHOTEL_HPP
