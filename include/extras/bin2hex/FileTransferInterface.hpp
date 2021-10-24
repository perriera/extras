#ifndef _EXTRA_FILETRANSFER_HPP
#define _EXTRA_FILETRANSFER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexInterface.hpp>
#include <extras/bin2hex/HexPacket.hpp>
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
  interface FileTransferInterface {
    // virtual SocketInterface& socket() pure;
    // virtual void transfer(const HexInterface&) pure;
  };

}  // namespace extras

#endif  // _EXTRA_FILETRANSFER_HPP
