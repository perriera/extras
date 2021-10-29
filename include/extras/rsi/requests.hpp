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
    virtual void send_line(const std::string& request,
                           int serverSocket) const pure;
    virtual std::string read_line(int serverSocket) pure;
  };

  concrete class RSIServerImp implements RSIRequestInterface {
    PortAuthority _portAuthority;

   public:
    virtual void request(RSIInterface& requestedService,
                         const PortServerNumber& serverSocket) override;
    virtual void send_line(const std::string& request,
                           int serverSocket) const override;
    virtual std::string read_line(int serverSocket) override;
  };

  concrete class RSIClientImp implements RSIRequestInterface {
   public:
    virtual void request(RSIInterface& requestedService,
                         const PortServerNumber& serverSocket) override;
    virtual void send_line(const std::string& request,
                           int serverSocket) const override;
    virtual std::string read_line(int serverSocket) override;
  };

}  // namespace extras

#endif  // _EXTRA_RSIREQUESTS_HPP
