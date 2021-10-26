#ifndef _EXTRA_COPYTOINTERFACE_HPP
#define _EXTRA_COPYTOINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/language/types.hpp>
#include <extras/rmi/RMIInterface.hpp>
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
