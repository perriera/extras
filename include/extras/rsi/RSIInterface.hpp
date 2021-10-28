#ifndef _EXTRA_RSIINTERFACE_HPP
#define _EXTRA_RSIINTERFACE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/Requests.hpp>
#include <iostream>

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
  concrete class RSIUpload extends RSI {
   public:
    RSIUpload() : RSI(true, "upload", "uploader_client", "uploader_server") {}
  };

}  // namespace extras

#endif  // _EXTRA_RSIINTERFACE_HPP
