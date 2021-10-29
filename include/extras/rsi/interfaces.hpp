#ifndef _EXTRA_RSIINTERFACES_HPP
#define _EXTRA_RSIINTERFACES_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <extras/sockets/Requests.hpp>
#include <extras/strings.hpp>
#include <iostream>
#include <sstream>

namespace extras {

  /**
   * @brief RSIInterface
   *
   * Remote Service Invocation (RSI) Interface
   *
   */

  using Filename = std::string;
  using IP = std::string;
  using Port = int;
  using Async = bool;
  using RSIClient = std::string;
  using RSIServer = std::string;

  interface RSIInterface {
    friend std::ostream& operator<<(std::ostream& out, const RSIInterface& obj);
    friend std::istream& operator>>(std::istream& in, RSIInterface& obj);

    virtual const RequestedService& service() const pure;
    virtual const Filename& filename() const pure;
    virtual const IP& ip() const pure;
    virtual const Port& port() const pure;
    virtual const Async& async() const pure;
    virtual RSIClient client() const pure;
    virtual RSIServer server() const pure;

    //
    // POJO
    //
    virtual void setService(const RequestedService& service) pure;
    virtual void setFilename(const Filename& filename) pure;
    virtual void setIP(const IP& ip) pure;
    virtual void setPort(const Port& port) pure;
    virtual void setAsync(const Async& async) pure;

    bool operator==(const RSIInterface& rhs) const {
      std::stringstream ssA;
      ssA << *this;
      std::string testA = ssA.str();
      std::stringstream ssB;
      ssB << rhs;
      std::string testB = ssB.str();
      return testB == testA;
    }

    bool operator!=(const RSIInterface& rhs) const { return !(*this == rhs); }
  };

  /**
   * @brief RSI class
   *
   * Used by the ChessMind project, it introduces an interface
   * to safely convert a number to and from octal format.
   *
   */

  abstract class RSI implements RSIInterface {
    Filename _filename;
    IP _ip;
    Port _port;
    Async _async;
    RequestedService _service;
    RSIClient _request;
    RSIServer _response;

   public:
    RSI(const Filename& filename, const IP& ip, Port port, Async async,
        RequestedService service, RSIClient request, RSIServer response)
        : _filename(filename),
          _ip(ip),
          _port(port),
          _async(async),
          _service(service),
          _request(request),
          _response(response) {}
    virtual const RequestedService& service() const override {
      return _service;
    };
    virtual const Filename& filename() const override { return _filename; };
    virtual const IP& ip() const override { return _ip; };
    virtual const Port& port() const override { return _port; };
    virtual const Async& async() const override { return _async; };

    virtual void setService(const RequestedService& service) override {
      _service = service;
    }
    virtual void setFilename(const Filename& filename) override {
      _filename = filename;
    }
    virtual void setIP(const IP& ip) override { _ip = ip; }
    virtual void setPort(const Port& port) override { _port = port; }
    virtual void setAsync(const Async& async) override { _async = async; }

    virtual RSIClient client() const override {
      std::stringstream ss;
      ss << *this;
      std::string cmd = extras::replace_all(ss.str(), service(), _request);
      return cmd;
    };
    virtual RSIServer server() const override {
      std::stringstream ss;
      ss << *this;
      std::string cmd = extras::replace_all(ss.str(), service(), _response);
      return cmd;
    };
  };

  /**
   * @brief Macro
   */

  concrete class RSIMacro extends RSI {
   public:
    RSIMacro()
        : RSI("", "", 0, true, "", "build/uploader_client",
              "build/uploader_server") {}
    RSIMacro(const Filename& filename, const IP& ip, Port port, Async async,
             RequestedService macro)
        : RSI(filename, ip, port, async, macro, "build/uploader_client",
              "build/uploader_server") {}
  };

  /**
   * @brief Upload
   */

  concrete class RSIUpload extends RSI {
   public:
    RSIUpload(const Filename& filename, const IP& ip, Port port, Async async)
        : RSI(filename, ip, port, async, "upload", "build/uploader_client",
              "build/uploader_server") {}
  };

}  // namespace extras

#endif  // _EXTRA_RSIINTERFACES_HPP
