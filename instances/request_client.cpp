#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/subsystem.hpp>
#include <extras/sockets/Requests.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[]) {
  //
  // collect parameters
  //
  if (argc < 6) {
    std::cout << "params: ip port service filename client [-async]"
              << std::endl;
    return -1;
  }
  std::stringstream ss;
  for (int i = 0; i < argc; i++) ss << argv[i] << ' ';
  std::string prg, service, filename, ip, client, sync;
  int port;
  ss >> prg >> ip >> port >> service >> filename >> client;
  ss >> sync;
  bool async = (sync == "-async");

  //
  // make connection
  //
  struct sockaddr_in server_addr;
  int sockfd = extras::rsi::connect_to_server(ip.c_str(), port, server_addr);

  //
  // form RSI macro
  //
  extras::RSIMacro macro(filename, ip, port, async, service);
  std::stringstream ss_macro;
  ss_macro << macro;
  std::string test = ss_macro.str();

  //
  // do business
  //
  std::stringstream ss_remote_cmd;
  ss_remote_cmd << service << ' ' << filename;
  // if (!async) ss_remote_cmd << "ip port &";
  std::string cmd = ss_remote_cmd.str();
  std::string remote_cmd = ss_remote_cmd.str();
  extras::RequestedService serviceName = remote_cmd;
  extras::Requests requests;
  extras::PortNumber port_to_use = requests.request(serviceName, sockfd);
  std::stringstream ss_local_cmd;
  ss_local_cmd << client << ' ' << filename << ' ' << ip << ' ' << port_to_use;
  if (!async) ss_local_cmd << " &";
  std::string local_cmd = ss_local_cmd.str();

  //
  // form RSI
  //
  extras::RSIUpload upload(filename, ip, port_to_use, async);
  std::string upload_request = upload.client();
  std::string upload_response = upload.server();

  printf("[+]ServerService Invoked '%s'\n", upload_response.c_str());
  printf("[+]ClientService Invoked '%s'\n", upload_request.c_str());
  system(local_cmd.c_str());

  //
  // close connection
  //
  printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
