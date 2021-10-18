#ifndef _EXTRA_FILETRANSFER_HPP
#define _EXTRA_FILETRANSFER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/bin2hex/HexFile.hpp>
#include <extras/bin2hex/HexInterface.hpp>
#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
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
    virtual void transfer(const HexFile&) pure;
    virtual const HexArray& lines() const pure;
    virtual int size() const pure;
  };

}  // namespace extras

#endif  // _EXTRA_FILETRANSFER_HPP
