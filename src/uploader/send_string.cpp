#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>
#include <string>

void send_string(const std::string& msg, int sockfd) {
  if (send(sockfd, msg.c_str(), msg.length(), 0) == -1) {
    perror("[-]Error in sending string.");
    exit(1);
  }
}

void send_int(int msg, int sockfd) {
  std::string value = std::to_string(msg);
  return send_string(value, sockfd);
}
