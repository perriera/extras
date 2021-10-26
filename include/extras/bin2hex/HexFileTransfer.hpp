#ifndef _EXTRA_HEXFILETRANSFER_HPP
#define _EXTRA_HEXFILETRANSFER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexInterface.hpp>
#include <extras/bin2hex/HexPacket.hpp>
#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
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

  /**
   * @brief HexFileTransferInterface
   *
   * Maintains a hex array in memory
   */
  interface UploaderInterface {
    virtual SocketInterface& socket() pure;
    virtual void upload(const HexPacket&) pure;
  };

  /**
   * @brief HexFileTransferInterface
   *
   * Maintains a hex array in memory
   */
  interface DownloaderInterface {
    virtual SocketInterface& socket() pure;
    virtual HexPacket download() pure;
  };

}  // namespace extras

#endif  // _EXTRA_HEXFILETRANSFER_HPP
