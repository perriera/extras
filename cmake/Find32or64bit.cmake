#
# Determining 32 or 64 (and/or both) from environment variables
# 

include(cmake/print.cmake)

set(IS_GITHUB_ENV $ENV{GITHUB_ENV})

#if (IS_GITHUB_ENV)
#print(STATUS "GITHUB_ENV detected")
#set(MAKE64BITONLY 1)
#unset(MAKE32BITONLY)
#else()
#unset(MAKE32BITONLY)
#set(MAKE64BITONLY 1)
#set(MAKE32BITONLY 1)
#endif()

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
