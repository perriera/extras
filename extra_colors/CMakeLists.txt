 
add_library(extra_colors SHARED
	include/extra/ansi_colors.hpp
	include/extra/ansi_input.hpp
	src/ansi_colors.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_colors
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_colors/include/extra
    DESTINATION include
)
target_include_directories(extra_colors 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_colors 
 	INTERFACE EXTRA_COLORS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_colors
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


