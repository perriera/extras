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

string(ASCII 27 Esc)
set(ColourReset "${Esc}[m")
set(ColourBold "${Esc}[1m")
set(Red "${Esc}[31m")
set(Green "${Esc}[32m")
set(Yellow "${Esc}[33m")
set(Blue "${Esc}[34m")
set(Magenta "${Esc}[35m")
set(Cyan "${Esc}[36m")
set(White "${Esc}[37m")
set(BoldRed "${Esc}[1;31m")
set(BoldGreen "${Esc}[1;32m")
set(BoldYellow "${Esc}[1;33m")
set(BoldBlue "${Esc}[1;34m")
set(BoldMagenta "${Esc}[1;35m")
set(BoldCyan "${Esc}[1;36m")
set(BoldWhite "${Esc}[1;37m")

function(print)
  list(GET ARGV 0 MessageType)
  if(MessageType STREQUAL FATAL_ERROR OR MessageType STREQUAL SEND_ERROR)
    list(REMOVE_AT ARGV 0)
    message(${MessageType} "${BoldRed}${ARGV}${ColourReset}")
  elseif(MessageType STREQUAL WARNING)
    list(REMOVE_AT ARGV 0)
    message(${MessageType} "${BoldYellow}${ARGV}${ColourReset}")
  elseif(MessageType STREQUAL AUTHOR_WARNING)
    list(REMOVE_AT ARGV 0)
    message(${MessageType} "${BoldCyan}${ARGV}${ColourReset}")
  elseif(MessageType STREQUAL STATUS)
    list(REMOVE_AT ARGV 0)
    message(${MessageType} "${Green}${ARGV}${ColourReset}")
  else()
    message("${ARGV}")
  endif()
endfunction()
