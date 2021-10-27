#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "extras/sockets/Services.hpp"
extras::Services services;

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 3) {
    std::cout << "params: ip port" << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, ip;
  int port;
  ss >> prg >> ip >> port;

  //
  // make connection
  //
  int sockfd;
  struct sockaddr_in server_addr;
  sockfd = configure_serversocket(ip.c_str(), port, server_addr, false);

  for (int i = 0; i < 1000; i++) {
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
    extras::RequestedService serviceName = services.request(new_sock);
    extras::PortNumber port_to_use = services.lastPortRequested();
    printf("[+]Sent port to use: %i.\n", port_to_use);
    std::string actualServiceName = serviceName;
    std::string cmd = serviceName + " &";
    std::string logFile = "RequestedService_" + serviceName + "_state.txt";
    {
      std::ofstream logit(logFile);
      logit << "requesting" << std::endl;
    }
    system(cmd.c_str());
    {
      std::ofstream logit(logFile);
      logit << "requested" << std::endl;
    }
    printf("[+]RequestedService '%s' Invoked on: %i.\n", serviceName.c_str(),
           port_to_use);
    close(new_sock);
  }
  //
  // close connection
  //
  close(sockfd);

  return 0;
}
