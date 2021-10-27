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
  std::stringstream ss_remote_cmd;
  ss_remote_cmd << service << ' ' << filename;
  if (!nsync) ss_remote_cmd << "ip port &";
  std::string cmd = ss_remote_cmd.str();
  std::string remote_cmd = ss_remote_cmd.str();
  extras::RequestedService serviceName = remote_cmd;
  extras::Requests requests;
  extras::PortNumber port_to_use = requests.request(serviceName, sockfd);
  std::stringstream ss_local_cmd;
  ss_local_cmd << client << ' ' << filename << ' ' << ip << ' ' << port_to_use;
  if (!nsync) ss_local_cmd << " &";
  std::string local_cmd = ss_local_cmd.str();
  printf("[+]ServerService Invoked '%s' on port: %i.\n", remote_cmd.c_str(),
         port_to_use);
  printf("[+]ClientService Invoked '%s' on port: %i.\n", local_cmd.c_str(),
         port_to_use);
  system(local_cmd.c_str());

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
