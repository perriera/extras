#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/subsystem/RSISubsystem.hpp>

void send_file(FILE *fp, int sockfd) {
  // int n;
  char data[SIZE] = {0};

  while (fgets(data, SIZE, fp) != NULL) {
    int len = strlen(data);
    if (send(sockfd, data, len, 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}