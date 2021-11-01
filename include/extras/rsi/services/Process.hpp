#ifndef _EXTRA_RSISERVICES_PROCESS_HPP
#define _EXTRA_RSISERVICES_PROCESS_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace extras {
  namespace rsi {
    /**
     * @brief UploaderInterface
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */

    interface ProcessInterface {
      /**
       * @brief process()
       * @note collect the parameters required for the Uploader from the
       * tradional C/C++ main() arguments.
       */
      virtual void process() const pure;
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISERVICES_PROCESS_HPP
