#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/services/Requests.hpp>
#include <extras/rsi/services/Uploader.hpp>
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
  void rsi::UploaderClient::connect() {
    this->_sockfd = extras::rsi::connect_to_server(ip().c_str(), stoi(port()),
                                                   _server_addr);
  }

  void rsi::UploaderClient::transfer() const {
    extras::rsi::send_file2(filename().c_str(), this->_sockfd);
  }

  void rsi::DownloaderClient::transfer() const {
    extras::rsi::write_file(filename().c_str(), this->_sockfd);
  }

  void rsi::UploaderClient::close() const { ::close(this->_sockfd); }

}  // namespace extras
