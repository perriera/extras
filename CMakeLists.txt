#
# determine required cmake here
# (use 'pip install cmake')
#
cmake_minimum_required(VERSION 3.21)

#
# determine PROJECT parameters here
# manually keep version numbers in sync 
# with the changelog.md and github
#
project(extras LANGUAGES CXX)
project(extras VERSION 2.7.0)

#
# Set C/C++ parameters for all targets in this CMakeLists.txt
#
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra --std=c++17 -fPIC" )
set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -fPIC" )

#
# determine DEBUG/PRODUCTION installation here
# install -d build; cd build; cmake ..; make
# install -d build; cd build; cmake -DPRODUCTION=true ..; make
#

# first check
set(ignoreMe "${PRODUCTION}")
if(NOT DEFINED PRODUCTION)
	set(CMAKE_BUILD_TYPE Debug)
	message(STATUS "DEBUG BUILD")
	message(STATUS "edit your ~/.bashrc and set")
	message(STATUS "export LD_LIBRARY_PATH=build:/usr/local/lib")
else()
	message(STATUS "PRODUCTION BUILD")
	message(STATUS "edit your ~/.bashrc and set")
	message(STATUS "export LD_LIBRARY_PATH=/usr/local/lib")
	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3" )
	set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -O3" )
endif()
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")

# Add local project module path so CMake includes custom CMake modules.
# https://gitlab.kitware.com/cmake/cmake/-/tree/a9affa07cdeea6b66c920e4826abfe59854f7ffa/
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_library(extras 
SHARED
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
	src/crc.cpp
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
target_include_directories(extras 
 	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

#
# Create a target for executing the Catch2 unit tests.
#
add_executable(run-unittests-extras
	test/main.cpp
	test/test_Directory.cpp
	test/test_FakeIt.cpp
	test/test_crc32.cpp
	test/test_crc64.cpp
	test/test_crcs.cpp
)
target_include_directories(run-unittests-extras
	PUBLIC
		test/
)
target_link_libraries(run-unittests-extras
	extras
   	stdc++fs 
)

include(CMakeDependentOption)
include(GNUInstallDirs)

# Library
# Note: may not work on windows
install(TARGETS extras
    LIBRARY DESTINATION lib
)

# Header files
install(DIRECTORY 
	${PROJECT_SOURCE_DIR}/include/
    DESTINATION include
)

# install(EXPORT ${targets_export_name}
# NAMESPACE ${cmake_package_name}::
# DESTINATION ${cmake_files_install_dir})

export(
	TARGETS extras
	FILE extrasConfig.cmake
)

# Set version for shared libraries.
set_target_properties(extras
	PROPERTIES
	VERSION ${${PROJECT_NAME}_VERSION}
	SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)


# install(TARGETS extra)

