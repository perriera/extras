#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/RSIInterface.hpp>
#include <extras/rsi/subsystem/RSISubsystem.hpp>
#include <extras/strings.hpp>
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
    std::cout << "params: ip port [-server_async]" << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, ip, server_sync;
  int port;
  ss >> prg >> ip >> port;
  ss >> server_sync;
  // bool not_server_async = (server_sync == "-server_async");

  int sockfd;
  struct sockaddr_in server_addr;
  sockfd = configure_serversocket(ip.c_str(), port, server_addr, false);

  extras::RSIServerImp rsi_server;

  for (int i = 0; i < 1000; i++) {
    //
    // make connection to socket client
    //
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
    extras::RSIMacro macro;
    rsi_server.request(macro, new_sock);
    printf("[+]Sent port to use: %i.\n", macro.port());
    printf("[+]RequestedService '%s' Invoked\n", macro.server().c_str());

    close(new_sock);
  }
  //
  // close connection
  //
  close(sockfd);

  return 0;
}
