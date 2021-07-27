 
add_library(extra_files SHARED
	include/extra/files.hpp
	include/extra/Directory.hpp
	src/Directory.cpp
)

# Library
# Note: may not work on windows
install(TARGETS extra_files
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_files/include/extra
    DESTINATION include
)
target_include_directories(extra_files 
 	PUBLIC 
	 "${CMAKE_CURRENT_SOURCE_DIR}/include"
	 "${CMAKE_CURRENT_SOURCE_DIR}/../extra_interfaces/include"
	 "${CMAKE_CURRENT_SOURCE_DIR}/../extra_strings/include"
)
target_compile_definitions(extra_files 
 	INTERFACE EXTRA_FILES_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_files
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

# install(TARGETS extra)


