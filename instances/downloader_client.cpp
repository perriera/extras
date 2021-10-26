#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("need an ip\n");
    return -1;
  }
  const char *ip = argv[1];
  int port = 8080;

  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip, port, server_addr);
  //
  //
  //

  write_file(sockfd);
  printf("[+]Data written in the file successfully.\n");

  //
  //
  //

  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
