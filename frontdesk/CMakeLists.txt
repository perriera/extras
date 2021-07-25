 
add_library(
    frontdesk SHARED
	include/Customer.hpp     
    include/FrontDesk.hpp           
    include/Hotel.hpp           
    include/ReservationExceptions.hpp  
    include/Room.hpp     
    include/RoomSelectionInterface.hpp
    include/DB2Database.hpp 
    include/FrontDeskInterface.hpp  
    include/HotelInterface.hpp  
    include/Reservation.hpp            
    include/RoomKey.hpp  
    include/RoomTypeInterface.hpp
    include/HotelDB2.hpp            
    include/hotels              
    include/RoomExceptions.hpp         
    include/roomkeys
    include/hotels/CheapHotel.hpp  
    include/hotels/DeltaHotel.hpp
    include/roomkeys/DeltaRoomKeyExceptions.hpp  
    include/roomkeys/DeltaRoomKey.hpp  
    include/roomkeys/HiltonRoomKey.hpp  
    include/roomkeys/HitlonRoomKeyExceptions.hpp
    src/FrontDesk.cpp  
    src/Hotel.cpp  
    src/Room.cpp
    src/hotels/CheapHotel.cpp  
    src/hotels/DeltaHotel.cpp
)

target_link_libraries(frontdesk 
    PRIVATE
        chessmind::library 
        docopt
        extra
)

