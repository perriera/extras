#
# @brief The MIT License (MIT)
# @copyright © 2023 Perry Anderson, (perry@exparx.ca)
# @ref https://github.com/perriera
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
# Determining 32 or 64 (and/or both) from environment variables
# 
# Notes on INTEL 32 BIT SUPPORT 
#
# By default the perriera/extras shared libraries and the perriera/extras_cpp template
# will compile to a 64bit platform. In modern applications this is rarely an issue. 
# But in the case were older architectures require 32bit support or perhaps dual 32bit
# and 64bit targets (simultaneously) all that needs to be done to build for the desired
# platforms are to set EITHER (not both) MAKE64BITONLY or MAKE32BITONLY, (see lines 21/22).
#
# In the case where GitHub.com testing is required these libraries will select 64bit.
#
# In the case where both MAKE64BITONLY and MAKE32BITONLY is desired COMMENT OUT BOTH.
#
# FOR PROPER INCLUSION via CPM see lines 120-142 of CMakeLists.txt 
# of perriera/extras_cpp
#

include(cmake/print.cmake)

set(IS_GITHUB_ENV $ENV{GITHUB_ENV})

if (IS_GITHUB_ENV)
print(STATUS "GITHUB_ENV detected")
set(MAKE64BITONLY 1)
unset(MAKE32BITONLY)
else()
#unset(MAKE32BITONLY)
# set(MAKE64BITONLY 1)
# set(MAKE32BITONLY 1)
endif()

if (NOT MAKE32BITONLY AND NOT MAKE64BITONLY)
  print(STATUS "neither MAKE32BITONLY or MAKE64BITONLY detected")
endif()

if (MAKE32BITONLY AND MAKE64BITONLY)
  print(STATUS "both MAKE32BITONLY and MAKE64BITONLY requested")
  message( FATAL_ERROR "only MAKE32BITONLY or MAKE64BITONLY can be set at the same time" )
endif()

set(MAKE32BIT 1)
set(MAKE64BIT 1)

if (MAKE32BITONLY)
  unset(MAKE64BIT)
endif()

if (MAKE64BITONLY)
  unset(MAKE32BIT)
endif()

if (MAKE32BIT)
  print(STATUS "32bit make requested: build/libextras_i386.so")
endif()

if (MAKE64BIT)
  print(STATUS "64bit make requested: build/libextras.so")
endif()
