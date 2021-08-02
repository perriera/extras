cmake_minimum_required(VERSION 3.5)
project(extras LANGUAGES CXX)
project(extras VERSION 2.3.3)

# add_subdirectory(colors)
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra --std=c++17 -fPIC" )
set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -fPIC" )

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
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(extra)

#
# Create a target for executing the Catch2 unit tests.
#
add_executable(run-unittests
	test/main.cpp
	test/test_Directory.cpp
	test/test_FakeIt.cpp
	test/test_crc32.cpp
	test/test_crc64.cpp
)
target_include_directories(run-unittests
	PUBLIC
		test/
)
target_link_libraries(run-unittests
   extra
   stdc++fs 
)
