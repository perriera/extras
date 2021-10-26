#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 2) {
    printf("need an ip\n");
    return -1;
  }
  const char *ip = argv[1];
  int port = 8080;

  //
  // make connection
  //
  int sockfd;
  struct sockaddr_in server_addr;
  sockfd = configure_serversocket(ip, port, server_addr);

  struct sockaddr_in new_addr;
  socklen_t addr_size = sizeof(new_addr);
  int new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
  if (new_sock == -1) {
    perror("[-]Timeout on accept");
    close(sockfd);
    exit(1);
  }

  //
  // do business
  //
  write_file(new_sock);
  printf("[+]Data written in the file successfully.\n");

  //
  // close connection
  //
  close(new_sock);
  close(sockfd);

  return 0;
}
