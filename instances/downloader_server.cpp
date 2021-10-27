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
  if (argc < 3) {
    printf("need a port\n");
    return -1;
  }
  int port = std::stoi(argv[2]);
  if (argc < 4) {
    printf("need a file\n");
    return -1;
  }
  const char *filename = argv[3];

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
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }
  send_file(fp, new_sock);
  printf("[+]File data sent successfully.\n");

  //
  // close connection
  //
  close(new_sock);
  close(sockfd);

  return 0;
}
