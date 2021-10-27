#ifndef _EXTRA_UPLOADER_HPP
#define _EXTRA_UPLOADER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/language/exceptions.hpp>
#include <extras/language/interfaces.hpp>
#include <extras/language/types.hpp>
#include <extras/sockets/SocketExceptions.hpp>
#include <extras/sockets/SocketPackets.hpp>
#include <iostream>
#include <string>

void send_file(FILE *fp, int sockfd);
void write_file(int sockfd);
int connect_to_server(const char *ip, int port,
                      struct sockaddr_in &server_addr);
int configure_serversocket(const char *ip, int port,
                           struct sockaddr_in &server_addr,
                           bool timeout = true);
void send_string(const std::string &msg, int sockfd);
std::string read_string(int sockfd);
int read_int(int sockfd);
std::string read_line(int sockfd);
void send_int(int msg, int sockfd);
void send_line(const std::string &msg, int sockfd);

static constexpr int const &SIZE = 1024 * 256;

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
