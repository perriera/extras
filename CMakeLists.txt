#
# @brief The MIT License (MIT)
# @copyright © 2017 David Dumke, (strike5150@gmail.com)
# @ref https://www.linkedin.com/in/davidtjdumke/
#
# Permission  is  hereby  granted, free  of  charge, to  any person  obtaining
# a copy of this software and associated documentation files (the “Software”),
# to deal in the Software  without restriction,  including  without limitation
# the rights to  use,  copy,  modify,  merge, publish, distribute, sublicense,
# and/or sell  copies of the  Software,  and  to  permit  persons  to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice  and this permission  notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS  PROVIDED “AS IS”,  WITHOUT WARRANTY  OF ANY  KIND,  EXPRESS
# OR IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR  COPYRIGHT HOLDERS BE  LIABLE FOR ANY  CLAIM,  DAMAGES  OR  OTHER
# LIABILITY,  WHETHER IN  AN ACTION  OF CONTRACT,  TORT OR  OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#

#
# "determine required cmake here (use 'sudo snap install cmake') to get the 
# latest and greatest version, (regardless of platform)" -- Matt Williams, 2021
#
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

#
# PROJECT_VERSION is set in the header file: include/version.hpp
# You will need to manually keep that number in sync with the version
# numbers you manage in the changelog.md. That is, however you choose
# to manage your version management system. 
#

# include CPM.cmake https://github.com/cpm-cmake/CPM.cmake
include(cmake/CPM.cmake)
include(cmake/utils.cmake)
include(cmake/print.cmake)
include(cmake/Find32or64bit.cmake)
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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic --std=c++17 -fPIC -pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -fPIC -pthread")

# add additional project options
message(STATUS "MAKE_EXTRAS_LIBRARY_ONLY is ${MAKE_EXTRAS_LIBRARY_ONLY}")
if(MAKE_EXTRAS_LIBRARY_ONLY)
option(BUILD_TESTS "Build tests" OFF)
option(DEBUG "Debug Build" OFF)
message(STATUS "BUILD_TESTS is ${BUILD_TESTS}")
message(STATUS "DEBUG is ${DEBUG}")
else()
option(BUILD_TESTS "Build tests" ON)
option(DEBUG "Debug Build" ON)
message(STATUS "BUILD_TESTS is ${BUILD_TESTS}")
message(STATUS "DEBUG is ${DEBUG}")
endif()

# Build will default to debug
message(STATUS "edit your ~/.bashrc and set")
message(STATUS "export LD_LIBRARY_PATH=build:/usr/local/lib")
if(DEBUG)
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
else()
  set(CMAKE_BUILD_TYPE Release)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()

message(STATUS "======================== CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE} ===========================")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")

# Add local project module path so CMake includes custom CMake modules.
# https://gitlab.kitware.com/cmake/cmake/-/tree/a9affa07cdeea6b66c920e4826abfe59854f7ffa/
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

# CPMAddPackage(
#   NAME gcc-multilib
#   GIT_REPOSITORY http://archive.ubuntu.com/ubuntu/pool/main/g/gcc-defaults/gcc-defaults_1.185.1ubuntu2.tar.gz
#   VERSION 0.22.3
#   OPTIONS "MAKE_SPDLOG_SHARED OFF"
#   OPTIONS "MAKE_EXTRAS_LIBRARY_ONLY ON"
#   OPTIONS "MAKE_SQLUTIL_LIBRARY_ONLY ON"
# )
# if(sqlutil_ADDED)
#   #
#   # NOTE:  enable c++11 to avoid compilation errors, and force spdlog into release build
#   #
#   print(STATUS "Configuring sqlutil build properties")
#   # set_target_properties(sqlutil PROPERTIES CMAKE_BUILD_TYPE Release)
# else()
#   print(WARNING "sqlutil was not configured properly")
# endif()

# CPMAddPackage("gh:catchorg/Catch2@2.5.0")

# CPMAddPackage(
#   NAME catch2
#   GITHUB_REPO catchorg/Catch2
#   VERSION 2.5.0
#   EXCLUDE_FROM_ALL YES
# )

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

#
# NOTE: declare libraries here all source should be placed into a single library, (whether they be
# shared or static)
#

set(EXTRAS_LIBS_NEEDED stdc++fs)

