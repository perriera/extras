#ifndef _EXTRA_COPYTOINTERFACE_HPP
#define _EXTRA_COPYTOINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/rmi/RMIInterface.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief class CopyTo
   *
   * Remote Method Invocation (RMI) Interface
   *
   */

  concrete class CopyTo implements RMIInterface {
    virtual void action() override;
  };

}  // namespace extras

#endif  // _EXTRA_COPYTOINTERFACE_HPP
