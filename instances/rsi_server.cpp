#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/RSIInterface.hpp>
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

  //
  // make connection
  //
  int sockfd;
  struct sockaddr_in server_addr;
  sockfd = configure_serversocket(ip.c_str(), port, server_addr, false);

  extras::RSIServerImp rsi_server;

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
    // form RSI macro
    //
    extras::RSIMacro macro;
    rsi_server.request(macro, new_sock);

    //
    // do business
    //
    // extras::RequestedService serviceName = services.request(new_sock);
    // extras::PortNumber port_to_use = services.lastPortRequested();
    printf("[+]Sent port to use: %i.\n", macro.port());

    // rsi_server.request()

    //
    // form command
    //
    // std::stringstream ss_cmd;
    // ss_cmd <<

    // std::string actualServiceName = serviceName;
    // std::string cmd =
    //     serviceName + " " + ip + " " + std::to_string(port_to_use);
    // if (!not_server_async) cmd += " &";
    // if (extras::contains(cmd, "&")) {
    //   cmd = extras::replace_all(cmd, "ip", ip);
    //   cmd = extras::replace_all(cmd, "port", std::to_string(port));
    // }
    printf("[+]RequestedService '%s' Invoked\n", macro.server().c_str());
    // system(macro.server().c_str());
    close(new_sock);
  }
  //
  // close connection
  //
  close(sockfd);

  return 0;
}
