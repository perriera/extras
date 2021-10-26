#ifndef _EXTRA_CSOCKET_HPP
#define _EXTRA_CSOCKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/sockets/Socket.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class CSocket implements SocketInterface {
    int _socket;
    byte *_readMsg = nullptr;
    int _readMsgSize;

   public:
    CSocket(int socket);
    virtual ~CSocket() {
      if (_readMsg != nullptr) {
        delete _readMsg;
        _readMsg = nullptr;
      }
    }
    virtual void send(const std::string &msg) override;
    virtual SocketInterface &read(int expectedMaxSize = 1024) override;
    operator std::string() const override;
    operator SocketPacket() const override;
  };

}  // namespace extras

#endif  // _EXTRA_SOCKET_HPP
