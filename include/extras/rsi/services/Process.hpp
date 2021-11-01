#ifndef _EXTRA_RSISERVICES_PROCESS_HPP
#define _EXTRA_RSISERVICES_PROCESS_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace extras {
  namespace rsi {
    /**
     * @brief ProcessInterface
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

    /**
     * @brief ProcessClient
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    concrete class ProcessClient extends UploaderClient {
     public:
      virtual void transfer() const override;
    };

    /**
     * @brief ProcessServer
     *
     *   build/rsi_client 127.0.0.1 8080 transfer send.txt
     *   ss >> prg >> filename >> ip >> port;ProcessServer
     *
     */
    concrete class ProcessServer extends UploaderServer {
     public:
      virtual void transfer() const override;
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISERVICES_PROCESS_HPP
