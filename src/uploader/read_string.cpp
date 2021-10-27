#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <string>

std::string read_string(int sockfd) {
  std::string result;
  char buffer[1024];
  int n;

  while (1) {
    n = recv(sockfd, buffer, 1024, 0);
    if (n <= 0) break;
    result += buffer;
    bzero(buffer, 1024);
  }
  return result;
}

int read_int(int sockfd) {
  std::string msg = read_string(sockfd);
  return std::stoi(msg);
}
