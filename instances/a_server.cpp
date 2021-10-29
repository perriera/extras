#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define extras ::rsi::SIZE 1024 * 256

void write_file(int sockfd) {
  int n;
  FILE *fp;
  char *filename = "recv.txt";
  char buffer[extras::rsi::SIZE];

  fp = fopen(filename, "w");
  while (1) {
    n = recv(sockfd, buffer, extras::rsi::SIZE, 0);
    if (n <= 0) {
      break;
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, extras::rsi::SIZE);
  }
  return;
}

int main() {
  char *ip = "159.223.103.27";
  int port = 8080;
  int e;

  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  char buffer[extras::rsi::SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (e < 0) {
    perror("[-]Error in bind");
    exit(1);
  }
  printf("[+]Binding successfull.\n");

  if (listen(sockfd, 10) == 0) {
    printf("[+]Listening....\n");
  } else {
    perror("[-]Error in listening");
    exit(1);
  }

  addr_size = sizeof(new_addr);
  new_sock = accept(sockfd, (struct sockaddr *)&new_addr, &addr_size);
  write_file(new_sock);
  printf("[+]Data written in the file successfully.\n");

  return 0;
}
