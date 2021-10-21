#ifndef _EXTRA_HEXPACKET_HPP
#define _EXTRA_HEXPACKET_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexInterface.hpp>
#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/types.hpp>
#include <iostream>
#include <vector>

namespace extras {

  /**
   * @brief HexInterface
   *
   * Maintains a hex array in memory
   */

  using HexLine = std::string;
  using HexArray = std::vector<std::string>;

  interface HexPacketInterface {
    virtual int index() const pure;
    virtual int count() const pure;
    virtual int rle() const pure;
    virtual const HexLine& line() const pure;
  };

  /**
   * @brief BinInterface
   *
   * Maintains a binrary array in memory
   */

  concrete class HexPacket implements HexPacketInterface {
    friend std::ostream& operator<<(std::ostream& out, const HexPacket& obj);
    friend std::istream& operator>>(std::istream& in, HexPacket& obj);

    HexLine _line;
    int _index;
    int _count;

   public:
    HexPacket(){};
    HexPacket(const HexLine& line, int index, int count)
        : _line(line), _index() {}

    virtual int index() const { return _index; };
    virtual int count() const { return _count; };
    virtual int rle() const { return _line.size(); };
    virtual const HexLine& line() const;
  };

}  // namespace extras

#endif  // _EXTRA_HEXPACKET_HPP
