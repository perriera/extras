#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/requests.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <extras/rsi/subsystem.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace extras {

  //
  // 'build/uploader_client send.txt 159.223.103.27 9010 &'
  //
  void rsi::Uploader::connect() {
    this->_sockfd = extras::rsi::connect_to_server(ip().c_str(), stoi(port()),
                                                   _server_addr);
  }
  rsi::Parameters rsi::Uploader::parameters(int argc, char const* argv[]) {
    if (argc < 4) {
      std::cout << "params: filename ip port" << std::endl;
      throw RSIException("params: filename ip port", __INFO__);
    }
    rsi::Parameters result;
    for (int i = 0; i < argc; i++) result.push_back(argv[i]);
    _parameters = result;
    return _parameters;
  }

  int rsi::Uploader::socket() const { return this->_sockfd; }
  void rsi::Uploader::send_file() const {
    FILE* fp = fopen(filename().c_str(), "r");
    if (fp == NULL) {
      perror("[-]Error in reading file.");
      exit(1);
    }
    extras::rsi::send_file(fp, this->_sockfd);
  }
  void rsi::Uploader::close() const { ::close(this->_sockfd); }

}  // namespace extras
