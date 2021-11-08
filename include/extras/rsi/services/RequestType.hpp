#ifndef _EXTRA_RSIREQUESTTYPE_HPP
#define _EXTRA_RSIREQUESTTYPE_HPP

#include <netinet/in.h>
#include <sys/socket.h>

#include <extras/keywords.hpp>
#include <extras/rsi/interfaces.hpp>
#include <extras/rsi/services/SocketPool.hpp>
#include <extras/sockets/PortAuthority.hpp>
#include <iostream>
#include <sstream>

namespace extras {
  namespace rsi {

    /**
     * @brief RequestTypeInterface
     *
     * All the types of services that can be run on a remote server.
     *
     */

    using RequestType = std::string;
    using RequestTypeList = std::vector<RequestType>;

    interface RequestTypeCompilationInterface {
      friend std::ostream &operator<<(
          std::ostream &out, const RequestTypeCompilationInterface &obj);
      friend std::istream &operator>>(std::istream &in,
                                      RequestTypeCompilationInterface &obj);
      virtual void setCompilation(const RequestTypeList &list) pure;
      virtual RequestTypeList compilation() const pure;
      virtual void writeSocket(int socket) const pure;
      virtual void readSocket(int socket) pure;
      bool operator==(const RequestTypeCompilationInterface &rhs) const {
        return compilation() == rhs.compilation();
      }

      bool operator!=(const RequestTypeCompilationInterface &rhs) const {
        return !(*this == rhs);
      }
    };

    concrete class RequestTypeCompilation implements
        RequestTypeCompilationInterface {
      RequestTypeList _requestTypeList;

     public:
      RequestTypeCompilation(const RequestTypeList requestTypeList)
          : _requestTypeList(requestTypeList) {}
      RequestTypeCompilation(const std::string &rawString) {
        std::stringstream ss;
        ss << rawString;
      }
      RequestTypeCompilation() {}
      virtual void setCompilation(const RequestTypeList &list) override {
        _requestTypeList = list;
      };
      virtual RequestTypeList compilation() const override {
        return _requestTypeList;
      };
      virtual void writeSocket(int socket) const override;
      virtual void readSocket(int socket) override;
      operator std::string() {
        std::stringstream ss;
        ss << *this;
        return ss.str();
      }
    };

    interface RequestTypeCompilerInterface {
      virtual RequestTypeCompilation compile(
          const SocketPoolParametersInterface &client,
          PortAuthorityInterface &portAuthority) const pure;
    };

    concrete class RequestTypeCompiler implements RequestTypeCompilerInterface {
     public:
      virtual RequestTypeCompilation compile(
          const SocketPoolParametersInterface &client,
          PortAuthorityInterface &portAuthority) const override;
      virtual RequestTypeCompilation compile(
          const SocketPoolParametersInterface &client) const {
        return compile(client, PortAuthority::instance());
      }
    };

  }  // namespace rsi
}  // namespace extras

#endif  // _EXTRA_RSIREQUESTTYPE_HPP
