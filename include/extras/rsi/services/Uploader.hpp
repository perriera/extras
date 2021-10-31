#ifndef _EXTRA_RSISERVICES_UPLOADER_HPP
#define _EXTRA_RSISERVICES_UPLOADER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {
    /**
     * @brief RSIRequestInterface
     *
     * Remote Service Invocation (RSI) Interface
     *
     */

    using Parameter = std::string;
    using Parameters = std::deque<Parameter>;

    interface UploaderInterface {
      virtual Parameters parameters(int argc, char const *argv[]) pure;
    };
  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISERVICES_UPLOADER_HPP
