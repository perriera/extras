#ifndef _EXTRA_RMIINTERFACE_HPP
#define _EXTRA_RMIINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief RMIInterface
   *
   * Remote Method Invocation (RMI) Interface
   *
   */

  interface RMIInterface {
    virtual void action() pure;
  };

  interface RMIClientInterface extends RMIInterface {
    virtual void connect() pure;
  };

  interface RMIServerInterface extends RMIInterface {
    virtual void accept() pure;
  };

}  // namespace extras

#endif  // _EXTRA_RMIINTERFACE_HPP
