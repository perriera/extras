// #include <arpa/inet.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// #include <extras/rsi/exceptions.hpp>
// #include <extras/rsi/services/Requests.hpp>
// #include <extras/rsi/services/Uploader.hpp>
// #include <extras/rsi/subsystem.hpp>
// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>

// using namespace std;

// namespace extras {

//   /**
//    * @brief abstract class Uploader
//    *
//    *   build/rsi_client 127.0.0.1 8080 transfer send.txt
//    *   ss >> prg >> filename >> ip >> port;
//    *
//    */
//   rsi::Parameters rsi::Uploader::parameters(int argc, char const* argv[]) {
//     if (argc < 4) {
//       std::cout << "params: filename ip port" << std::endl;
//       throw RSIException("params: filename ip port", __INFO__);
//     }
//     rsi::Parameters result;
//     for (int i = 0; i < argc; i++) result.push_back(argv[i]);
//     _parameters = result;
//     return _parameters;
//   }

//   /**
//    * @brief concrete class UploaderClient
//    *
//    *   build/rsi_client 127.0.0.1 8080 transfer send.txt
//    *   ss >> prg >> filename >> ip >> port;
//    *
//    */
//   void rsi::UploaderClient::connect() {
//     this->_sockfd = extras::rsi::connect_to_server(ip().c_str(),
//     stoi(port()),
//                                                    _server_addr);
//   }

//   void rsi::UploaderClient::transfer() const {
//     extras::rsi::send_file2(filename().c_str(), this->_sockfd);
//   }

//   void rsi::DownloaderClient::transfer() const {
//     extras::rsi::write_file(filename().c_str(), this->_sockfd);
//   }

//   void rsi::UploaderClient::close() const { ::close(this->_sockfd); }

//   /**
//    * @brief concrete class UploaderServer
//    *
//    *   build/rsi_client 127.0.0.1 8080 transfer send.txt
//    *   ss >> prg >> filename >> ip >> port;
//    *
//    */
//   void rsi::UploaderServer::connect() {
//     this->_sockfd = extras::rsi::configure_serversocket(
//         ip().c_str(), stoi(port()), _server_addr);
//     socklen_t addr_size = sizeof(_new_addr);
//     this->_new_sock =
//         accept(this->_sockfd, (struct sockaddr*)&_new_addr, &addr_size);
//     if (_new_sock == -1) {
//       ::close(this->_sockfd);
//       throw RSIException("Timeout on uploader_server accept", __INFO__);
//     }
//   }

//   void rsi::UploaderServer::transfer() const {
//     extras::rsi::write_file(filename().c_str(), this->_new_sock);
//   }

//   void rsi::DownloaderServer::transfer() const {
//     extras::rsi::send_file2(filename().c_str(), this->_new_sock);
//   }

//   void rsi::UploaderServer::close() const {
//     ::close(this->_new_sock);
//     ::close(this->_sockfd);
//   }

// }  // namespace extras
