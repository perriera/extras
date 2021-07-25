 
add_library(
    extra_options SHARED
	include/extra/options.hpp    
	include/extra/docopt_private.h    
    include/extra/docopt_util.h         
    include/extra/docopt_value.h           
    include/extra/docopt.h  
    src/docopt.cpp  
)

target_link_libraries(extra_options 
    PRIVATE
        extra
)

target_compile_features(extra_options
	PUBLIC
		cxx_std_11
)

# Library
# Note: may not work on windows
install(TARGETS extra_options
    LIBRARY DESTINATION lib
)
# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/extra_options/include/extra
    DESTINATION include
)
target_include_directories(extra_options 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(extra_options 
 	INTERFACE EXTRA_STRINGS_VERSION=1
)
# Set version for shared libraries.
set_target_properties(extra_options
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)
