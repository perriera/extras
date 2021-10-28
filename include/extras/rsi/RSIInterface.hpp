#ifndef _EXTRA_RSIINTERFACE_HPP
#define _EXTRA_RSIINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/Requests.hpp>
#include <iostream>
#include <sstream>

namespace extras {

  /**
   * @brief RSIInterface
   *
   * Remote Service Invocation (RSI) Interface
   *
   */

  using RSIRequest = std::string;
  using RSIResponse = std::string;

  interface RSIInterface {
    friend std::ostream& operator<<(std::ostream& out, const RSIInterface& obj);
    friend std::istream& operator>>(std::istream& in, RSIInterface& obj);

    virtual const RequestedService& service() const pure;
    virtual bool async() const pure;
    virtual const RSIRequest& request() const pure;
    virtual const RSIResponse& response() const pure;
  };

  /**
   * @brief RSI class
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  abstract class RSI implements RSIInterface {
    bool _async;
    RequestedService _service;
    RSIRequest _request;
    RSIResponse _response;

   public:
    RSI(bool async, RequestedService service, RSIRequest request,
        RSIResponse response)
        : _async(async),
          _service(service),
          _request(request),
          _response(response) {}
    virtual bool async() const override { return _async; };
    virtual const RequestedService& service() const override {
      return _service;
    };
    virtual const RSIRequest& request() const override { return _request; };
    virtual const RSIResponse& response() const override { return _response; };
  };

  /**
   * @brief Upload
   */
  using Filename = std::string;
  using IP = std::string;
  using Port = int;
  using Async = bool;

  concrete class RSIUpload extends RSI {
    Filename _filename;
    IP _ip;
    Port _port;

   public:
    RSIUpload(const Filename& filename, const IP& ip, Port port, Async async)
        : RSI(async, "upload", "uploader_client", "uploader_server"),
          _filename(filename),
          _ip(ip),
          _port(port) {}
  };

}  // namespace extras

#endif  // _EXTRA_RSIINTERFACE_HPP
