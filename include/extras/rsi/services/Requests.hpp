#ifndef _EXTRA_RSIREQUESTS_HPP
#define _EXTRA_RSIREQUESTS_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <iostream>
#include <sstream>

namespace extras {

  /**
   * @brief RSIRequestInterface
   *
   * Remote Service Invocation (RSI) Interface
   *
   */

  interface RSIRequestInterface {
    virtual void request(RSIInterface& requestedService,
                         const PortServerNumber& serverSocket) pure;
  };

  concrete class RSIServerImp implements RSIRequestInterface {
    PortAuthority _portAuthority;

   public:
    virtual void request(RSIInterface& requestedService,
                         const PortServerNumber& serverSocket) override;
  };

  concrete class RSIClientImp implements RSIRequestInterface {
   public:
    virtual void request(RSIInterface& requestedService,
                         const PortServerNumber& serverSocket) override;
  };

}  // namespace extras

#endif  // _EXTRA_RSIREQUESTS_HPP
