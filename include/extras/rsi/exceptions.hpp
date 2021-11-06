#ifndef _EXTRA_RSIEXCEPTIONS_HPP
#define _EXTRA_RSIEXCEPTIONS_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>

namespace extras {

  /**
   * @brief SocketException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class RSIException extends AbstractCustomException {
   public:
    RSIException(const char *msg, const WhereAmI &whereAmI)
        : AbstractCustomException(msg, whereAmI._file.c_str(),
                                  whereAmI._func.c_str(), whereAmI._line) {}
    static void assertion(const std::string &msg, const WhereAmI &ref);
  };

  /**
   * @brief SocketException
   *
   * To be thrown if either string or value supplied is out of range.
   *
   */
  concrete class RSIRemoteException extends RSIException {
   public:
    RSIRemoteException(const char *msg, const WhereAmI &whereAmI)
        : RSIException(msg, whereAmI) {}
    static void assertion(const std::string &msg, const WhereAmI &ref);
  };

}  // namespace extras

#endif  // _EXTRA_RSIEXCEPTIONS_HPP
