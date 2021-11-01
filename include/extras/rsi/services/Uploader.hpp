#ifndef _EXTRA_RSISERVICES_UPLOADER_HPP
#define _EXTRA_RSISERVICES_UPLOADER_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {
    /**
     * @brief UploaderInterface
     *
     *   build/rsi_client 127.0.0.1 8080 upload send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */

    using Parameter = std::string;
    using Parameters = std::deque<Parameter>;

    interface UploaderInterface {
      virtual Parameters parameters(int argc, char const* argv[]) pure;
      virtual const Parameter& program() const pure;
      virtual const Parameter& filename() const pure;
      virtual const Parameter& ip() const pure;
      virtual const Parameter& port() const pure;
      virtual void connect() pure;
      virtual int socket() const pure;
      virtual void upload() const pure;
      virtual void close() const pure;
    };

    /**
     * @brief abstract class Uploader
     *
     *   build/rsi_client 127.0.0.1 8080 upload send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    abstract class Uploader implements UploaderInterface {
     protected:
      Parameters _parameters;
      struct sockaddr_in _server_addr;
      int _sockfd;

     public:
      virtual Parameters parameters(int argc, char const* argv[]) override;
      virtual const Parameter& program() const override {
        return _parameters[0];
      };
      virtual const Parameter& filename() const override {
        return _parameters[1];
      };
      virtual const Parameter& ip() const override { return _parameters[2]; };
      virtual const Parameter& port() const override { return _parameters[3]; };
      virtual int socket() const override { return _sockfd; }
    };

    /**
     * @brief concrete class UploaderClient
     *
     *   build/rsi_client 127.0.0.1 8080 upload send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    concrete class UploaderClient extends Uploader {
     public:
      virtual void connect() override;
      virtual void upload() const override;
      virtual void close() const override;
    };

    concrete class DownloaderClient extends UploaderClient {
     public:
      virtual void upload() const override;
    };

    /**
     * @brief concrete class UploaderServer
     *
     *   build/rsi_client 127.0.0.1 8080 upload send.txt
     *   ss >> prg >> filename >> ip >> port;
     *
     */
    concrete class UploaderServer extends Uploader {
     protected:
      struct sockaddr_in _new_addr;
      int _new_sock;

     public:
      virtual void connect() override;
      virtual void upload() const override;
      virtual void close() const override;
    };

    concrete class DownloaderServer extends UploaderServer {
     public:
      virtual void upload() const override;
    };
  }  // namespace rsi

}  // namespace extras

#endif  // _EXTRA_RSISERVICES_UPLOADER_HPP
