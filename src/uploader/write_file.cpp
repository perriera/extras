#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/uploader/UploaderInterface.hpp>

void write_file(const char* filename, int sockfd) {
  int n;
  FILE* fp;
  char buffer[SIZE];

  fp = fopen(filename, "w");
  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0) break;
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}