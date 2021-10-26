#ifndef _EXTRA_SOCKETPACKET_HPP
#define _EXTRA_SOCKETPACKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <extras/types.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief SocketPacketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface SocketPacketInterface {
    virtual const byte *array() const pure;
    virtual int size() const pure;
    virtual ~SocketPacketInterface(){};
  };

  /**
   * @brief SocketInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  concrete class SocketPacket implements SocketPacketInterface {
    byte *_array = nullptr;
    int _size = 0;

   public:
    SocketPacket(){};
    SocketPacket(byte *array, int size) : _size(size) {
      this->_array = new byte[size];
      for (int i = 0; i < _size; i++) this->_array[i] = array[i];
    }
    virtual ~SocketPacket() {
      if (_array != nullptr) {
        delete _array;
        _array = nullptr;
      }
    }
    virtual const byte *array() const { return _array; };
    virtual int size() const { return _size; };
  };

}  // namespace extras

#endif  // _EXTRA_SOCKETPACKET_HPP
