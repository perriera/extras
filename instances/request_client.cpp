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
  if (argc < 6) {
    std::cout << "params: ip port service filename client [-nsync]"
              << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, service, filename, ip, client, sync;
  int port;
  ss >> prg >> ip >> port >> service >> filename >> client;
  ss >> sync;
  bool nsync = (sync == "-nsync");

  //
  // make connection
  //
  struct sockaddr_in server_addr;
  int sockfd = connect_to_server(ip.c_str(), port, server_addr);

  //
  // do business
  //
  std::stringstream ss_server_cmd;
  ss_server_cmd << service << ' ' << filename;
  std::string cmd = ss_server_cmd.str();
  std::string server_cmd = ss_server_cmd.str();
  extras::RequestedService serviceName = server_cmd;
  extras::Requests requests;
  extras::PortNumber port_to_use = requests.request(serviceName, sockfd);
  std::stringstream ss_client_cmd;
  ss_client_cmd << client << ' ' << filename << ' ' << ip << ' ' << port_to_use;
  if (!nsync) ss_client_cmd << " &";
  std::string client_cmd = ss_client_cmd.str();
  printf("[+]RequestedService '%s' Invoked on port: %i.\n", serviceName.c_str(),
         port_to_use);
  system(client_cmd.c_str());

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
