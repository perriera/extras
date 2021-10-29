#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/subsystem.hpp>

void extras::rsi::send_file(FILE *fp, int sockfd) {
  // int n;
  char data[extras::rsi::SIZE] = {0};

  while (fgets(data, extras::rsi::SIZE, fp) != NULL) {
    int len = strlen(data);
    if (send(sockfd, data, len, 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, extras::rsi::SIZE);
  }
}