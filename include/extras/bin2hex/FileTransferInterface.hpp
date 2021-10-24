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
    virtual void upload(const HexInterface&, SocketInterface& socket) pure;
    virtual void inquire(const HexInterface&, SocketInterface& socket) pure;
    virtual void download(const HexInterface&, SocketInterface& socket) pure;
  };

}  // namespace extras

#endif  // _EXTRA_FILETRANSFER_HPP
