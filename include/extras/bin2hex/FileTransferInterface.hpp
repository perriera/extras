#ifndef _EXTRA_FILETRANSFER_HPP
#define _EXTRA_FILETRANSFER_HPP

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
  interface FileTransferInterface {
    virtual void upload(const HexInterface&, SocketInterface& socket) pure;
    // virtual void inquire(const HexInterface&, SocketInterface& socket) pure;
    virtual HexArray download(SocketInterface& socket) pure;
  };

  /**
   * @brief HexFileTransferInterface
   *
   * Maintains a hex array in memory
   */
  concrete class FileTransfer implements FileTransferInterface {
    HexArray _echo;

   public:
    virtual void upload(const HexInterface&, SocketInterface& socket) override;
    // virtual void inquire(const HexInterface&, SocketInterface& socket) pure;
    virtual HexArray download(SocketInterface& socket) override;

    operator const HexArray&() { return _echo; }
  };

}  // namespace extras

#endif  // _EXTRA_FILETRANSFER_HPP
