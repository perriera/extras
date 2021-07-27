cmake_minimum_required(VERSION 3.5)
project(extras LANGUAGES CXX)
project(extras VERSION 2.1.0)

# add_subdirectory(colors)

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
endif()

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(extra_keywords)
add_subdirectory(extra)
add_subdirectory(extra_colors)
add_subdirectory(extra_crcs)
add_subdirectory(extra_strings)
add_subdirectory(extra_options)
add_subdirectory(extra_files)

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
   extra_crcs
   extra_colors
   extra_files
   extra_keywords
   extra_strings
)
# -Werror
target_compile_options(run-unittests
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			  -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)
