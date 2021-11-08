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

  namespace rsi {
    /**
     * @brief SocketException
     *
     * To be thrown if either string or value supplied is out of range.
     *
     */
    concrete class UnsupportedTokenException extends RSIException {
     public:
      UnsupportedTokenException(std::string msg, const WhereAmI &whereAmI)
          : RSIException(msg.c_str(), whereAmI) {}
      static void assertion(const std::string &msg, const WhereAmI &ref) {
        if (msg.length() == 0) throw UnsupportedTokenException(msg, ref);
      }
    };

    concrete class NoTokensException extends RSIException {
     public:
      NoTokensException(const WhereAmI &whereAmI)
          : RSIException("No tokens were specified", whereAmI) {}
      static void assertion(int size, const WhereAmI &ref) {
        if (size == 0) throw NoTokensException(ref);
      }
    };

  }  // namespace rsi

}  // namespace extras

#endif  // _EXTRA_RSIEXCEPTIONS_HPP
