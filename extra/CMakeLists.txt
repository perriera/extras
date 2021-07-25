 
add_library(
    extra SHARED
	include/extra/ansi_colors.hpp
	include/extra/ansi_input.hpp
	include/extra/crc16_support.hpp
	include/extra/crc32_support.hpp
	include/extra/crc64_support.hpp
	include/extra/Directory.hpp
	include/extra/octal_support.hpp
	include/extra/string_support.hpp
	src/ansi_colors.cpp
	src/crc16.cpp
	src/crc32.cpp
	src/crc64.cpp
	src/Directory.cpp
	src/string_support.cpp
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


