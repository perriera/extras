#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>
#include <string>

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
  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip, port, server_addr);

  //
  // do business
  //
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }
  send_file(fp, sockfd);
  printf("[+]File data sent successfully.\n");

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
