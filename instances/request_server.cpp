#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/strings.hpp>
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
    std::cout << "params: ip port [-server_nsync]" << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, ip, server_sync;
  int port;
  ss >> prg >> ip >> port;
  ss >> server_sync;
  bool server_nsync = (server_sync == "-server_nsync");

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
      perror("[-]Timeout on request_server accept");
      close(sockfd);
      exit(1);
    }

    //
    // do business
    //
    extras::RequestedService serviceName = services.request(new_sock);
    extras::PortNumber port_to_use = services.lastPortRequested();
    printf("[+]Sent port to use: %i.\n", port_to_use);
    //
    // form command
    //
    // std::stringstream ss_cmd;
    // ss_cmd <<

    std::string actualServiceName = serviceName;
    std::string cmd =
        serviceName + " " + ip + " " + std::to_string(port_to_use);
    if (!server_nsync) serviceName += " &";
    if (extras::contains(cmd, "&")) {
      cmd = extras::replace_all(cmd, "ip", ip);
      cmd = extras::replace_all(cmd, "port", std::to_string(port));
    }
    system(cmd.c_str());
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
