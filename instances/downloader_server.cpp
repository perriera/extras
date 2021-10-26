#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>

int configure_serversocket(const char *ip, int port,
                           struct sockaddr_in &server_addr) {
  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

  // Forcefully attaching socket to the port 8080
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  int e = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (e < 0) {
    perror("[-]Error in bind");
    exit(1);
  }
  printf("[+]Binding successfull.\n");

  if (listen(sockfd, 10) == 0) {
    printf("[+]Listening....\n");
  } else {
    perror("[-]Error in listening");
    exit(1);
  }
  return sockfd;
}

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("need an ip\n");
    return -1;
  }
  const char *ip = argv[1];
  int port = 8080;

  int sockfd;
  struct sockaddr_in server_addr;

  sockfd = configure_serversocket(ip, port, server_addr);

  struct sockaddr_in new_addr;
  socklen_t addr_size = sizeof(new_addr);
  int new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);

  //
  //
  //

  const char *filename = "send.txt";
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }

  send_file(fp, new_sock);
  printf("[+]File data sent successfully.\n");
  close(new_sock);
  close(sockfd);

  //
  //
  //

  return 0;
}
