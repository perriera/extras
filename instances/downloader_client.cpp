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
    extras::rsi::DownloaderClient downloader;
    downloader.parameters(argc, argv);
    downloader.connect();
    downloader.transfer();
    printf("[+]File data sent successfully.\n");
    downloader.close();
    printf("[+]Closed the connection.\n");
    return 0;
  } catch (std::exception& ex) {
    printf("[-]%s.\n", ex.what());
    return -1;
  }
}
