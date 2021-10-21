#ifndef _EXTRA_HEXFILETRANSFER_HPP
#define _EXTRA_HEXFILETRANSFER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexInterface.hpp>
#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/sockets/Socket.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief HexFileTransferInterface
   *
   * Maintains a hex array in memory
   */

  interface HexFileTransferInterface {
    virtual SocketInterface& socket() pure;
    virtual void transfer(const HexInterface&) pure;
  };

}  // namespace extras

#endif  // _EXTRA_HEXFILETRANSFER_HPP
