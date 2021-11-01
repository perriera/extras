#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/requests.hpp>
#include <extras/rsi/subsystem.hpp>
#include <extras/sockets/Requests.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 5) {
    std::cout << "params: ip port service filename client [-async]"
              << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, service, filename, ip, sync;
  int port;
  ss >> prg >> ip >> port >> service >> filename;
  ss >> sync;
  bool async = (sync == "-async");

  //
  // make connection to socket server
  //
  struct sockaddr_in server_addr;
  int sockfd = extras::rsi::connect_to_server(ip.c_str(), port, server_addr);

  //
  // do business
  //
  extras::RSIMacro macro(filename, ip, port, async, service);
  extras::RSIClientImp rsi_client;
  rsi_client.request(macro, sockfd);

  printf("[+]ServerService Invoked '%s'\n", macro.server().c_str());
  printf("[+]ClientService Invoked '%s'\n", macro.client().c_str());
  system(macro.client().c_str());

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
