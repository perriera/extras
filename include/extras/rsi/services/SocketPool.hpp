#ifndef _EXTRA_RSISOCKETPOOL_HPP
#define _EXTRA_RSISOCKETPOOL_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/exceptions.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/Uploader.hpp>
#include <extras/sockets/PortAuthority.hpp>
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
      virtual void transfer() const pure;
    };

    interface SocketPoolParametersInterface {
      friend std::ostream &operator<<(std::ostream &out,
                                      const SocketPoolParametersInterface &obj);
      friend std::istream &operator>>(std::istream &in,
                                      SocketPoolParametersInterface &obj);
      virtual Parameters parameters(int argc, char const *argv[]) pure;
      virtual const Parameter &program() const pure;
      virtual const Parameter &ip() const pure;
      virtual const Parameter &port() const pure;
      virtual const Parameter &filename() const pure;
      virtual const SocketRequestTypeList &requests() const pure;

      virtual void setProgram(const Parameter &program) pure;
      virtual void setIP(const IP &ip) pure;
      virtual void setPort(const Port &port) pure;
      virtual void setFilename(const Filename &filename) pure;
      virtual void setRequests(const SocketRequestTypeList &list) pure;

      bool operator==(const SocketPoolParametersInterface &rhs) const {
        std::stringstream ssA;
        ssA << *this;
        std::string testA = ssA.str();
        std::stringstream ssB;
        ssB << rhs;
        std::string testB = ssB.str();
        return testB == testA;
      }

      bool operator!=(const SocketPoolParametersInterface &rhs) const {
        return !(*this == rhs);
      }
    };

    interface SocketPoolClientInterface {
      virtual void connect() pure;
      virtual void close() const pure;
    };

    interface SocketPoolServerInterface {
      virtual void connect() pure;
      virtual void accept() pure;
      virtual void close() const pure;
      virtual PortAuthority &portAuthority() pure;
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
      std::string _program;
      std::string _ip;
      std::string _port;
      std::string _filename;
      SocketRequestTypeList _requests;
      SocketRequestTypeList _types;
      SocketRequestTypeMap _lastRequest;

     public:
      virtual Parameters parameters(int argc, char const *argv[]) override;
      virtual const Parameter &program() const override { return _program; };
      virtual const Parameter &ip() const override { return _ip; };
      virtual const Parameter &port() const override { return _port; };
      virtual const Parameter &filename() const override { return _filename; };
      virtual const SocketRequestTypeList &requests() const override {
        return _requests;
      };
      virtual SocketRequestTypeList types() const override { return _types; };
      virtual SocketRequestTypeMap lastRequest() const override {
        return _lastRequest;
      };

      virtual void setProgram(const Parameter &program) override {
        _program = program;
      }
      virtual void setIP(const IP &ip) override { _ip = ip; }
      virtual void setPort(const Port &port) override {
        _port = std::to_string(port);
      }
      virtual void setFilename(const Filename &filename) override {
        _filename = filename;
      }
      virtual void setRequests(const SocketRequestTypeList &list) override {
        _requests = list;
      }
    };

    concrete class SocketPoolClient extends SocketPool with
        SocketPoolClientInterface {
      struct sockaddr_in _server_addr;
      int _sockfd;

     public:
      SocketPoolClient() {}
      SocketPoolClient(const std::string &msg) {
        std::stringstream ss;
        ss << msg;
        ss >> *this;
      }
      operator std::string() const {
        std::string msg;
        std::stringstream ss;
        ss << *this;
        std::getline(ss, msg);
        return msg;
      }
      virtual void connect() override;
      virtual void close() const override;
      virtual PortNumberPool request(
          const PortNumber &portNumber,
          const SocketRequestTypeList &requests) override;
      virtual PortNumberPool request();
      virtual SocketRequestTypeMap startServices(
          const SocketRequestTypeMap &map) const override;
      virtual void transfer() const override;
    };

    concrete class SocketPoolServer extends SocketPool with
        SocketPoolServerInterface {
      struct sockaddr_in _server_addr;
      struct sockaddr_in _new_addr;
      int _sockfd;
      int _new_sock;
      PortAuthority _PortAuthority;

     public:
      virtual void connect() override;
      virtual void accept() override;
      virtual void close() const override;
      virtual PortNumberPool request();
      virtual PortNumberPool request(
          const PortNumber &portNumber,
          const SocketRequestTypeList &requests) override;
      virtual SocketRequestTypeMap startServices(
          const SocketRequestTypeMap &map) const override;
      virtual void transfer() const override;
      virtual PortAuthority &portAuthority() override { return _PortAuthority; }
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
