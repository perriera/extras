#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/services/Uploader.hpp>
#include <extras/rsi/subsystem.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const* argv[]) {
  try {
    extras::rsi::UploaderServer uploader;
    uploader.parameters(argc, argv);
    uploader.connect();
    uploader.transfer();
    printf("[+]File data received successfully.\n");
    uploader.close();
    printf("[+]Closed the connection.\n");
    exit(0);
  } catch (std::exception& ex) {
    printf("[-]%s.\n", ex.what());
    exit(-1);
  }
}
