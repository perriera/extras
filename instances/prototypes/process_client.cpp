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
    extras::rsi::ProcessClient client;
    client.parameters(argc, argv);
    client.connect();
    client.process();
    printf("[+]File data sent successfully.\n");
    client.close();
    printf("[+]Closed the connection.\n");
    return 0;
  } catch (std::exception& ex) {
    printf("[-]%s.\n", ex.what());
    return -1;
  }
}
