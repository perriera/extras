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
     * @brief UploaderInterface
     *
     *   build/rsi_client 127.0.0.1 8080 upload send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */

    using Parameter = std::string;
    using Parameters = std::deque<Parameter>;

    interface UploaderInterface {
      virtual Parameters parameters(int argc, char const* argv[]) pure;
      virtual const Parameter& program() const pure;
      virtual const Parameter& filename() const pure;
      virtual const Parameter& ip() const pure;
      virtual const Parameter& port() const pure;
    };
  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISERVICES_UPLOADER_HPP
