#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 4) {
    std::cout << "params: filename ip port" << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, filename, ip;
  int port;
  ss >> prg >> filename >> ip >> port;

  //
  // make connection
  //
  int sockfd;
  struct sockaddr_in server_addr;
  sockfd = configure_serversocket(ip.c_str(), port, server_addr);

  struct sockaddr_in new_addr;
  socklen_t addr_size = sizeof(new_addr);
  int new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
  if (new_sock == -1) {
    perror("[-]Timeout on uploader_server accept");
    close(sockfd);
    exit(1);
  }

  //
  // do business
  //
  write_file(filename.c_str(), new_sock);
  printf("[+]Data written in the file successfully.\n");

  //
  // close connection
  //
  close(new_sock);
  close(sockfd);

  return 0;
}
