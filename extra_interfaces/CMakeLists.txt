 
add_library(extra_interfaces SHARED
	include/extra/interfaces.hpp
	src/interfaces.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_interfaces
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_interfaces/include/extra
    DESTINATION include
)
target_include_directories(extra_interfaces 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_interfaces 
 	INTERFACE extra_interfaces_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_interfaces
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


