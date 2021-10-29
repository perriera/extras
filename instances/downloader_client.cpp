#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/subsystem/RSISubsystem.hpp>
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
  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip.c_str(), port, server_addr);

  //
  // do business
  //
  write_file(filename.c_str(), sockfd);
  printf("[+]Data written in the file successfully.\n");

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
