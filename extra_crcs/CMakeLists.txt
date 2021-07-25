 
add_library(
    extra_crcs SHARED
	include/extra/crcs.hpp
	include/extra/crc16_support.hpp
	include/extra/crc32_support.hpp
	include/extra/crc64_support.hpp
	include/extra/octal_support.hpp
	src/crc16.cpp
	src/crc32.cpp
	src/crc64.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_crcs
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_crcs/include/extra
    DESTINATION include
)
target_include_directories(extra_crcs 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_crcs 
 	INTERFACE EXTRA_CRCS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_crcs
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