if(MAKE32BIT)
  add_library(${PROJECT_NAME}_i386 SHARED ${EXTRAS_HEADERS} ${EXTRAS_SOURCE})
  target_include_directories(${PROJECT_NAME}_i386 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
  target_compile_options(${PROJECT_NAME}_i386 PUBLIC -m32)
  target_link_options(${PROJECT_NAME}_i386 PRIVATE -m32)
endif()

if(MAKE64BIT)
  add_library(${PROJECT_NAME} SHARED ${EXTRAS_HEADERS} ${EXTRAS_SOURCE})
  target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
endif()

# Create a target for executing the Catch2 unit tests.
if (NOT MAKE_EXTRAS_LIBRARY_ONLY)
  if(BUILD_TESTS)
    message(STATUS "Building interfaces")
    file(GLOB_RECURSE TESTS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/interfaces/*.cpp")
    #
    # run-unittests
    #
    if(MAKE32BIT)
      add_executable(run-unittests-extras_i386 ${TESTS})
      target_include_directories(run-unittests-extras_i386 PUBLIC test/)
      target_link_libraries(run-unittests-extras_i386 ${PROJECT_NAME}_i386 stdc++fs  ${CMAKE_THREAD_LIBS_INIT})
      target_compile_options(run-unittests-extras_i386 PUBLIC -m32)
      target_link_options(run-unittests-extras_i386 PRIVATE -m32)
    endif()
    if(MAKE64BIT)
      add_executable(run-unittests-extras ${TESTS})
      target_include_directories(run-unittests-extras PUBLIC test/)
      target_link_libraries(run-unittests-extras ${PROJECT_NAME} stdc++fs  ${CMAKE_THREAD_LIBS_INIT})
    endif()
  endif()
endif()

#
# TODO: declare example client usage application code here, this is where regression tests should
# ultimately be written. as well, this make file uses a GLOB_RECURSE macro which automatically 
# includes ALL headers and sources under include/ and src/. So, to keep two or more main() 
# declarations seperate, we place any sources that have a main() in the instances/ folder
#
if( NOT MAKE_EXTRAS_LIBRARY_ONLY OR MAKE_EXTRAS_LIBRARY_TOOLS)

  if (MAKE32BIT)
    add_executable(retag_i386 instances/retag.cpp) 
    target_include_directories(retag_i386 PUBLIC ${INCLUDES} ${ORACLE_INCLUDE})
    target_link_libraries(retag_i386 PRIVATE ${PROJECT_NAME}_i386 ${EXTRAS_LIBS_NEEDED})
    target_compile_options(retag_i386 PUBLIC -m32)
    target_link_options(retag_i386 PRIVATE -m32)
  endif()

  if (MAKE64BIT)
    add_executable(retag instances/retag.cpp) 
    target_include_directories(retag PUBLIC ${INCLUDES} ${ORACLE_INCLUDE})
    target_link_libraries(retag PRIVATE ${PROJECT_NAME} ${EXTRAS_LIBS_NEEDED})
  endif()

endif()

# Library Note: may not work on windows
if(MAKE32BIT)
  install(TARGETS ${PROJECT_NAME}_i386 LIBRARY DESTINATION lib)
endif()
if(MAKE64BIT)
  install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
endif()

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

if(MAKE32BIT)
  export(TARGETS ${PROJECT_NAME}_i386 FILE extrasConfig_i386.cmake)
endif()
if(MAKE64BIT)
  export(TARGETS ${PROJECT_NAME} FILE extrasConfig.cmake)
endif()

# if the compiler supports iter-procedural optimization, turn it on
check_ipo_supported(RESULT result OUTPUT output)
if(result)
  if(MAKE32BIT)
    set_target_properties(${PROJECT_NAME}_i386 PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
  endif()
  if(MAKE64BIT)
    set_target_properties(${PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
  endif()
  else()
  message(STATUS "IPO is not supported: ${output}")
endif()

if(MAKE32BIT)
  # Set version for shared libraries.
  set_target_properties(
    ${PROJECT_NAME}_i386 
      PROPERTIES VERSION ${${PROJECT_NAME}_VERSION} 
      SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
  )
endif()

if(MAKE64BIT)
  set_target_properties(
    ${PROJECT_NAME} 
      PROPERTIES VERSION ${${PROJECT_NAME}_VERSION} 
      SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
  )
endif()
