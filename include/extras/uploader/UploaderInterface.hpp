#ifndef _EXTRA_UPLOADER_HPP
#define _EXTRA_UPLOADER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <extras/sockets/SocketPackets.hpp>
#include <extras/types.hpp>
#include <iostream>

void send_file(FILE *fp, int sockfd);
void write_file(int sockfd);
int connect_to_server(const char *ip, int port,
                      struct sockaddr_in &server_addr);

namespace extras {

  /**
   * @brief UploaderInterface
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  interface FileSendWriteInterface {
    virtual void write_file(int sockfd) pure;
    virtual void send_file(FILE *fp, int sockfd) pure;
  };

  interface FileUploaderInterface extends FileSendWriteInterface {
    // virtual void write_file(int sockfd) pure;
    // virtual void send_file(FILE *fp, int sockfd) pure;
  };

  interface FileDownloaderInterface extends FileSendWriteInterface {
    // virtual void write_file(int sockfd) pure;
    // virtual void send_file(FILE *fp, int sockfd) pure;
  };

}  // namespace extras

#endif  // _EXTRA_UPLOADER_HPP