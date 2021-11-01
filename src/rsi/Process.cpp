#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/requests.hpp>
#include <extras/rsi/services/Process.hpp>
#include <extras/rsi/subsystem.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace extras {

  /**
   * @brief concrete class UploaderClient
   *
   *   build/rsi_client 127.0.0.1 8080 transfer send.txt
   *   ss >> prg >> filename >> ip >> port;
   *
   */

  void rsi::ProcessClient::transfer() const {
    FILE* fp = fopen(filename().c_str(), "r");
    if (fp == NULL) {
      throw RSIException("Error in reading file.", __INFO__);
    }
    extras::rsi::send_file(fp, this->_sockfd);
  }

  void rsi::ProcessServer::transfer() const {
    extras::rsi::write_file(filename().c_str(), this->_new_sock);
  }
}  // namespace extras
