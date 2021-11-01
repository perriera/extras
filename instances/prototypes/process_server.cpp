#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/services/Process.hpp>
#include <extras/rsi/subsystem.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const* argv[]) {
  try {
    extras::rsi::ProcessServer server;
    server.parameters(argc, argv);
    server.connect();
    server.process();
    printf("[+]File data received successfully.\n");
    server.close();
    printf("[+]Closed the connection.\n");
    return 0;
  } catch (std::exception& ex) {
    printf("[-]%s.\n", ex.what());
    return -1;
  }
}
