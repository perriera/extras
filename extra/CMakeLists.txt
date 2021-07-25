 
add_library(
    extra SHARED
	include/extra/support.hpp
	include/extra/Definitions.hpp
	src/Definitions.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra/include/extra
    DESTINATION include
)
target_include_directories(extra 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra 
 	INTERFACE EXTRA_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


