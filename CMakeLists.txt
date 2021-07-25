cmake_minimum_required(VERSION 3.5)
project(extras LANGUAGES CXX)
project(extras VERSION 0.1.1)

set(CMAKE_BUILD_TYPE Debug)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(extra)
add_subdirectory(docopt)
# add_subdirectory(frontdesk)

# add_library(helloworld_lib SHARED
#     include/HelloWorld/HelloWorld.hpp
# 	src/HelloWorld/HelloWorld.cpp
# )
# add_library(helloworld::library ALIAS helloworld_lib)

# target_include_directories(helloworld_lib
# 	PUBLIC
#         ${PROJECT_SOURCE_DIR}/include
# 		src
# )
# target_compile_options(helloworld_lib
# 	PRIVATE
# 		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
# 			 -Wall -Wextra>
# 		$<$<CXX_COMPILER_ID:MSVC>:
# 			/W4>
# )

#
# Create executable that uses the ChessMind lib to say Hello.
#
# add_executable(helloworld
# 	src/main.cpp
# )
# target_link_libraries(helloworld
# 	PRIVATE
# 	    helloworld::library 
# 		docopt
# 		extra
# )
# target_compile_options(helloworld
# 	PRIVATE
# 		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
# 			-Wall -Wextra>
# 		$<$<CXX_COMPILER_ID:MSVC>:
# 			/W4>
# )

#
# Create a target for executing the Catch2 unit tests.
#
add_executable(run-unittests
	test/main.cpp
	test/test_Directory.cpp
	test/test_FakeIt.cpp
#	test/test_HelloWorld.cpp
)
target_include_directories(run-unittests
	PUBLIC
		test/
)
target_link_libraries(run-unittests
 #  helloworld::library 
   extra
)
# -Werror
target_compile_options(run-unittests
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			  -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

############################################################
# Install
############################################################

# # Binaries
# install (TARGETS helloworld
#     DESTINATION bin)

# # Library
# # Note: may not work on windows
# install (TARGETS helloworld_lib
#     LIBRARY DESTINATION lib)

# # Header files
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
#     DESTINATION include)

# # Config
# install (FILES cmake-examples.conf
#     DESTINATION etc)

