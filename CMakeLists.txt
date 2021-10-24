# determine required cmake here (use 'pip install cmake') to get the latest and greates versin,
# regardless of platform
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# include CPM.cmake https://github.com/cpm-cmake/CPM.cmake
include(cmake/CPM.cmake)
include(cmake/utils.cmake)
include(CMakeDependentOption)
include(CheckIPOSupported)


# generate compile_commands.json, this is for text editors (emacs, vim) that don't want to rely on
# Micro$ofts lang server
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
extras_get_version()

project(
  extras
  VERSION ${EXTRAS_VERSION}
  LANGUAGES CXX
)
message(STATUS "Building extras-${EXTRAS_VERSION}")

find_package (Threads REQUIRED)

# These includes will only work after LANGUAGES is defined.
include(GNUInstallDirs)
include(CheckIPOSupported)

# Prevent in source builds
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In source builds are not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# Set C/C++ parameters for all targets in this CMakeLists.txt
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic --std=c++17 -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -fPIC")

# add additional project options
option(BUILD_TESTS "Build tests" ON)
option(DEBUG "Debug Build" ON)

# Build will default to debug
if(DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
  message(STATUS "edit your ~/.bashrc and set")
  message(STATUS "export LD_LIBRARY_PATH=build:/usr/local/lib")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
else()
  set(CMAKE_BUILD_TYPE Release)
  message(STATUS "edit your ~/.bashrc and set")
  message(STATUS "export LD_LIBRARY_PATH=/usr/local/lib")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")

# Add local project module path so CMake includes custom CMake modules.
# https://gitlab.kitware.com/cmake/cmake/-/tree/a9affa07cdeea6b66c920e4826abfe59854f7ffa/
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

# # Add spdlog which includes fmt library as well (two for one) This should install on the system when
# # extras in included in another project
# CPMAddPackage(
#   GITHUB_REPOSITORY gabime/spdlog
#   VERSION 1.9.1
#   OPTIONS "SPDLOG_BUILD_SHARED ON" "SPDLOG_BUILD_EXAMPLE OFF" "SPDLOG_BUILD_TESTS OFF"
#           "SPDLOG_BUILD_EXAMPLE OFF" "SPDLOG_ENABLE_PCH ON" "SPDLOG_INSTALL ON"
# )

# HACK: It is technically bad practice to glob files, as the build tree might not update if a new
# file is added or removed, for this reason it is recommended to rm -rf the build folder and rebuild
# from scratch if files are added or removed

# glob extras header files
file(GLOB_RECURSE EXTRAS_HEADERS CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.hpp"
)

# glob extras src files
file(GLOB_RECURSE EXTRAS_SOURCE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${EXTRAS_HEADERS} ${EXTRAS_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Create a target for executing the Catch2 unit tests.
if(BUILD_TESTS)
  message(STATUS "Building tests")
  file(GLOB_RECURSE TESTS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")
  add_executable(run-unittests-extras ${TESTS})
  target_include_directories(run-unittests-extras PUBLIC test/)
  target_link_libraries(run-unittests-extras ${PROJECT_NAME} stdc++fs  ${CMAKE_THREAD_LIBS_INIT})
endif()

# Library Note: may not work on windows
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

export(TARGETS ${PROJECT_NAME} FILE extrasConfig.cmake)

#
# FreeFormJS client
#
add_executable(client instances/client.cpp) 
target_include_directories(client PUBLIC ${INCLUDES})
target_link_libraries(client PRIVATE ${PROJECT_NAME} stdc++fs )

#
# FreeFormJS server
#
add_executable(server instances/server.cpp) 
target_include_directories(server PUBLIC ${INCLUDES})
target_link_libraries(server PRIVATE ${PROJECT_NAME} stdc++fs )

#
# FreeFormJS test_server
#
add_executable(test_server instances/test_server.cpp) 
target_include_directories(test_server PUBLIC ${INCLUDES})
target_link_libraries(test_server PRIVATE ${PROJECT_NAME} stdc++fs extras)

#
# FreeFormJS test_client
#
add_executable(test_client instances/test_client.cpp) 
target_include_directories(test_client PUBLIC ${INCLUDES})
target_link_libraries(test_client PRIVATE ${PROJECT_NAME} stdc++fs extras)


# if the compiler supports iter-procedural optimization, turn it on
check_ipo_supported(RESULT result OUTPUT output)
if(result)
  set_target_properties(${PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
  message(STATUS "IPO is not supported: ${output}")
endif()

# Set version for shared libraries.
set_target_properties(
  ${PROJECT_NAME} PROPERTIES VERSION ${${PROJECT_NAME}_VERSION} SOVERSION
                                                                ${${PROJECT_NAME}_VERSION_MAJOR}
)
