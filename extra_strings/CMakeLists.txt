 
add_library(extra_strings SHARED
    include/extra/strings.hpp
	include/extra/string_support.hpp
	src/string_support.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_strings
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_strings/include/extra
    DESTINATION include
)
target_include_directories(extra_strings 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_strings 
 	INTERFACE EXTRA_STRINGS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_strings
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


