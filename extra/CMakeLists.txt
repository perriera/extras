 
add_library(
    extra SHARED
	include/extra/support.hpp
	include/extra/Definitions.hpp
	include/extra/colors.hpp
	include/extra/ansi_colors.hpp
	include/extra/ansi_input.hpp
	src/Definitions.cpp
	src/ansi_colors.cpp
	include/extra/crcs.hpp
	include/extra/crc16_support.hpp
	include/extra/crc32_support.hpp
	include/extra/crc64_support.hpp
	include/extra/octal_support.hpp
	src/crc16.cpp
	src/crc32.cpp
	src/crc64.cpp
	include/extra/files.hpp
	include/extra/Directory.hpp
	src/Directory.cpp
	include/extra/interfaces.hpp
	src/interfaces.cpp
	include/extra/keywords.hpp
	src/keywords.cpp
	include/extra/options.hpp    
	include/extra/docopt_private.h    
    include/extra/docopt_util.h         
    include/extra/docopt_value.h           
    include/extra/docopt.h  
    src/docopt.cpp  
    include/extra/strings.hpp
	include/extra/string_support.hpp
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
 	INTERFACE EXTRA_CRCS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)
# install(TARGETS extra)


