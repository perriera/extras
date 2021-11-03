#ifndef _EXTRA_RSISOCKETPOOL_HPP
#define _EXTRA_RSISOCKETPOOL_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

namespace extras {
  namespace rsi {
    /**
     * @brief SocketPoolInterface
     *
     * The idea is that we assign a port to be the authority on deligating
     * available port numbers, (from a range of port numbers). At the basic
     * level a series of predefined tokens are given to this interface. If all
     * tokens are reconized then a port number is returned for each token.
     *
     * The purpose of a token is to inform the SocketPool instance what type of
     * socket service will be expected to be running on that port. Earlier
     * prototypes to this just returned a single port number. However, it was
     * soon realized that perhaps more than one port is required and to inform
     * the socket pool manager in advance of what type of service to running on
     * that port would be advantageous.
     *
     * This version only returns a port number, a more enhanced version would
     * support IP addresses, (hence supporting socket pools over different IPs).
     *
     */

    using Socket = int;
    using PortNumberPool = std::vector<PortNumber>;
    using SocketRequestType = std::string;
    using SocketRequestTypeList = std::vector<SocketRequestType>;
    using SocketRequestTypeMap = std::map<PortNumber, SocketRequestType>;

    interface SocketPoolInterface {
      virtual SocketRequestTypeList types() const pure;
      virtual PortNumberPool request(
          const PortNumber &portNumber,
          const SocketRequestTypeList &requests) pure;
      virtual SocketRequestTypeMap lastRequest() const pure;
      virtual SocketRequestTypeMap startServices(
          const SocketRequestTypeMap &map) const pure;
    };

    interface SocketPoolParametersInterface {
      virtual Parameters parameters(int argc, char const *argv[]) pure;
      virtual const Parameter &program() const pure;
      virtual const Parameter &ip() const pure;
      virtual const Parameter &port() const pure;
      virtual const Parameter &filename() const pure;
      virtual const SocketRequestTypeList &requests() const pure;
    };

    interface SocketPoolClientInterface {
      virtual void connect() pure;
      virtual void close() const pure;
    };

    interface SocketPoolServerInterface {
      virtual void connect() pure;
      virtual void accept() pure;
      virtual void close() const pure;
    };

    /**
     * @brief SocketPoolInterface
     *
     * The idea is that we assign a port to be the authority on deligating
     * available port numbers, (from a range of port numbers). At the basic
     * level a series of predefined tokens are given to this interface. If all
     * tokens are reconized then a port number is returned for each token.
     *
     * The purpose of a token is to inform the SocketPool instance what type of
     * socket service will be expected to be running on that port. Earlier
     * prototypes to this just returned a single port number. However, it was
     * soon realized that perhaps more than one port is required and to inform
     * the socket pool manager in advance of what type of service to running on
     * that port would be advantageous.
     *
     * This version only returns a port number, a more enhanced version would
     * support IP addresses, (hence supporting socket pools over different IPs).
     *
     */

    abstract class SocketPool implements SocketPoolInterface with
        SocketPoolParametersInterface {
     protected:
      Parameters _parameters;
      SocketRequestTypeList _requests;
      SocketRequestTypeList _types;
      SocketRequestTypeMap _lastRequest;

     public:
      virtual Parameters parameters(int argc, char const *argv[]) override;
      virtual const Parameter &program() const override {
        return _parameters[0];
      };
      virtual const Parameter &ip() const override { return _parameters[1]; };
      virtual const Parameter &port() const override { return _parameters[2]; };
      virtual const Parameter &filename() const override {
        return _parameters[4];
      };
      virtual const SocketRequestTypeList &requests() const override {
        return _requests;
      };
      virtual SocketRequestTypeList types() const override { return _types; };
      virtual SocketRequestTypeMap lastRequest() const override {
        return _lastRequest;
      };
    };

    concrete class SocketPoolClient extends SocketPool with
        SocketPoolClientInterface {
      struct sockaddr_in _server_addr;
      int _sockfd;

     public:
      virtual void connect() override;
      virtual void close() const override;
      virtual PortNumberPool request(
          const PortNumber &portNumber,
          const SocketRequestTypeList &requests) override;
      virtual SocketRequestTypeMap startServices(
          const SocketRequestTypeMap &map) const override;
    };

    concrete class SocketPoolServer extends SocketPool with
        SocketPoolServerInterface {
      struct sockaddr_in _server_addr;
      struct sockaddr_in _new_addr;
      int _sockfd;
      int _new_sock;

     public:
      virtual void connect() override;
      virtual void accept() override;
      virtual void close() const override;
      virtual PortNumberPool request(
          const PortNumber &portNumber,
          const SocketRequestTypeList &requests) override;
      virtual SocketRequestTypeMap startServices(
          const SocketRequestTypeMap &map) const override;
    };

    /**
     * @brief SocketException
     *
     * To be thrown if either string or value supplied is out of range.
     *
     */
    concrete class UnsupportedTokenException extends RSIException {
     public:
      UnsupportedTokenException(std::string msg, const WhereAmI &whereAmI)
          : RSIException(msg.c_str(), whereAmI) {}
      static void assertion(const std::string &msg, const WhereAmI &ref);
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSISOCKETPOOL_HPP
