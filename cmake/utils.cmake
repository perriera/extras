function(extras_get_version)
  file(READ "${CMAKE_CURRENT_LIST_DIR}/include/extras/version.hpp" file_contents)
  string(REGEX MATCH "EXTRAS_VER_MAJOR ([0-9]+)" _ "${file_contents}")
  if(NOT CMAKE_MATCH_COUNT EQUAL 1)
    message(FATAL_ERROR "Could not extract the major version from extras/version.hpp")
  endif()
  set(ver_major ${CMAKE_MATCH_1})

  string(REGEX MATCH "EXTRAS_VER_MINOR ([0-9]+)" _ "${file_contents}")
  if(NOT CMAKE_MATCH_COUNT EQUAL 1)
    message(FATAL_ERROR "Could not extract the minor version from extras/version.hpp")
  endif()
  set(ver_minor ${CMAKE_MATCH_1})

  string(REGEX MATCH "EXTRAS_VER_PATCH ([0-9]+)" _ "${file_contents}")
  if(NOT CMAKE_MATCH_COUNT EQUAL 1)
    message(FATAL_ERROR "Could not extract the patch version from extras/version.hpp")
  endif()
  set(ver_patch ${CMAKE_MATCH_1})

  set(EXTRAS_VERSION_MAJOR
      ${ver_major}
      PARENT_SCOPE
  )
  set(EXTRAS_VERSION_MINOR
      ${ver_minor}
      PARENT_SCOPE
  )
  set(EXTRAS_VERSION_PATCH
      ${ver_patch}
      PARENT_SCOPE
  )

  set(EXTRAS_VERSION
      "${ver_major}.${ver_minor}.${ver_patch}"
      PARENT_SCOPE
  )
endfunction()
