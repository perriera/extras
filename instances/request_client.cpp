#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/sockets/Requests.hpp>
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
  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip, port, server_addr);

  //
  // do business
  //
  extras::RequestedService serviceName = "upload";
  extras::Requests requests;
  extras::PortNumber port_to_use = requests.request(serviceName, sockfd);
  printf("[+]RequestedService '%s' Invoked on port: %i.\n", serviceName.c_str(),
         port_to_use);

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
