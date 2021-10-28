
#include <iostream>
#include <sstream>

#include "../vendor/catch.hpp"
#include "extras/rsi/RSIInterface.hpp"

using namespace extras;
using namespace std;

/**
 * @brief MockRSIServer
 * @note simulates a remote server
 */
static PortNumber sevicePort = 9000;
concrete class MockRSIServer implements RSIRequestInterface {
 public:
  virtual void request(RSIInterface& requestedService,
                       const PortServerNumber& serverSocket) override {
    /**
     * All it has to do is set the service port
     * (but could also set a service ip or other parameters)
     */
    requestedService.setPort(sevicePort);
  }
  virtual std::string send_line(const std::string& request,
                                int serverSocket) const override{};
  virtual std::string read_line(int serverSocket) override{};
};

/**
 * @brief MockRSIClient
 * @note simulates a local client
 */
static MockRSIServer mockRSIServer;
concrete class MockRSIClient implements RSIRequestInterface {
 public:
  virtual void request(RSIInterface& requestedService,
                       const PortServerNumber& serverSocket) override {
    /**
     * The actual implementation would use sockets, (or something the same)
     * to do the actual fetching of data from a remote server. This is one of
     * the benefits of programming to the interface. All we need at this stage
     * is determine the general shape of how the actual implementaiton should be
     * & we save ourselves a lot of time in on unnecessary boilerplate code.
     */
    return mockRSIServer.request(requestedService, serverSocket);
  }
  virtual std::string send_line(const std::string& request,
                                int serverSocket) const override{};
  virtual std::string read_line(int serverSocket) override{};
};

SCENARIO("Test RSIRequestInterface", "[RSIRequestInterface]") {
  PortServerNumber socketServerPort = 8080;
  RSIUpload rsi_upload("send.txt", "159.223.103.27", socketServerPort, true);
  MockRSIClient client;

  /**
   * It's a server pool, we know the port of the server port socket
   * so we ask that socket for a port that can be used for dedicted
   * task. Further, because we are using an interface, all the details
   * of the requestedService are inside the instance of that interface.
   */

  REQUIRE(rsi_upload.port() == socketServerPort);
  client.request(rsi_upload, 8080);
  REQUIRE(rsi_upload.port() == sevicePort);
}
