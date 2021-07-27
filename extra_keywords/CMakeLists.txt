 
add_library(extra_keywords SHARED
	include/extra/keywords.hpp
	include/extra/interfaces.hpp
	src/keywords.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_keywords
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_keywords/include/extra
    DESTINATION include
)
target_include_directories(extra_keywords 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_keywords 
 	INTERFACE EXTRA_KEYWORDS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_keywords
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


