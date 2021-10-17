#ifndef _EXTRA_SOCKETEXCEPTIONS_HPP
#define _EXTRA_SOCKETEXCEPTIONS_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class SocketException extends AbstractCustomException {
   public:
    SocketException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertLTZ(int socket, const std::string &msg,
                          const WhereAmI &ref);
    static void assertLTEQZ(int socket, const std::string &msg,
                            const WhereAmI &ref);
    static void assertZERO(int socket, const std::string &msg,
                           const WhereAmI &ref);
    static void assertNEQZ(int socket, const std::string &msg,
                           const WhereAmI &ref);
  };

}  // namespace extras

#endif  // _EXTRA_SOCKETEXCEPTIONS_HPP
