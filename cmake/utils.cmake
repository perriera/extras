
#
# @brief The MIT License (MIT)
# @copyright © 2021 Matt Williams, (mattltf@protonmail.com)
# @ref https://github.com/thebashpotato
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
