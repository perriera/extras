#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/sockets/Requests.hpp>
#include <extras/uploader/UploaderInterface.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 5) {
    std::cout << "params: ip port service filename" << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, service, filename, ip;
  int port;
  ss >> prg >> ip >> port >> service >> filename;

  //
  // make connection
  //
  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip.c_str(), port, server_addr);

  //
  // do business
  //
  extras::RequestedService serviceName = service;
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
