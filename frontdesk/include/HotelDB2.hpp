#ifndef _HOTELDB2_HPP
#define _HOTELDB2_HPP

#include "../frontdesk/include/DB2Database.hpp"
#include "../frontdesk/include/HotelInterface.hpp"
#include "extra/Definitions.hpp"

//
// This is just a mock up of what connecting to
// an legacy system might look like.
//

class HotelDB2 implements HotelInterface {

private:
  DB2Initializer _DB2Initializer;
  DB2Authorization _DB2Authorization;
  DB2SSLPermissions _DB2SSLPermissions;
  DB2RoomListing _DB2RoomListing;

public:
  virtual void add(const Room &room);
  virtual void remove(const Room &particularRoom);
  virtual RoomListing roomListing() const;
};

#endif // _HOTELDB2_HPP
