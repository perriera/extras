#ifndef _EXTRA_INPUTSTREAM_HPP
#define _EXTRA_INPUTSTREAM_HPP

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface InputStreamInterface {
    friend bool operator==(const InputStreamInterface&,
                           const InputStreamInterface&) {
      return true;
    }
    friend bool operator!=(const InputStreamInterface& lhs,
                           const InputStreamInterface& rhs) {
      return !(lhs == rhs);
    }
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class InputStream implements InputStreamInterface {};

  /**
   * @brief OctalException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class InputStreamException extends AbstractCustomException {
   public:
    InputStreamException(const char* msg, const WhereAmI& whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string& hostname, int port,
                          const WhereAmI& ref);
  };

}  // namespace extras

#endif  // _EXTRA_INPUTSTREAM_HPP
